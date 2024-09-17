#include <iostream>


class Vector
{
public:

	Vector(float a_ = 0, float b_ = 0, float c_ = 0) { a = a_, b = b_, c = c_; };

	friend float operator*(const Vector& v1, const Vector& v2);

	friend Vector operator-(const Vector& v1, const Vector& v2);

	friend std::istream& operator>>(std::istream& is, Vector& v);

	friend std::ostream& operator<<(std::ostream& os, const Vector& v);

private:

	float a = 0;
	float b = 0;
	float c = 0;
};


float operator*(const Vector& v1, const Vector& v2)
{
	return (v1.a * v2.a) + (v1.b * v2.b) + (v1.c * v2.c);
}

Vector operator-(const Vector& v1, const Vector& v2)
{
	return Vector(v1.a - v2.a, v1.b - v2.b, v1.c - v2.c);
}

std::istream& operator>>(std::istream& is, Vector& v)
{
	is >> v.a >> v.b >> v.c;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
	os << v.a << ' ' << v.b << ' ' << v.c;
	return os;
}


int main()
{
	Vector v1{ 4, 5, 6 };
	Vector v2 = Vector();

	std::cin >> v2;

	Vector v3 = v1 - v2;

	std::cout << v3;

	return 0;
}