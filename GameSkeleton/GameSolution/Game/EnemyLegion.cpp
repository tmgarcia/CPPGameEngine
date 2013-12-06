#include "EnemyLegion.h"


void EnemyLegion::draw(Core::Graphics& g, Vector3D shipPosition)
{
	for (unsigned int i=0; i<numActiveTroops; i++)
	{
		if (troops[i] != NULL )
			troops[i]->draw(g, shipPosition);
	}
}
void EnemyLegion::update(float dt)
{
	for (unsigned int i=0; i<numActiveTroops; i++)
	{
		if (troops[i] != NULL )
			troops[i]->update(dt);
	}
}
void EnemyLegion::addEnemy(Vector3D position)
{
	if(numActiveTroops<MAX_ENEMIES)
	{
		troops.push_back(new Enemy(position));
		numActiveTroops++;
	}
}
void EnemyLegion::deleteEnemy(int i)
{
	delete troops[i];
	vector<Enemy*>::iterator where = troops.begin() + i;
	troops.erase( where );
	numActiveTroops--;
}

bool EnemyLegion::checkCollide(Vector3D colliderPosition, int type, int b)
{
	bool collided = false;
	int buffer =  b;
	for(unsigned int i=0; i<numActiveTroops; i++)
	{
		if(((colliderPosition.x>(troops[i]->position.x-buffer)) && (colliderPosition.x<(troops[i]->position.x+buffer))) && ((colliderPosition.y>(troops[i]->position.y-buffer))&&(colliderPosition.y<(troops[i]->position.y+buffer))))
		{
			collided = true;
			collidedPosition = Vector3D(troops[i]->position.x, troops[i]->position.y);
			if(type==1)
				deleteEnemy(i);
		}
	}
	return collided;
}