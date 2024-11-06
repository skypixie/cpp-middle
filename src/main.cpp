#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <array>


class Box
{
public:
    int* p_;

    Box()
    {
        p_ = new int;
    }
    
    Box(int p)
    {
        p_ = new int;
        *p_ = p;
    }
    ~Box()
    {
        delete p_;
    }

    // глубокое копирование
    Box(const Box& ToCopy)
    {
        p_ = new int;
        *p_ = *ToCopy.p_;
    }

    Box& operator=(const Box& rhs)
    {
        if (this != &rhs)
        {
            delete p_;
            p_ = new int;
            *p_ = *rhs.p_;
        }

        return *this;
    }

    void set_p(int p)
    {
        *p_ = p;
    }

    int get_p() const
    {
        return *p_;
    }
};


int main()
{
    //  DEEP COPY
    
    // создаем вектор из которого будем копировать
    std::vector<Box> boxes1;
    Box box1 = Box(1);
    Box box2 = Box(2);
    Box box3 = Box(3);
    boxes1.push_back(box1);
    boxes1.push_back(box2);
    boxes1.push_back(box3);
    
    // выведем вектор и значения из указателей
    std::cout << "boxes1: ";
    std::for_each(boxes1.begin(), boxes1.end(), [](const Box& box){std::cout << box.get_p() << ' ';});
    std::cout << '\n';
    
    // сюда будем копировать
    std::vector<Box> boxes2;
    boxes2.resize(boxes1.size()); // calls default constructor
    
    // копируем и выводим
    std::copy(boxes1.cbegin(), boxes1.cend(), boxes2.begin());
    std::cout << "boxes2: ";
    std::for_each(boxes2.begin(), boxes2.end(), [](const Box& box){std::cout << box.get_p() << ' ';});
    std::cout << '\n';
    
    // изменим значения на которые указывают указатели 
    for (auto& box : boxes2)
    {
        box.set_p(0);
    }
    
    // видим, что коробки из первого вектора не поменялись
    std::cout << "boxes1: ";
    std::for_each(boxes1.begin(), boxes1.end(), [](const Box& box){std::cout << box.get_p() << ' ';});
    std::cout << '\n';
    std::cout << "boxes2: ";
    std::for_each(boxes2.begin(), boxes2.end(), [](const Box& box){std::cout << box.get_p() << ' ';});
    std::cout << "\n\n";
    // ===========================================================



    
    // UNORDERED_MAP::COPY

    // создаем unordered_map
    std::unordered_map<std::string, int> name_to_age {
        {"Bob", 18},
        {"Trump", 78},
        {"Kamala", 59},
    };
    std::unordered_map<std::string, int> name_to_age2;

    // скопируем с использованием inserter
    std::copy(name_to_age.begin(), name_to_age.end(), std::inserter(name_to_age2, name_to_age2.end()));

    // вывод элементов словаря
    for (const auto& i : name_to_age2)
    {
        std::cout << i.first << ' ' << i.second << '\n';
    }
    std::cout << '\n';
    // ===========================================================



    
    // ARRAY::FILL

    // создаем массив 
    std::array<int, 5> arr;
    // заполняем семерками
    std::fill(arr.begin(), arr.end(), 7);
    // выводим
    std::for_each(arr.begin(), arr.end(), [](int i) { std::cout << i << ' '; });
    std::cout << '\n';
    // ===========================================================
    
}