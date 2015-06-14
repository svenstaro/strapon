#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include <map>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#ifdef __EMSCRIPTEN__
#include <SDL/SDL_mixer.h>
#else
#include <SDL2/SDL_mixer.h>
#endif

class ResourceManager {
public: 
    /***/
    void shutdown() {
        for(auto e : m_textures) {
            SDL_DestroyTexture(e.second);
        }

        for(auto e : m_sounds) {
            Mix_FreeChunk(e.second);
        }

        for(auto e : m_music) {
            Mix_FreeMusic(e.second);
        }

        for(auto e : m_fonts) {
            TTF_CloseFont(e.second);
        }
    }

    /***/
    bool load_texture(const std::string &key,
                      const std::string &path,
                      SDL_Renderer *ren) {
        SDL_Texture *texture;
        texture = IMG_LoadTexture(ren, path.c_str());

        if (!texture) {
            std::cerr << "IMG_Load:" << IMG_GetError() << std::endl;
            return false;
        }

        m_textures[key] = texture;
        return true;
    }

    /***/
    bool load_sound(const std::string &key, const std::string &path) {
        Mix_Chunk *new_sound = Mix_LoadWAV(path.c_str());

        if (new_sound == NULL) {
            std::cerr << "Error: could not load sound from" << path << std::endl;
            return false;
        }

        m_sounds[key] = new_sound;
        return true;
    }

    /***/
    bool load_music(const std::string &key, const std::string &path) {
        Mix_Music *new_music = Mix_LoadMUS(path.c_str());

        if (new_music == NULL) {
            std::cerr << "Error: could not load music from " << path << ": "<< Mix_GetError() << std::endl;
            return false;
        }

        m_music[key] = new_music;
        return true;
    }

    /***/
    bool load_font(const std::string &key, const std::string &path, int size) {
        TTF_Font *new_font = TTF_OpenFont(path.c_str(), size);

        if (new_font == NULL) {
            std::cerr << "Error: could not load font from " << path << ": "<< TTF_GetError() << std::endl;
            return false;
        }

        m_fonts[key] = new_font;
        return true;
    }

    /***/
    SDL_Texture *get_texture(std::string key) {
        return m_textures.at(key);
    }

    /***/
    Mix_Chunk *get_sound(std::string key) {
        return m_sounds.at(key);
    }

    /***/
    Mix_Music *get_music(std::string key) {
        return m_music.at(key);
    }

    /***/
    TTF_Font *get_font(std::string key) {
        return m_fonts.at(key);
    }

private:
    std::map<std::string, SDL_Texture*> m_textures;
    std::map<std::string, Mix_Chunk*> m_sounds;
    std::map<std::string, Mix_Music*> m_music;
    std::map<std::string, TTF_Font*> m_fonts;
};

#endif
