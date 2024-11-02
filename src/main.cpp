#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <string>


bool has_burger(std::pair<std::string, float> menu_line)
{
    return menu_line.first.find("Burger") != std::string::npos;
}


int main()
{
    // MAP::FIND
    std::map<std::string, int> name_to_age {
        {"Cartman", 10},
        {"Kyle", 10},
        {"Stan", 10},
        {"Kenny", 10},
        {"Butters", 9},
        {"Liane", 40}
    };
    
    std::string target_name;
    std::cout << "Enter your name ";
    std::cin >> target_name;
    
    if (name_to_age.count(target_name))
    {
        std::cout << target_name << "'s age is " << name_to_age.find(target_name)->second << '\n';
    }
    else
    {
        std::cout << "We don't have such name yet!\n";
    }
    std::cout << "=================================\n";

    // UNORDERED_MAP::COUNT_IF
    std::unordered_map<std::string, float> menu {
        {"Burger", 2.99},
        {"Cola", 0.99},
        {"Chips", 1.99},
        {"Cheese Burger", 3.50},
        {"Super Mega Burger", 6.0},
    };
    
    // считаем, сколько в нашем меню бургеров, проверяя вхождения подстроки "Burger" в позиции меню
    // с помощью лямбда-функции
    const long long n_burgers = std::count_if(menu.begin(),
        menu.end(),
        [](std::pair<std::string, float> menu_line){return menu_line.first.find("Burger") != std::string::npos;});
    std::printf("We have %lld types of burgers in our menu\n", n_burgers);
    std::cout << "=================================\n";

    // SET::FOR_EACH
    std::set<int> numbers {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "Numbers: ";
    for (auto n : numbers)
    {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    std::cout << "Numbers x2: ";
    // выведем числа, умноженный на 2
    std::for_each(numbers.begin(),
        numbers.end(),
        [](int const& n){std::cout << n * 2 << ' ';});
    std::cout << '\n';
    
}
