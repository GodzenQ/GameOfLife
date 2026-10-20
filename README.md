# Game Of Life
### 19.10.26
- [nob basic example](https://github.com/tsoding/nob.h/blob/main/how_to/001_basic_usage/nob.c)
- [Cellular Automatoa](https://en.wikipedia.org/wiki/Cellular_automaton)
- [Raylib Examples](https://www.raylib.com/examples.html)

* Basic Linking and rpath is working. 

***What needs to be done on 20.10.26 ?***

+  The colors and the functions of raylib are not working from wsl maybe.

            The problem was EndDrawing() was not added.

+ Analyze the ldd of main from wsl.

            All the non-standard ones are just X11-display things.
