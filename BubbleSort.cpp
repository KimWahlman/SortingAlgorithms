#include <iostream>
#include <vector>

void BubbleSort(std::vector<int>& vectorToSort)
{
    bool unsorted = true;
    while(unsorted)
    {
        for(int i = 0; i < vectorToSort.size() - 1; i++)
        {
            if(vectorToSort[i] > vectorToSort[i + 1])
            {
                int a = 0;
                a = vectorToSort[i];

                vectorToSort[i] = vectorToSort[i + 1];
                vectorToSort[i + 1] = a;
                unsorted = true;
                break;
            }
            unsorted = false;
        }
    }
}

int main()
{
    std::vector<int> inputVector = { 8, 5, 7, 3, 2 };
    BubbleSort(inputVector);

    for(int i = 0; i < inputVector.size(); i++)
        std::cout << inputVector[i] << " ";
    std::cout << std::endl;
}
