#include <iostream>


/* creating different types of characters that can have different weapons and vehicles */


class Weapon
{
public:

	virtual void Attack() = 0;
};


class Sword : public Weapon
{
public:

	void Attack() override
	{
		std::cout << "Hit!\n";
	}
};

class Pistol : public Weapon
{
public:

	void Attack() override
	{
		std::cout << "Shoot!\n";
	
	}
};


class Vehicle
{
public:

	virtual void Ride() = 0;
};


class Car : public Vehicle
{
	void Ride() override
	{
		std::cout << "VROOOM\n";
	}
};


class Motorcycle : public Vehicle
{
	void Ride() override
	{
		std::cout << "VOOOSH\n";
	}
};


class CharFactory
{
public:

	virtual Weapon* CreateWeapon() = 0;

	virtual Vehicle* CreateVehicle() = 0;
};


class FighterFactory : public CharFactory
{
public:
	Weapon* CreateWeapon() override
	{
		return new Sword;
	}

	Vehicle* CreateVehicle() override
	{
		return new Motorcycle;
	}
};


class ShooterFactory : public CharFactory
{
public:
	Weapon* CreateWeapon() override
	{
		return new Pistol;
	}

	Vehicle* CreateVehicle() override
	{
		return new Car;
	}
};

// character acts as client's code
class Character
{
private:

	Weapon* weapon;
	Vehicle* vehicle;

public:

	Character(CharFactory* factory)
	{
		weapon = factory->CreateWeapon();
		vehicle = factory->CreateVehicle();
	}

	void Attack()
	{
		weapon->Attack();
	}

	void Go()
	{
		vehicle->Ride();
	}
};


//int main()
//{
//	FighterFactory* fighter_f = new FighterFactory;
//	ShooterFactory* shooter_f = new ShooterFactory;
//
//	Character* hero = new Character(fighter_f);
//	Character* opponent = new Character(shooter_f);
//
//	hero->Attack();
//	hero->Go();
//
//	std::cout << '\n';
//
//	opponent->Attack();
//	opponent->Go();
//
//}