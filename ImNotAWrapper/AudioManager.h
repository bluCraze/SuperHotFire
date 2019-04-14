#pragma once
#include "GameObject.h"
#include "AudioComponent.h"

class AudioManager
{
public:
	AudioManager();
	~AudioManager();

	void Play(AudioComponent* _audio);
	void Stop(AudioComponent* _audio);

	void Update(float dt, std::vector<GameObject*> scene);
};

