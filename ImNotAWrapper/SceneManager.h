#pragma once
#include <string>

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void LoadScene(std::string _scenePath);

private:

	char* m_jsonScene;
};

