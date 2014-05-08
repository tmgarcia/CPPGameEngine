#include "FetchingFlagState.h"
#include "ReturningToBaseState.h"

void FetchingFlagState::update(NonPlayerCharacter* player)
{
	if(player->isCurrentlyPathing() && player->reachedCurrentGoalNode())
	{
		cout << "Flag fetching update" << endl;
		player->hasFlag = true;
		player->stopPathing();
		player->setStateToReturnHome();
	}
}