# K&R C

Exercises and examples from
[_The C Programming Language_](https://en.wikipedia.org/wiki/The_C_Programming_Language)
by Kernighan and Ritchie.

### Dependencies

##### All systems

- [`scons`](http://www.scons.org)

##### OS X

- [Xcode command line tools](https://developer.apple.com/downloads/)

##### Linux

- `gcc`
- [`libbsd`](http://libbsd.freedesktop.org/wiki/)

##### Windows

- [Microsoft Visual Studio](https://www.visualstudio.com/en-us/downloads/download-visual-studio-vs.aspx)

### Building

From the top-level directory, run `scons`.

This will create the directory `build` if it doesn't exist, then build all the
object files and executables and place them there.
