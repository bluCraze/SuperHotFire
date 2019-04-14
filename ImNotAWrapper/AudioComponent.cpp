#include "pch.h"
#include "AudioComponent.h"



AudioComponent::AudioComponent():BaseComponent(AUDIO)
{
}


AudioComponent::~AudioComponent()
{
}

void AudioComponent::LoadSFX(std::string _soundFile)
{
	if (!m_buffer.loadFromFile(_soundFile)) {
		printf("Failure for SFX");
	}
	m_sound.setBuffer(m_buffer);
	m_isSFX = true;
}

void AudioComponent::LoadMusic(std::string _soundFile)
{
	if (!m_music.openFromFile(_soundFile))
		printf("Failure for music");

	m_isMusic = true;

}

void AudioComponent::Play()
{
	if (m_isSFX) {
		m_sound.play();
		isPlaying = true;
	}
	else if (m_isMusic) {
		if (!isPlaying){ 
			m_music.play();
			isPlaying = true;
		}
	}
}

void AudioComponent::Stop()
{
	if (m_isSFX) {
		m_sound.stop();
		isPlaying = false;
	}
	else if (m_isMusic) {
		if (!isPlaying) {
			m_music.stop();
			isPlaying = false;
		}
	}
}
