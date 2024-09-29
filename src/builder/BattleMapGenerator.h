#pragma once

#include "CanGenerateBattleMap.h"

class ForestBattleMap : public ICanGenerateBattleMap, public UObject
{
public:
	virtual UObject* GetResult() const override { return new UObject; };
	void GenerateGround() override
	{
		GenerateBushes();
		GenerateFoliage();
	};
	void GenerateObstacles() override
	{
		GenerateRocks();
	};
	void GeneratePlayerSpawnPoints() {};
	void GenerateWeaponSpawnPoints() {};

protected:
	void GenerateTrees() {};
	void GenerateRocks() {};
	void GenerateBushes() {};
	void GenerateFoliage() {};
};

class SpaceshipBattleMap : public ICanGenerateBattleMap, public UObject
{
public:
	virtual UObject* GetResult() const override { return new UObject; };
	void GenerateGround() override {};
	void GenerateObstacles() override
	{
		GenerateSpaceshipWalls();
		GenerateTeleports();
	};
	void GeneratePlayerSpawnPoints() {};
	void GenerateWeaponSpawnPoints() {};

protected:
	void GenerateTeleports() {};
	void GenerateSpaceshipWalls() {};
};

class DungeonBattleMap : public ForestBattleMap, public UObject
{
public:
	virtual UObject* GetResult() const override { return new UObject; };
	void GenerateGround() override
	{
		GenerateFoliage();
	};
	void GenerateObstacles() override
	{
		GenerateWalls();
		GenerateTraps();
	};
	void GeneratePlayerSpawnPoints() {};
	void GenerateWeaponSpawnPoints() {};

protected:
	void GenerateTraps() {};
	void GenerateFoliage() {};
	void GenerateWalls() {};
};