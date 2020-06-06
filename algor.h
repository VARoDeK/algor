#include <limits.h>
#include <stdint.h>

/* ========================================================================= */

#ifndef __ALGOR_H__
#define __ALGOR_H__ /* algor.h */

/* ====================== All Declarations Below This ====================== */

    /* ---- Configuration --------------------------------------------------
     *
     * fgets(char*, size_t, stream), reads size_t-1 no of characters from
     * stream or until newline character is found.
     */
    struct algor_config_t {
        char cwd[PATH_MAX];      /* Current Working Directory */
        char questwd[PATH_MAX];  /* Question Working Directory */
        char testwd[PATH_MAX];   /* Test Working Directory */
        char compwd[PATH_MAX];   /* Compiled Working Directory */
        uint8_t flags:6;
    };
    extern struct algor_config_t algor_config;

/* ===================== No Declarations Beyond This ======================= */

#endif /* algor.h */

/* ========================================================================= */
