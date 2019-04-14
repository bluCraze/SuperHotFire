#pragma once
#include "BaseComponent.h"
#include <SFML/Audio.hpp>


class AudioComponent :
	public BaseComponent
{
public:
	AudioComponent();
	~AudioComponent();

	void LoadSFX(std::string _soundBuffer);
	void LoadMusic(std::string _soundBuffer);
	void Play();
	void Stop();
	bool isActive = false;
	bool isPlaying = false;
	

	

private:
	
	sf::SoundBuffer m_buffer;
	sf::Sound m_sound;
	sf::Music m_music;
	bool m_isSFX = false;
	bool m_isMusic = false;


};

