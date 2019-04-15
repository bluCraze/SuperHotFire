#include "pch.h"
#include "SceneManager.h"
#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>
#include <fstream>

#pragma warning(disable : 4996)


SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

void SceneManager::LoadScene(std::string _scenePath, GameObject* _sceneNode, std::vector<GameObject*>* _listOfPhysicsObjs, std::vector<GameObject*>* _listOfAudioObjs, sf::RenderWindow* _window)
{
	FILE* fp = fopen(_scenePath.c_str(), "rb"); // non-Windows use "r"

	char readBuffer[65536];
	rapidjson::FileReadStream m_jsonScene(fp, readBuffer, sizeof(readBuffer));

	rapidjson::Document documentScene;
	documentScene.ParseStream(m_jsonScene);

	
	//printf(documentScene["SceneName"].GetString());

	fclose(fp);

	_sceneNode->SetName(documentScene["SceneName"].GetString());
	_window->setTitle(documentScene["SceneName"].GetString());

	//Gets a reference to the gameObjects array in the json
	const rapidjson::Value& gameObjects = documentScene["GameObjects"];
	//Loops through all the elements in the above array
	for (rapidjson::Value::ConstValueIterator itr = gameObjects.Begin(); itr != gameObjects.End(); ++itr) {
		
		GameObject* tempGameObject = new GameObject(nullptr,
			sf::Vector2f(itr->FindMember("Width")->value.GetFloat(), itr->FindMember("Height")->value.GetFloat()),
			sf::Vector2f(itr->FindMember("PositionX")->value.GetFloat(), itr->FindMember("PositionY")->value.GetFloat()),
			itr->FindMember("Colour")->value.GetString());
		tempGameObject->SetName(itr->FindMember("Name")->value.GetString());
		if (itr->FindMember("PhysicsComponent")->value.GetBool()) {
			PhysicsComponent* PhysicsComp = new PhysicsComponent(1.0f);
			tempGameObject->AddComponent(PhysicsComp);
			_listOfPhysicsObjs->push_back(tempGameObject);
		}
		if (itr->FindMember("AudioComponent")->value.GetBool()) {
			AudioComponent* AudioComp = new AudioComponent();
			tempGameObject->AddComponent(AudioComp);
			_listOfAudioObjs->push_back(tempGameObject);
		}
		if (itr->FindMember("RenderComponent")->value.GetBool()) {
			RenderComponent* RenderComp = new RenderComponent();
			tempGameObject->AddComponent(RenderComp);
		}
		
		tempGameObject->SetParent(_sceneNode);
		_sceneNode->AddChild(tempGameObject);
		
	}
	//for (rapidjson::Value::ConstMemberIterator itr = gameObjects.MemberBegin(); itr != gameObjects.MemberEnd(); ++itr) {
	//	//itr->
	//}
	//assert(gameObjects.IsArray());
	//printf("GameObjects = %s\n", gameObjects[0].FindMember("Name")->value.GetString());

}
