#define NOB_IMPLEMENTATION
#include "nob.h"

int main(int argc, char **argv)
{
    NOB_GO_REBUILD_URSELF(argc, argv);
    Nob_Cmd cmd = {0};
    nob_cmd_append(&cmd, "clang", "-Wall", "-Wextra", "-ggdb", "-o", "main", "main.c");
    nob_cmd_append(&cmd, "-I./raylib/include/");
    // For clang
    // nob_cmd_append(&cmd, "-Wl,-rpath,./raylib/lib/", "-L./raylib/lib/", "-lraylib");
    nob_cmd_append(&cmd, "-Wl,-rpath=./raylib/lib/", "-L./raylib/lib/", "-lraylib");
    if (!nob_cmd_run(&cmd)) return 1;
    return 0;
}
