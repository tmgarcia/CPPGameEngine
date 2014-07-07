#include "ReturningToBaseState.h"
#include "FetchingFlagState.h"

void ReturningToBaseState::update(NonPlayerCharacter* player)
{
	if(player->isCurrentlyPathing() && player->reachedCurrentGoalNode())
	{
		player->hasFlag = false;
		player->stopPathing();
		player->setStateToFetchingFlag();
	}
}