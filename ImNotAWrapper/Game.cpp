#include "pch.h"
#include "Game.h"
#include <vector>


Game::Game()
{
	
}


Game::~Game()
{
}

void Game::Start(sf::RenderWindow* _window, InputManager* _inputManager, PhysicsManager* _physicsManager, AudioManager* _audioManager, SceneManager* _sceneManager)
{
	m_mainWindow = _window;
	m_inputManager = _inputManager;
	m_physicsManager = _physicsManager;
	m_audioManager = _audioManager;
	m_sceneManager = _sceneManager;


	
	m_ssTexture.loadFromFile("../Assets/Images/splash1.png");
	m_ssSprite.setScale(0.35, 0.35);
	m_ssSprite.setTexture(m_ssTexture);

	sf::Texture texture2;
	texture2.loadFromFile("../Assets/Images/pacman.png");
	m_player = Player(&texture2, 100.0f);
	m_listOfPhysicsObjs.push_back(&m_player);

	//Creating the scene node
	m_scene = new GameObject;
	AudioComponent* bgMusic = new AudioComponent();
	bgMusic->LoadMusic("../Assets/Sounds/MainMusic.ogg");
	bgMusic->isActive = true;
	m_scene->AddComponent(bgMusic);
	m_listOfAudioObjs.push_back(m_scene);

	
	////Creating platform1 gameobject, will probably need to create a gameobject factory
	//GameObject platform1(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 500.0f));
	//RenderComponent* platform1RenderComp = new RenderComponent();
	//PhysicsComponent* platform1PhysicsComp = new PhysicsComponent(1.0f);
	//platform1.AddComponent(platform1RenderComp);
	//platform1.AddComponent(platform1PhysicsComp);
	//m_scene->AddChild(&platform1);
	//m_listOfPhysicsObjs.push_back(&platform1);

	////Creating platform2 gameobject
	//GameObject platform2(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));
	//RenderComponent* platform2RenderComp = new RenderComponent();
	//PhysicsComponent* platform2PhysicsComp = new PhysicsComponent(0.0f);
	//platform2.AddComponent(platform2RenderComp);
	//platform2.AddComponent(platform2PhysicsComp);
	//m_scene->AddChild(&platform2);
	//m_listOfPhysicsObjs.push_back(&platform2);


	m_sceneManager->LoadScene("../Assets/Scenes/jsonScene.json", m_scene, &m_listOfPhysicsObjs, &m_listOfAudioObjs, m_mainWindow);


	Update();
}

void Game::Update()
{
	float deltaTime = 0.0f;
	sf::Clock deltaClock;
	sf::Clock clock;
	sf::Time ssTimer = sf::seconds(3.0f);



	/*GameObject *sun = new GameObject;
	GameObject *earth = new GameObject;
	GameObject *moon = new GameObject;
	//scene->AddChild(&player);
	/*sun->AddChild(earth);
	earth->AddChild(moon);*/

	//m_inputManager.m_callbacks.push_back(&player.Movement);

	while (m_mainWindow->isOpen())
	{
		deltaTime = deltaClock.restart().asSeconds();
		sf::Event event;
		while (m_mainWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_mainWindow->close();
		}

		//view.setCenter(player.GetPosition());
		m_mainWindow->clear();

		//Splash Screen goes away after set time
		sf::Time elapsed1 = clock.getElapsedTime();
		if (ssTimer < elapsed1)
		{

			m_inputManager->Update(deltaTime);
			m_physicsManager->Update(deltaTime, &m_player, m_listOfPhysicsObjs);
			m_audioManager->Update(deltaTime, m_listOfAudioObjs);
			m_player.Update(deltaTime, m_mainWindow, m_inputManager->m_moveDirection);
			m_scene->Update(deltaTime, m_mainWindow);
			

		}
		else
		{
			m_mainWindow->draw(m_ssSprite);
			
			
		}

		m_mainWindow->display();


	}
}
