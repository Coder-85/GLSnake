# GLSnake
GLSnake is a classic snake game made using OpenGL.

## Controls
WASD or Arrow Keys: Move

P: Pause

## Build From Source

1. Clone this repository or download zip.
2. Download and build [FREEGLUT](https://sourceforge.net/projects/freeglut/)
3. Copy the libraries to `{root folder}/lib` where {root folder} is the root folder of the project. You can always tweak the paths in the `CMakeLists.txt` file.
4. Copy the header files to `{root folder}/include/GL` where {root folder} is the root folder of the project.
5. Build with cmake.
```
$ cmake -B build -S . -G "<Generator Name>"
$ cmake --build build --target GLSnake
```
5. Now you can run the game!

N.B: There might be some issues while building using Visual Studio build tools(only in Release mode). However I was successful in building using nmake.
So, I recommend you to use nmake if you are using Visual Studio.

## Precompiled Binaries
Precompiled binaries for windows(x64) can be found in the Releases page.