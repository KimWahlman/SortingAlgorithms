#include <iostream>
#include <vector>

// In this algorithms we simply move a element
// one position ahead of their current position.
// This algorithm works great together with QuickSort
// See QuickSort2.cpp.
void InsertionSort(std::vector<int>& v)
{
    for(unsigned int i = 0; i < v.size(); i++)
    {
        int key = v[i],
            j = i - 1;

        while(j >= 0 && v[j] > key)
            v[j + 1] = v[j--];

        v[j + 1] = key;
    }
}

int main()
{
    std::vector<int> input = { 9090, 10, 9, 4, 67, 69 };
    InsertionSort(input);
    for(unsigned int i = 0; i < input.size(); i++)
        std::cout << input[i] << " ";
    std::cout << std::endl;
}
