#include "ClickBoxComponent.h"
#include "SceneManager.h"
#include "DebugTools/ConsolePrinter.h"
#include "Renderer/GeneralGLWindow.h"

ClickBoxComponent::ClickBoxComponent()
{
	QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(mouseClicked(QMouseEvent*)), this, SLOT(mouseClickReaction(QMouseEvent*)));
}

void ClickBoxComponent::mouseClickReaction(QMouseEvent* e)
{
	int xPX = e->x();
	int yPX = e->y();
	int windowWidth = SceneManager::getInstance().WINDOW_WIDTH;
	int windowHeight = SceneManager::getInstance().WINDOW_HEIGHT;
	float xFraction = (float)xPX/windowWidth;
	float yFraction = (float)(windowHeight-yPX)/windowHeight;

	float vectorXPosition = (float)(xFraction*2)-1.0f;
	float vectorYPosition = (float)(yFraction*2)-1.0f;
	float vectorZPosition = -1.0f;

	mat4 invertedVP = glm::inverse(SceneManager::getInstance().VIEW_TO_PROJECTION);

	vec4 clickVectorVP = vec4(vectorXPosition, vectorYPosition, vectorZPosition, 1.0f);
	vec4 clickVectorWP = invertedVP * clickVectorVP;

	clickVectorWP.z = -1.0f;
	clickVectorWP.w = 0.0f;

	mat4 invertedWV = glm::inverse(SceneManager::getInstance().WORLD_TO_VIEW);
	vec4 clickVectorW = invertedWV * clickVectorWP;

	vec3 direction = glm::normalize(vec3(clickVectorW));//normalized
	vec3 origin = SceneManager::getInstance().camera.getPosition();


	vec3 pointOnPlane = boxOrigin;
	vec3 surfaceNormal = glm::normalize(vec3(0,1,0));

	float numerator = glm::dot((origin - pointOnPlane), surfaceNormal);
	float denominator = glm::dot(direction, surfaceNormal);
	float distance = - numerator/denominator;

	vec3 intersectionPoint = origin + (direction * distance);

	if(distance>0)
	{
		if(isWithinBox(intersectionPoint))
		{
			if(e->button()==Qt::RightButton)
			{
				emit RightClicked();
			}
			else
			{
				emit LeftClicked();
			}
		}
	}

}
bool ClickBoxComponent::isWithinBox(vec3 point)
{
	return (isWithinWidth(point.x) && isWithinHeight(point.y) && isWithinLength(point.z));
}
bool ClickBoxComponent::isWithinWidth(float x)
{
	return (x < boxOrigin.x+(width/2.0f) && x > boxOrigin.x-(width/2.0f));
}
bool ClickBoxComponent::isWithinHeight(float y)
{
	return (y < boxOrigin.y+(height/2.0f) && y > boxOrigin.y-(height/2.0f));
}
bool ClickBoxComponent::isWithinLength(float z)
{
	return (z < boxOrigin.z+(length/2.0f) && z > boxOrigin.z-(length/2.0f));
}

void ClickBoxComponent::update()
{
	
}

void ClickBoxComponent::cleanup()
{

}