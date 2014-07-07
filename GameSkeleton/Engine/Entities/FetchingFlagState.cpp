#include "FetchingFlagState.h"
#include "ReturningToBaseState.h"

void FetchingFlagState::update(NonPlayerCharacter* player)
{
	if(player->isCurrentlyPathing() && player->reachedCurrentGoalNode())
	{
		player->hasFlag = true;
		player->stopPathing();
		player->setStateToReturnHome();
	}
}