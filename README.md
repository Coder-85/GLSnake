# GLSnake
GLSnake is a classic snake game made using OpenGL.

## Controls
WASD or Arrow Keys: Move

P: Pause

## Build From Source

1. Clone this repository or download zip.
2. Download [GLUT](https://www.opengl.org/resources/libraries/glut/glut_downloads.php)
3. Copy the libraries to `{root folder}/lib` where {root folder} is the root folder of the project. You can always tweak the paths in the `CMakeLists.txt` file.
4. Copy the header files to `{root folder}/include/GL` where {root folder} is the root folder of the project.
5. Build with cmake.
```
$ cmake -B build -S . -G "<Generator Name>"
$ cmake --build build --target GLSnake
```
5. Now you can run the game!

## Precompiled Binaries
Precompiled binaries for windows(x86) can be found in the Releases page.