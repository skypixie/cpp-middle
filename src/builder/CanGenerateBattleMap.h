#pragma once

class UObject {};

class ICanGenerateBattleMap
{
public:

	virtual UObject* GetResult() const = 0;
	virtual void GenerateGround() = 0;
	virtual void GenerateObstacles() = 0;
	virtual void GeneratePlayerSpawnPoints() = 0;
	virtual void GenerateWeaponSpawnPoints() = 0;
};