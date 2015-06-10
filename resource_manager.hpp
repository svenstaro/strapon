#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <SDL2/SDL.h>
#include <string>
#include <map>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

class ResourceManager
{
public:

	/***/
	ResourceManager(){}
	
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
	bool load_surface(
		std::string &key,
		const char* path,
		SDL_Renderer *ren)
	{
		SDL_Texture *texture;
		texture = IMG_LoadTexture(ren,path);
		if(!texture)
		{
   			printf("IMG_Load: %s\n", IMG_GetError());
   			return false;
		}
		m_textures[key] = texture;
		return true;
	}
	
	/***/
	bool load_sound(std::string key, char* path)
	{
		Mix_Chunk *new_sound = Mix_LoadWAV(path);
		if(new_sound == NULL)
		{
			printf("Error: could not load sound from %s\n", path);
			return false;
		}
		m_sounds[key] = new_sound;
		return true;
	}

	/***/
	SDL_Texture* get_const_texture(std::string texture_key) 
	{
		return m_textures[texture_key];
	}

	/***/
	SDL_Texture* get_texture(std::string texture_key) 
	{
		return m_textures[texture_key];
	}

	/***/
	Mix_Chunk* get_const_sound(std::string sound_key) 
	{
		return m_sounds[sound_key];
	}
	
	/***/
	Mix_Chunk* get_sound(std::string sound_key) 
	{
		return m_sounds[sound_key];
	}

private:
	std::map<std::string,SDL_Texture*> m_textures;
	std::map<std::string,Mix_Chunk*> m_sounds;
};

#endif