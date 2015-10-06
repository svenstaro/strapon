#ifndef SDL_HELPER_HPP
#define SDL_HELPER_HPP

#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include "resource_manager.hpp"

/**
 * Draws [text] to 
 */

static void draw_text(SDL_Renderer renderer, ResourceManager resource_manager, std::string text,std::string font_key SDL_Rect &rect, SDL_Color color)
{
    SDL_Surface *text_surface = TFF_RenderText_Blended(resource_manager.get(font_key), text.c_str(), color);
    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    SDL_RenderCopy(renderer, text_texture, nullptr, rect);
    SDL_FreeSurface(text_surface);
    SDL_DestroyTexture(text_texture);
}

#endif
