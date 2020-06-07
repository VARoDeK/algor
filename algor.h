#include <limits.h>
#include <stdint.h>

/* ========================================================================= */

#ifndef __ALGOR_H__
#define __ALGOR_H__ /* algor.h */

/* ====================== All Declarations Below This ====================== */

/* ============================ CONFIGURATION ============================== */
    /*
     * Structure to contain user configuration.
     *
     * We use "opt" as a set of bit flags to know which all options were
     * passed in terminal with algor. The values of those options get stored
     * in the object "algor_config" of structure "struct algor_config_t".
     * 
     * Value of opt when bitwised &ed with 0x1, 0x2, 0x4, 0x8, 0x10, 0x20:
     * - 1  = (0x1)  = show
     * - 2  = (0x2)  = test
     * - 4  = (0x4)  = lang
     * - 8  = (0x8)  = quest
     * - 16 = (0x10) = flag
     * - 32 = (0x20) = write
     */
    struct algor_config_t {
        char cwd[PATH_MAX];      /* Current Working Directory */
        char questwd[PATH_MAX];  /* Question Working Directory */
        char testwd[PATH_MAX];   /* Test Working Directory */
        char compwd[PATH_MAX];   /* Compiled Working Directory */
        uint8_t opt:6;
    };
    extern struct algor_config_t algor_config;

/* ============================== Arguments =================================*/

    /*
     * Used by main to communicate with parse_opt.
     * The values passed with options, on terminal, are stored in these. 
     */
    struct algor_arguments_t {
        char *quest_file; /* Pointer to value passed with '-q' or '-s' or
                             '--quest' -r '--show'*/
        char *test_file;  /* Pointer to value passed with '-t' or '--test' */
        char *lang;       /* Pointer to value passed with '-l' or '--lang' */
        char *flag;       /* Pointer to value passed with '-f' or '--flag' */
    };
    extern struct algor_arguments_t algor_arguments;


/* ===================== No Declarations Beyond This ======================= */

#endif /* algor.h */

/* ========================================================================= */
