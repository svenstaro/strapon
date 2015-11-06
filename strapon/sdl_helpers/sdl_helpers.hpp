#ifndef SDL_HELPER_HPP
#define SDL_HELPER_HPP

#include "strapon/resource_manager/resource_manager.hpp"

#include <SDL.h>
#include <SDL_ttf.h>

/**
 * Draws [text] to
 */

static void draw_text(SDL_Renderer *renderer, ResourceManager resource_manager, std::string text,
                      std::string font_key, SDL_Rect *rect, SDL_Color color) {
    SDL_Surface *text_surface =
        TTF_RenderText_Blended(resource_manager.font(font_key), text.c_str(), color);
    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    SDL_RenderCopy(renderer, text_texture, nullptr, rect);
    SDL_FreeSurface(text_surface);
    SDL_DestroyTexture(text_texture);
}

static void draw_text(SDL_Renderer *renderer, ResourceManager resource_manager, std::string text,
                      std::string font_key, int x_pos, int y_pos, SDL_Color color) {
    SDL_Surface *text_surface =
        TTF_RenderText_Blended(resource_manager.font(font_key), text.c_str(), color);
    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    int w, h;
    SDL_QueryTexture(text_texture, nullptr, nullptr, &w, &h);
    SDL_Rect rect{x_pos, y_pos, w, h};
    SDL_RenderCopy(renderer, text_texture, nullptr, &rect);
    SDL_FreeSurface(text_surface);
    SDL_DestroyTexture(text_texture);
}

#endif
