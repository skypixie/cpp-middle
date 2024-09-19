#include <iostream>
#include <exception>
#include <memory>


class Fraction
{
private:
	float numerator = 1.0f;
	float denomerator = 1.0f;

public:
	Fraction(float num, float denom)
	{
		numerator = num;

		if (denom == 0.0f)
			throw std::runtime_error("Denomerator can not equal 0.");
		denomerator = denom;
	}
};


int main()
{
	int num, denom;
	std::cout << "Type numerator and denomerator of the fraction: ";
	std::cin >> num >> denom;
	try
	{
		Fraction fraction = Fraction(num, denom);

		std::cout << "Successfully created a fraction!\n";
	}
	catch (std::runtime_error& error)
	{
		std::cout << "[!] Runtime error: " << error.what() << '\n';
	}
}