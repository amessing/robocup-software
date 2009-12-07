#include "Defense.hpp"

using namespace std;

Gameplay::Plays::Defense::Defense(GameplayModule *gameplay):
	Play(gameplay),
	_fullback1(gameplay, Behaviors::Fullback::Left),
	_fullback2(gameplay, Behaviors::Fullback::Left), // should it be "right"?
	_kicker1(gameplay),
	_kicker2(gameplay)
{
	_fullback1.otherFullbacks.insert(&_fullback2);
	_fullback2.otherFullbacks.insert(&_fullback1);
}

bool Gameplay::Plays::Defense::applicable()
{
	bool refApplicable =_gameplay->state()->gameState.playing();
	bool gameplayApplicable = _gameplay->state()->stateID.posession == Packet::LogFrame::DEFENSE;

	return refApplicable && gameplayApplicable;
}

void Gameplay::Plays::Defense::assign(set<Robot *> &available)
{
	_fullback1.assign(available);
	_fullback2.assign(available);
	_kicker1.assign(available);
	_kicker2.assign(available);
}

bool Gameplay::Plays::Defense::run()
{
	_fullback1.run();
	_fullback2.run();
	_kicker1.run();
	_kicker2.run();
	
	return true;
}
