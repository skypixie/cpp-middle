#pragma once

#include <iostream> 

/*
* cloning different types of bad guys in game
*/

class Monster
{
public:
	virtual Monster* clone() = 0;

protected:
	int health_;
	int speed_;
};


class Ghost : public Monster
{
public:

	Ghost(int health, int speed)
	{
		health_ = health;
		speed_ = speed;
	}

	Monster* clone() override
	{
		return new Ghost(health_, speed_);
	}

	std::ostream& operator << (std::ostream& os)
	{
		os << "Ghost: HP(" << health_ << ") SPEED(" << speed_ << ")";
		return os;
	}
};


class Spawner
{
public:
	Spawner(Monster* prototype) : prototype_(prototype) {}

	Monster* SpawnMonster()
	{
		return prototype_->clone();
	}

private:
	Monster* prototype_;

};