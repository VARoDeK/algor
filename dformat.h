/* ========================== DISPLAY FORMAT =============================== */

#ifndef __DFORMAT_H__
#define __DFORMAT_H__ /* dformat.h */

/* ====================== All Declarations Below This ====================== */

    #define NORMAL_FORMAT "\e[0m"
    #define HIGHLIGHT_FORMAT "\e[7m"
    #define BOLD_FORMAT "\e[1m"

    /* ---- Print Bold ----------------------------------------------------- */
    #define printB(x, ...) fprintf(stdout,\
                                   BOLD_FORMAT x NORMAL_FORMAT "\n",\
                                   __VA_ARGS__)

    /* ---- Print Highlight ------------------------------------------------ */
    #define printH(x, ...) fprintf(stdout,\
                                   HIGHLIGHT_FORMAT x NORMAL_FORMAT "\n",\
                                   __VA_ARGS__)

    /* ---- Print Highlight and Bold --------------------------------------- */
    #define printBH(x, ...) fprintf(stdout,\
                                    HIGHLIGHT_FORMAT BOLD_FORMAT \
                                    x NORMAL_FORMAT "\n",\
                                    __VA_ARGS__)

    /* ---- Print With Newline at End -------------------------------------- */
    #define print(x, ...) fprintf(stdout, x "\n", __VA_ARGS__)

    /* ---- Input Bold ----------------------------------------------------- */
    #define getsB(x, y) {\
                           printf(BOLD_FORMAT);\
                           fgets_imp(x, y, stdin);\
                           printf(NORMAL_FORMAT);\
                        }

    /* ---- Input HIGHLIGHT ------------------------------------------------ */
    #define getsH(x, y) {\
                           printf(HIGHLIGHT_FORMAT);\
                           fgets_imp(x, y, stdin);\
                           printf(NORMAL_FORMAT);\
                        }

    /* ---- Input Bold and Highlight --------------------------------------- */
    #define getsBH(x, y) {\
                            printf(BOLD_FORMAT HIGHLIGHT_FORMAT);\
                            fgets_imp(x, y, stdin);\
                            printf(NORMAL_FORMAT);\
                         }

    #define line() print("%s", "---------------------------------------------"\
    "----------------------------------")

    #define print_error(x, ...) {\
                                   line();\
                                   fprintf(stderr, BOLD_FORMAT\
                                                   "ERROR: "\
                                                   NORMAL_FORMAT\
                                                   x "\n", __VA_ARGS__);\
                                   fprintf(stderr, BOLD_FORMAT\
                                                   "Line: "\
                                                   NORMAL_FORMAT\
                                                   "%d\n", __LINE__);\
                                   fprintf(stderr, BOLD_FORMAT\
                                                   "Function: "\
                                                   NORMAL_FORMAT\
                                                   "%s\n", __func__);\
                                   fprintf(stderr, BOLD_FORMAT\
                                                   "File: "\
                                                   NORMAL_FORMAT\
                                                   "%s\n", __FILE__);\
                                   line();\
                                }



/* ===================== No Declarations Beyond This ======================= */

#endif /* dformat.h */

/* ========================================================================= */
