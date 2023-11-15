# ores

This project uses the [SDL library](http://www.libsdl.org/)

Here's instructions to compile and run using Visual Studio 2019:

1. Download the SDL release zip file for VC, e. g. [SDL2-devel-2.28.5-VC.zip](https://github.com/libsdl-org/SDL/releases/download/release-2.28.5/SDL2-devel-2.28.5-VC.zip)
2. Extract the zip file to any location of your choice
3. Open the project in VS
4. For the desired platform:
    1. Add the include directory from the SDL folder to Configuration Properties -> VC++ Directories -> Include Directories
    2. Add the library directory of the respective platform from the SDL folder to Configuration Properties -> VC++ Directories -> Library Directories
    3. Add the SDL2.lib SDL2main.lib files to Configuration Properties -> Linker -> Additional Dependencies (Add a semicolon ; after each file)
    4. Add a script that copies the library DLL to the compilation output directory, e. g.  in Configuration Properties -> Build Events -> Post-Build Event add `XCOPY SDL_DIRECTORY\lib\PLATFORM\SDL2.dll "$(TargetDir)" /D /K /Y` (replace `SDL_DIRECTORY` with the path to the SDL library folder and `PLATFORM` with the respective platform)
    5. Alternatively, you can add the DLL folder to the PATH environment variable
5. Repeat the configuration steps for SDL2_image and SDL2_ttf, [SDL2_image-devel-2.6.3-VC.zip](https://github.com/libsdl-org/SDL_image/releases/download/release-2.6.3/SDL2_image-devel-2.6.3-VC.zip) [SDL2_ttf-devel-2.20.2-VC.zip](https://github.com/libsdl-org/SDL_ttf/releases/download/release-2.20.2/SDL2_ttf-devel-2.20.2-VC.zip)

This configuration was based in the following resources:
* [Lazy Foo tutorial](https://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/msvc2019/index.php)
* [This Stack Overflow reply](https://stackoverflow.com/a/20410798)
