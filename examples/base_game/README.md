# base_game
Generic SDL2-based template game using entityx and glm.

## Requirements

* sdl2
* sdl2_gfx
* sdl2_image
* sdl2_mixer
* sdl2_ttf
* cmake
* git
* emscripten (optionally)
* python (optionally)
* clang (optionally)

## Instructions

0. Make your own git repo
1. Copy the contents of the `base_game` directory into your repo
2. Navigate into your repo
3. `git submodule add git@github.com:svenstaro/strapon.git strapon`
4. `git submodule add git@github.com:alecthomas/entityx.git entityx`
5. `git submodule add git@github.com:g-truc/glm.git glm`
6. Type `make`
