#pragma once

#include "BattleMapGenerator.h"
#include "MapGenerationDirector.h"

class MapGenerator
{
public:
	void GenerateMap()
	{
		auto SpaceshipGenerator = new SpaceshipBattleMap;
		auto IGenerator = static_cast<ICanGenerateBattleMap*>(SpaceshipGenerator);
		GenerationDirector::GenerateSpaceshipLocation(IGenerator);
		// locations->add(SpaceshipGenerator->GetResult())

		auto ForestGenerator = new ForestBattleMap;
		auto IGenerator = static_cast<ICanGenerateBattleMap*>(ForestGenerator);
		GenerationDirector::GenerateForestLocation(IGenerator);
		// locations->add(ForestGenerator->GetResult())

		// etc.
	}
};
