#include "SceneManager.h"


SceneManager* SceneManager::theInstance;

SceneManager& SceneManager::getInstance()
{
	if(theInstance == 0)
	{
		theInstance = new SceneManager();
	}
	return *theInstance;
}
SceneManager::~SceneManager()
{

}
void SceneManager::cleanup()
{
	if(theInstance !=0)
	{
		delete theInstance;
	}
}

void SceneManager::update()
{
	EYE_POSITION = camera.getPosition();
	VIEW_TO_PROJECTION = glm::perspective(60.0f, ((float)WINDOW_WIDTH) / WINDOW_HEIGHT, 0.1f, 90.0f);
	WORLD_TO_VIEW = camera.getWorldToViewMatrix();
	WORLD_TO_PROJECTION = VIEW_TO_PROJECTION * WORLD_TO_VIEW;
}