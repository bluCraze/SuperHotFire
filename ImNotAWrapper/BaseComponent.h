#pragma once
#include <string>

enum ComponentName{TRANSFORM,RENDERER,PHYSICS};

class BaseComponent
{
public:
	BaseComponent();
	~BaseComponent();

	void FindComponent(std::string _componentName) {

	}
private:
	   //ComponentName 
};

