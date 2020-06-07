/* Standard Headers */
#include <argp.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Local Headers */
#include "algor.h"
#include "dformat.h"
#include "functions.h"

/* ============================= ALGOR CONFIG ============================== */

struct algor_config_t algor_config = {
    .cwd = "-",
    .questwd = "-",
    .testwd = "-",
    .compwd = "-",
    .opt = 0x0
};

/* =========================== ALGOR ARGUMENTS ============================= */

struct algor_arguments_t algor_arguments = {
    .quest_file = "-",
    .test_file  = "-",
    .lang = "-",
    .flag = "-"
};

/* ============================= ALGOR OPTIONS ============================= */

#define OPT_DOC "Documentation.\n"
#define OPT_FLAG "Programs sometimes requires additional flags, either during"\
                 "run-time or compile-time. For example, C/C++ programs may"\
                 "require flags like \"-lm\", \"-lpthread\", \"-lncurses\", "\
                 "etc. during compile-time. Python may require \"-c\", \"-q\""\
                 ", etc. during runtime. They should be written inside double"\
                 " quotes.\n"

#define OPT_LANG "Specify the language of your program. LANG=\n"\
                 "[C, C++, C++11, C++17, JAVA, Python2, Python3,\n"\
                 "Rust, Javascript, etc].\n"

#define OPT_QUEST "Used with \"--test\" for evaluation. Specify file-name or "\
                  "full-path to the question file.\n"

#define OPT_SHOW "Prints question. Specify file-name or full-path to the "\
                 "question file.\n"

#define OPT_TEST "Program/Solution File. Specify file-name or full-path to the"\
                 "test/solution file.\n"

#define OPT_WRITE "Write a new question. Specify file-name or full-path of the"\
                  "Question-file, to be made.\n"

static const struct argp_option algor_options[] = {
    {"doc",   'd',           0,                   0, OPT_DOC},
    {"flag",  'f',      "FLAG",                   0, OPT_FLAG},
    {"lang",  'l',      "LANG",                   0, OPT_LANG},
    {"quest", 'q', "FILE/PATH", OPTION_ARG_OPTIONAL, OPT_QUEST},
    {"show",  's', "FILE/PATH", OPTION_ARG_OPTIONAL, OPT_SHOW},
    {"test",  't', "FILE/PATH",                   0, OPT_TEST},
    {"write", 'w', "FILE/PATH", OPTION_ARG_OPTIONAL, OPT_WRITE},
    { 0 }
};

#undef OPT_DOC
#undef OPT_FLAG
#undef OPT_LANG
#undef OPT_QUEST
#undef OPT_SHOW
#undef OPT_TEST
#undef OPT_WRITE

/* =========================== ARGP DEFINITIONS ============================ */

const char *argp_program_version = "AlgoR - Offline Judge : 0.0.1";
static const char usage_doc[] = "\nAlgoR - Offline Judge";

/* ============================== ARGP PARSER ============================== */

static error_t
parse_opt (int key, char *arg, struct argp_state *state){
    /* Get the input argument from argp_parse, which we
       know is a pointer to our arguments structure.*/

    extern struct algor_config_t algor_config;
    struct algor_arguments_t *arguments = state->input;
    uint32_t i;

    switch(key){
        case 'd':
            system("less documentation");
            break;

        case 'f':
            arguments->flag = arg;
            algor_config.opt |= 0x10;
            break;

        case 'l':
            for(i=0; arg[i] != '\0'; i++)
                arg[i] = tolower(arg[i]);
            arguments->lang = arg;
            algor_config.opt |= 0x4;
            break;

        case 'q':
            if(arg && arguments->quest_file[0] == '-')
                arguments->quest_file = arg;
            algor_config.opt |= 0x8;
            break;

        case 's':
            if(arg && arguments->quest_file[0] == '-')
                arguments->quest_file = arg;
            algor_config.opt |= 0x1;
            break;

        case 't':
            arguments->test_file = arg;
            algor_config.opt |= 0x2;
            break;

        case 'w':
            if(arg)
                arguments->quest_file = arg;
            algor_config.opt |= 0x20;
            break;

        default:
            return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

/* ========================================================================= */

static struct argp algor_argp = { algor_options, parse_opt, 0, usage_doc };

/* ========================================================================= */

int main (int argc, char *argv[]){
    extern struct algor_arguments_t algor_arguments;

    if(argc == 1){
        fprintf(stderr, "algor: Too few arguments"
                        "\n%s\n"
                        "\nTry `algor --help` or `algor --usage` for more "
                        "information.\n", usage_doc);
        return 1;
    }

    /* Parse the commandline arguments. */
    argp_parse(&algor_argp, argc, argv, ARGP_NO_ARGS, 0, &algor_arguments);

    print("%s", "");

    print("%s\n%s\n%s\n%s\n%u", algor_arguments.quest_file,
                              algor_arguments.test_file,
                              algor_arguments.lang,
                              algor_arguments.flag,
                              algor_config.opt);



    return 0;
}

/* ========================================================================= */
