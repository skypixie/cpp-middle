#include <iostream>
#include <string>


// index between 0 and 99
int hash_code(const std::string &in_str)
{
    int hash = 7;
    for (const char c : in_str)
    {
        hash = (hash * 31 + c) % 100;
    }
    return hash;
}

int main()
{
    // same
    std::cout << hash_code("Hello, World!") << '\n';
    std::cout << hash_code("Hello, World!") << '\n';

    // slightly differ
    std::cout << hash_code("aba") << '\n';
    std::cout << hash_code("abb") << '\n';
    
    return 0;
}
