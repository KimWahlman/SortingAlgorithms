#include <iostream>
#include <vector>

void Merge(std::vector<int>& inputVector, int startIndex, int midIndex, int endIndex)
{
    std::vector<int> temporaryVector(inputVector.size() - 1);
    int i = startIndex, j = midIndex + 1, k = startIndex;

    while(i <= midIndex && j <= endIndex)
    {
        if(inputVector[i] < inputVector[j])
            temporaryVector[k++] = inputVector[i++];
        else
            temporaryVector[k++] = inputVector[j++];
    }

    for(; i <= midIndex; i++)
       temporaryVector[k++] = inputVector[i];

    for(; j <= endIndex; j++)
        temporaryVector[k++] = inputVector[j];

    for(i = startIndex; i <= endIndex; i++)
        inputVector[i] = temporaryVector[i];
}

void MergeSort(std::vector<int>& v, int startIndex, int endIndex)
{
    if(startIndex < endIndex)
    {
        int midIndex = (startIndex + endIndex) / 2;
        MergeSort(v, startIndex, midIndex);
        MergeSort(v, midIndex + 1, endIndex);
        Merge(v, startIndex, midIndex, endIndex);
    }
}

int main()
{
    std::vector<int> input = { 991, 262, 150, 121 };
    MergeSort(input, 0, 4);
    for(unsigned int i = 0; i < input.size(); i++)
        std::cout << input[i] << " ";
    std::cout << std::endl;
}
