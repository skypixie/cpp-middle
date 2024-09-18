#include <iostream>
#include <vector>
#include <string>


class Wheel
{

public:
	Wheel() {};
	Wheel(float diam_) : diameter(diam_) {};

	float getDiameter() const
	{
		return diameter;
	}

private:
	float diameter = 0.6f;
};


class Engine
{

public:
	Engine() {};
	Engine(float power_) : power(power_) {};

	float getPower() const
	{
		return power;
	}

private:

	float power = 300.f;
};

class Vehicle
{
public:

	virtual std::ostream& print(std::ostream& out) const = 0;

	friend std::ostream& operator<<(std::ostream& out, Vehicle& vehicle)
	{
		return vehicle.print(out);
	}
};


class WaterVehicle : public Vehicle
{
private:
	float upsetting = 10.f;

public:

	WaterVehicle(float upsetting_)
	{
		setUpsetting(upsetting_);
	}

	std::ostream& print(std::ostream& out) const override
	{
		out << "WaterVehicle Upsetting : " << getUpsetting();
		return out;
	}

	float getUpsetting() const
	{
		return upsetting;
	}

	void setUpsetting(float newUpsetting)
	{
		upsetting = newUpsetting;
	}

};


class RoadVehicle : public Vehicle
{
private:
	float clearance = 200.0f;

public:

	std::ostream& print(std::ostream& out) const override
	{
		out << "RoadVehicle";
		return out;
	}

	float getClearance() const
	{
		return clearance;
	}

	void setClearance(float newClearance)
	{
		clearance = newClearance;
	}

};


class Bicycle : public RoadVehicle
{

public:

	Bicycle(Wheel fWheel, Wheel rWheel, float Clearance_)
	{
		FrontWheel = fWheel;
		RearWheel = rWheel;
		setClearance(Clearance_);
	}

	std::ostream& print(std::ostream& out) const override
	{
		out << "Bicycle Wheels : " << FrontWheel.getDiameter() << ' ' << RearWheel.getDiameter() << " Ride height : " << getClearance();
		return out;
	}

private:
	Wheel FrontWheel;
	Wheel RearWheel;

};


class Car : public RoadVehicle
{

public:

	Car(Engine CarEngine_, Wheel flWheel, Wheel frWheel, Wheel rlWheel, Wheel rrWheel, float Clearance_)
	{
		CarEngine = CarEngine_;
		FrontLeftWheel = flWheel;
		FrontRightWheel = frWheel;
		RearLeftWheel = rlWheel;
		RearRightWheel = rrWheel;
		setClearance(Clearance_);
	}

	std::ostream& print(std::ostream& out) const override
	{
		out << "Car Engine : " << CarEngine.getPower()
			<< " Wheels : " << FrontLeftWheel.getDiameter()
			<< ' ' << FrontRightWheel.getDiameter()
			<< ' ' << RearLeftWheel.getDiameter()
			<< ' ' << RearRightWheel.getDiameter()
			<< " Ride height : " << getClearance();
		return out;
	}

	float getPower()
	{
		return CarEngine.getPower();
	}

private:

	Wheel FrontLeftWheel;
	Wheel FrontRightWheel;
	Wheel RearLeftWheel;
	Wheel RearRightWheel;

	Engine CarEngine;
};


float getHighestPower(std::vector<Vehicle*>& v)
{
	float result = 0.0f;
	for (auto vehiclePtr : v)
	{
		Car* car = dynamic_cast<Car*>(vehiclePtr);
		if (car && car->getPower() > result)
		{
			result = car->getPower();
		}
	}

	return result;
}

int main()

{

	Car c(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 150);

	std::cout << c << '\n';



	Bicycle t(Wheel(20), Wheel(20), 300);

	std::cout << t << '\n';

	std::vector<Vehicle*> v;

	v.push_back(new Car(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 250));

	// WHAT IS CIRCLE ???
	// IT IS NOT MENTIONED IN THE TASK
	//v.push_back(new Circle(Point(1, 2, 3), 7));

	v.push_back(new Car(Engine(200), Wheel(19), Wheel(19), Wheel(19), Wheel(19), 130));

	v.push_back(new WaterVehicle(5000));

	// Вывод элементов вектора v здесь
	for (auto vehiclePtr : v)
	{
		std::cout << *vehiclePtr << '\n';
	}

	// vehicle MUST have an ENGINE to have power so it has to be a CAR
	std::cout << "The highest power is " << getHighestPower(v) << '\n'; // реализуйте эту функцию

	//TODO: Удаление элементов вектора v здесь
	for (auto vehiclePtr : v)
	{
		delete vehiclePtr;
		vehiclePtr = nullptr;
	}
	v.erase(v.begin(), v.end());
	
	std::cout << "Vector has " << v.size() << " elements\n";

	return 0;

}