#include <iostream>
#include <vector>


class Integers
{
public:
    
    class VectorForwardIterator
    {
    private:
        int* cur_ = nullptr;

    public:
        VectorForwardIterator(int* first_el) : cur_(first_el) {}

        int& operator*() const
        {
            return *cur_;
        }
    
        int* operator->() const
        {
            return cur_;
        }

        friend bool operator==(const VectorForwardIterator& a, const VectorForwardIterator& b)
        {
            return a.cur_ == b.cur_;
        }

        friend bool operator!=(const VectorForwardIterator& a, const VectorForwardIterator& b)
        {
            return a.cur_ != b.cur_;
        }

        VectorForwardIterator& operator++()
        {
            ++cur_;
            return *this;
        }
    
        VectorForwardIterator& operator++(int)
        {
            VectorForwardIterator tmp = *this;
            ++(*this);
            return tmp;
        }
    };

    VectorForwardIterator begin()
    {
        return VectorForwardIterator(&data_[0]);
    }

    VectorForwardIterator end()
    {
        return VectorForwardIterator(&data_[data_.size() - 1]);
    }
    
private:
    std::vector<int> data_ {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
};

int main()
{
    
    Integers integers;
    std::fill(integers.begin(), integers.end(), 3);
    
    for (auto i : integers)
    {
        std::cout << i << '\n';
    }

    // ВИДИМО ТО, ЧТО ТРЕБОВАЛОСЬ!!!! =)
    std::vector<int> myVector;
    for (int count=0; count < 5; ++count)
    {
        myVector.push_back(count);
    }
    
    std::fill(myVector.begin(), myVector.end(), 10);
    std::vector<int>::const_iterator it;
    it = myVector.begin();
    while (it != myVector.end())
    {
        std::cout << *it << " ";
        ++it;
    }
 
    std::cout << '\n';
}
