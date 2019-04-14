#include "pch.h"
#include "AudioManager.h"



AudioManager::AudioManager()
{
}


AudioManager::~AudioManager()
{
}

void AudioManager::Play(AudioComponent* _audio)
{
	_audio->Play();
}

void AudioManager::Stop(AudioComponent* _audio)
{
	_audio->Stop();
}

void AudioManager::Update(float dt, std::vector<GameObject*> scene)
{
	for (auto &gameObject : scene) {
		AudioComponent* objectAudio = (AudioComponent *)gameObject->GetComponent(AUDIO);
		if (objectAudio->isActive) {
			Play(objectAudio);
		}
			
	}
}
