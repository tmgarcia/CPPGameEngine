#include "MathTools.h"

static const float _180_PI = 180/3.14159265359;

MathTools MathTools::theInstance;
MathTools& MathTools::getInstance()
{
	return theInstance;
}

mat4 MathTools::getAlignMatrix(const vec3& originalOrientation, const vec3& newOrientation)
{
	glm::vec3 original = glm::normalize(originalOrientation);
    float yaw = acos(glm::dot(original, glm::normalize(glm::vec3(newOrientation.x, 0, newOrientation.z)))) * _180_PI;
    float pitch = 0.0f;
    if(yaw * 0 != 0)
    {
            yaw = 0;
            pitch = acos(glm::dot(original, glm::normalize(newOrientation))) * _180_PI;
    }
    else
    {
            if(newOrientation.x < 0)
                    yaw = -yaw;
            glm::vec3 pitchVector = glm::vec3(glm::vec4(original, 0) * glm::rotate(yaw, glm::vec3(0,1,0)));
            pitch = acos(glm::dot(pitchVector, glm::normalize(newOrientation))) * _180_PI;
    }
    if(pitch * 0 != 0)
    {
            pitch = 0;
    }
    else if(newOrientation.y > 0)
    {
            pitch = -pitch;
    }
      mat4 r1 = glm::rotate(pitch, vec3(1.0f,0.0f,0.0f));
	  mat4 r2 = glm::rotate(-yaw, vec3(0.0f,1.0f,0.0f));
    return r1 * r2;
}