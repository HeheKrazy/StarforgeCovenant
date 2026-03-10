// Copyright HeheKrazy


#include "Player/SFCPlayerState.h"

ASFCPlayerState::ASFCPlayerState()
{
	// Controls how often this actor replicates updates to clients (times per second).
	// Higher values = smoother updates but more network bandwidth usage.
	NetUpdateFrequency = 100.f;
}
