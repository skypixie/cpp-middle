#include <algorithm>
#include <iostream>
#include <list>


template <class T>
void printList(std::list<T> l)
{
    for (auto& i : l)
    {
        std::cout << i << " ";
    }
    std::cout << '\n';
}


int main()
{
    // заполнить список числами от 0 до 9
    std::list<int> list;
    list.resize(10);
    std::generate(list.begin(), list.end(), [](){static int i; return i++;});
    printList(list);

    // умножить все элементы на 10
    std::transform(list.begin(), list.end(), list.begin(), [](int i){return i * 10;});
    printList(list);

    // удалить все элементы больше 3 и убрать из списка удаленные элементы
    list.erase(std::remove_if(list.begin(), list.end(), [](int i){return i > 3;}), list.end());
    printList(list);
    
}