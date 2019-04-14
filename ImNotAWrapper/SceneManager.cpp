#include "pch.h"
#include "SceneManager.h"
#include <rapidjson/document.h>
#include <fstream>


SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

void SceneManager::LoadScene(std::string _scenePath)
{
	std::ifstream t(_scenePath);
	int length;
	//t.open(_scenePath);      // open input file
	if (!t) {
		printf("idiot");
	}
	t.seekg(0, std::ios::end);    // go to the end
	length = t.tellg();           // report location (this is the length)
	t.seekg(0, std::ios::beg);    // go back to the beginning
	m_jsonScene = new char[length];    // allocate memory for a buffer of appropriate dimension
	t.read(m_jsonScene, length);       // read the whole file into the buffer
	t.close();                    // close file handle

	rapidjson::Document document;
	document.Parse(m_jsonScene);

	

}
