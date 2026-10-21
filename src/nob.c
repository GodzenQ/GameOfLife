#define NOB_IMPLEMENTATION
#include "nob.h"

#define BUILD_FOLDER "build/"
#define SRC_FOLDER   "src/"

int main(int argc, char **argv)
{
    if (!nob_mkdir_if_not_exists(BUILD_FOLDER)) return 1;
    NOB_GO_REBUILD_URSELF(argc, argv);
    Nob_Cmd cmd = {0};
    nob_cmd_append(&cmd, "clang", "-Wall", "-Wextra", "-ggdb", "-o", BUILD_FOLDER"main", SRC_FOLDER"main.c");
    nob_cmd_append(&cmd, "-fsanitize=address");
    nob_cmd_append(&cmd, "-I./raylib/include/");
    // For clang
    // nob_cmd_append(&cmd, "-Wl,-rpath,./raylib/lib/", "-L./raylib/lib/", "-lraylib");
    nob_cmd_append(&cmd, "-Wl,-rpath=./raylib/lib/", "-L./raylib/lib/", "-lraylib");
    if (!nob_cmd_run(&cmd)) return 1;
    return 0;
}
