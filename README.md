# AnguishGL

## About

AnguishGL is a simplistic graphics library (and in the near future gaming library?)
aimed at a concept of "just enough abstraction".

This means that AnguishGL is centered at users that can understand how OpenGL works
and can extend the base classes to build awesome applications.

## How to build

Requirements to build the library, sandbox and tools projects is as follows:

* GCC 13.1.0 or Clang 16
* CMake 3.26
* OpenGL 4.6
* OpenAL 1.1
* GLM 0.9.9.8
* GLFW 3.3.8
* LZ4 1.9.4
* xxHash 0.8.1
* Opus 1.4
* Opusfile 0.12

I recommend building this under Arch Linux or on windows with MSYS2 (UCRT64), reason
being that Ubuntu/Debian based distros are pretty trash and don't have these packages
in the required versions.

It may be able to compile under Fedora and similar systems aimed at developers.

## License

None for now. But probably GPLv3.