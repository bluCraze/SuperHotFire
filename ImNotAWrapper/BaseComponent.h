#pragma once
#include <string>

enum ComponentName{TRANSFORM,RENDERER,PHYSICS,AUDIO};

class BaseComponent
{
public:
	BaseComponent(ComponentName _componentName);
	~BaseComponent();
	ComponentName m_componentName;
	
private:
	   
};

