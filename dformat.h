/* ========================= DISPLAY FORMAT =============================== */

#ifndef __DFORMAT_H__
#define __DFORMAT_H__ /* dformat_h */

/* ====================== All Declarations Below This ====================== */

#define NORMAL_FORMAT "\e[0m"
#define HIGHLIGHT_FORMAT "\e[7m"
#define BOLD_FORMAT "\e[1m"

/* ---- Print Bold --------------------------------------------------------- */
#define printB(x, ...) fprintf(stdout,\
                               BOLD_FORMAT x "\n" NORMAL_FORMAT,\
                               __VA_ARGS__)

/* ---- Print Highlight ---------------------------------------------------- */
#define printH(x, ...) fprintf(stdout,\
                               HIGHLIGHT_FORMAT x "\n" NORMAL_FORMAT,\
                               __VA_ARGS__)

/* ---- Print Highlight and Bold ------------------------------------------- */
#define printBH(x, ...) fprintf(stdout,\
                                HIGHLIGHT_FORMAT BOLD_FORMAT \
                                x "\n" NORMAL_FORMAT,\
                                __VA_ARGS__)

/* ---- Print With Newline at End ------------------------------------------ */
#define print(x, ...) fprintf(stdout, x "\n", __VA_ARGS__)

/* ---- Input Bold --------------------------------------------------------- */
#define fgetsB(...) {\
                       printf(BOLD_FORMAT);\
                       fgets_imp(__VA_ARGS__);\
                       printf(NORMAL_FORMAT);\
                    }

/* ---- Input HIGHLIGHT ---------------------------------------------------- */
#define fgetsH(...) {\
                       printf(HIGHLIGHT_FORMAT);\
                       fgets_imp(__VA_ARGS__);\
                       printf(NORMAL_FORMAT);\
                    }

/* ---- Input Bold and Highlight ------------------------------------------- */
#define fgetsBH(...) {\
                        printf(BOLD_FORMAT HIGHLIGHT_FORMAT);\
                        fgets_imp(__VA_ARGS__);\
                        printf(NORMAL_FORMAT);\
                     }

#define line() prints("---------------------------------------------------"\
"----------------------------")

#define print_error(x, ...) {\
                               line();\
                               fprintf(stderr, "ERROR: " x "\n", __VA_ARGS__);\
                               fprintf(stderr, "Line: %d\n", __LINE__);\
                               fprintf(stderr, "Function: %s\n", __func__);\
                               fprintf(stderr, "File: %s\n", __FILE__);\
                               line();\
                            }



/* ====================== No Declarations Beyond This ======================= */

#endif /* dformat_h */

/* ========================================================================= */
