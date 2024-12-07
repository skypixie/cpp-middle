#include <algorithm>
#include <iostream>
#include <array>
#include <set>
#include <vector>


int main()
{
    // STD::PARTIAL_SORT_COPY
    std::array<int, 5> arr;
    std::generate(arr.begin(), arr.end(), [](){static int i = 5; return i--;});
    
    std::array<int, 5> arr2;
    std::partial_sort_copy(arr.begin(), arr.end(), arr2.begin(), arr2.end());
    
    // print both
    std::cout << "Array 1: ";
    std::for_each(arr.begin(), arr.end(), [](int i){std::cout << i << ' ';});
    std::cout << '\n';
    std::cout << "Array 2: ";
    std::for_each(arr2.begin(), arr2.end(), [](int i){std::cout << i << ' ';});
    std::cout << '\n';
    // ======================================================
    
    std::cout << "\n========================================================\n\n";
    
    
    // LOWER_BOUND и UPPER_BOUND
    std::array<int, 5> arr3 {10, 20, 30, 40 , 50};
    std::for_each(std::begin(arr3), std::end(arr3), [](int i){std::cout << i << ' ';});
    std::cout << '\n';
    
    std::cout << "first value >= 20: " << *std::lower_bound(arr3.begin(), arr3.end(), 20) << '\n';
    std::cout << "first value > 15: " << *std::upper_bound(arr3.begin(), arr3.end(), 15) << '\n';
    
    // SET::LOWER_BOUNT и SET::UPPER_BOUND
    std::set<int> set = {1, 4, 3, 2, 5, 7, 11, 10};
    std::cout << "first value >= 9: " << *set.lower_bound(9) << '\n';
    std::cout << "first value > 4: " << *set.upper_bound(4) << '\n';
    // ======================================================
    
    std::cout << "\n========================================================\n\n";

    // INCLUDES
    std::array<int, 10> arr4 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::array<int, 5> arr5 {3, 4, 5, 6, 7};
    
    std::for_each(arr4.begin(), arr4.end(), [](int i){std::cout << i << ' ';});
    std::cout << '\n';
    std::for_each(arr5.begin(), arr5.end(), [](int i){std::cout << i << ' ';});
    std::cout << '\n';
    
    if (std::includes(arr4.begin(), arr4.end(), arr5.begin(), arr5.end()))
    {
        std::cout << "[+] arr4 includes all elements from arr5\n";
    }
    else
    {
        std::cout << "[-] arr4 doesn't include all elements from arr5\n";
    }

    // SET_DIFFERENCE
    std::vector<int> o_arr;
    std::set_difference(arr4.cbegin(), arr4.cend(), arr5.cbegin(), arr5.cend(), std::back_inserter(o_arr));
    
    std::cout << "different elements are: " << '\n';
    std::for_each(o_arr.begin(), o_arr.end(), [](int i){std::cout << i << ' ';});
    std::cout << '\n';
    
}