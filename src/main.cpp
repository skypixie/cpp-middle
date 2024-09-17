#include <iostream>
#include <cstdlib>


class A
{

public:

	A(int rows_, int columns_, std::string* info_, std::string* description_, int** ArrToCopy = nullptr)
	{
		rows = rows_;
		columns = columns_;
		info = new std::string(*info_);
		description = new std::string(*description_);

		list = new int* [rows] {};
		for (int i = 0; i < rows; ++i)
		{
			list[i] = new int[columns] {};
		}

		if (ArrToCopy)
		{
			for (int i = 0; i < rows; ++i)
			{
				for (int j = 0; j < columns; ++j)
				{
					list[i][j] = ArrToCopy[i][j];
				}
			}
		}
	}

	A& operator=(A& other)
	{
		ClearArray();

		// new data
		rows = other.rows;
		columns = other.columns;

		if (other.info)
		{
			if (info) delete info;
			info = new std::string(*(other.info));
		}

		if (other.description)
		{
			if (description) delete description;
			description = new std::string(*(other.description));
		}

		// create new array with new data
		list = new int* [rows] {};
		for (int i = 0; i < rows; ++i)
		{
			list[i] = new int[columns] {};
			for (int j = 0; j < columns; ++j)
			{
				list[i][j] = other.list[i][j];
			}
		}

		return *(this);
	}

	void print()
	{
		std::cout << *info << ' ' << *description << '\n';

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				std::cout << list[i][j] << ' ';
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}

private:
	int rows = 0;
	int columns = 0;
	int** list = nullptr;
	std::string* info;
	std::string* description;

	void ClearArray()
	{
		for (int i = 0; i < rows; ++i)
		{
			delete[] list[i];
		}
		delete[] list;
		list = nullptr;
	}

};

int** GenerateArray(int r, int c)
{
	int** A;
	A = new int* [r];
	for (int i = 0; i < r; i++) {
		A[i] = new int[c];
	}
	return A;
}

void InitArray(int** A, int r, int c)
{
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			A[i][j] = std::rand() % 100;
		}
	}
}


int main()
{
	std::string* s1 = new std::string("obj1");
	std::string* s2 = new std::string("obj2");
	int rows1 = 1;
	int columns1 = 2;
	int rows2 = 2;
	int columns2 = 3;
	int** numbers1 = GenerateArray(rows1, columns1);
	int** numbers2 = GenerateArray(rows2, columns2);
	InitArray(numbers1, rows1, columns1);
	InitArray(numbers2, rows2, columns2);

	A obj1 = A(1, 2, s1, s1, numbers1);
	A obj2 = A(2, 3, s2, s2, numbers2);

	std::cout << "Array 1\n";
	obj1.print();
	std::cout << "Array 2\n";
	obj2.print();

	obj1 = obj2;

	std::cout << "Array 1\n";
	obj1.print();

	return 0;
}