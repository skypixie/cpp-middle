#pragma once

#include "CanGenerateBattleMap.h"


class GenerationDirector
{
public:
	static void GenerateForestLocation(ICanGenerateBattleMap* Generator)
	{
		if (Generator)
		{
			Generator->GenerateGround();
			Generator->GenerateObstacles();
			Generator->GeneratePlayerSpawnPoints();
		}
	}

	static void GenerateSpaceshipLocation(ICanGenerateBattleMap* Generator)
	{
		if (Generator)
		{
			Generator->GenerateGround();
			Generator->GenerateObstacles();
			Generator->GeneratePlayerSpawnPoints();
			Generator->GenerateWeaponSpawnPoints();
		}
	}

	static void GenerateDungeonLocation(ICanGenerateBattleMap* Generator)
	{
		if (Generator)
		{
			Generator->GenerateGround();
			Generator->GenerateObstacles();
			Generator->GenerateWeaponSpawnPoints();
		}
	}
};