#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include <map>
#include <SDL2/SDL_image.h>
#ifdef __EMSCRIPTEN__
#include <SDL/SDL_mixer.h>
#else
#include <SDL2/SDL_mixer.h>
#endif

class ResourceManager
{
public:
	/***/
	~ResourceManager()
	{
		for(auto e : m_textures)
		{
			SDL_DestroyTexture(e.second);
		}

		for(auto e : m_sounds)
		{
			Mix_FreeChunk(e.second);
		}
	}

	/***/
	bool load_surface(const std::string &key,
					  const std::string &path,
					  SDL_Renderer *ren)
	{
		SDL_Texture *texture;
		texture = IMG_LoadTexture(ren, path.c_str());
		if(!texture)
		{
   			std::cerr << "IMG_Load:" << IMG_GetError() << std::endl;
   			return false;
		}

		m_textures[key] = texture;
		return true;
	}
	
	/***/
	bool load_sound(std::string key, std::string &path)
	{
		Mix_Chunk *new_sound = Mix_LoadWAV(path.c_str());
		if(new_sound == NULL)
		{
			std::cerr << "Error: could not load sound from" << path << std::endl;
			return false;
		}
		m_sounds[key] = new_sound;
		return true;
	}

	/***/
	SDL_Texture* get_const_texture(std::string texture_key) 
	{
		return m_textures.at(texture_key);
	}

	/***/
	SDL_Texture* get_texture(std::string texture_key) 
	{
		return m_textures.at(texture_key);
	}

	/***/
	Mix_Chunk* get_const_sound(std::string sound_key) 
	{
		return m_sounds.at(sound_key);
	}
	
	/***/
	Mix_Chunk* get_sound(std::string sound_key) 
	{
		return m_sounds.at(sound_key);
	}

private:
	std::map<std::string,SDL_Texture*> m_textures;
	std::map<std::string,Mix_Chunk*> m_sounds;
};

#endif
