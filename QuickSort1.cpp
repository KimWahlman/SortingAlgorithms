#include <iostream>
#include <vector>

// On average this algorithm have a O(n log n) complexity.
void QuickSort(std::vector<int>& inputVector, int startIndex, int endIndex)
{
    // Here we find the middle element as pivot value.
    int pivot = inputVector[(startIndex + endIndex) / 2],
        i = startIndex,
        j = endIndex;

    // Here we rearrange the elements, if a element is lesser than the pivot
    // we place it on the left side of the pivot, if it is greater it goes
    // to the right. Elements equal to the pivot stay where they are.
    // This partition work even if the two parts are of different sizes.
    while(i <= j)
    {
        // Check the left side for values lesser than the pivot.
        // If we find a greater value, we stay on it.
        while(inputVector[i] < pivot)
            i++;

        // Check the right side for values greater than pivot.
        // If we find a lesser value, we stay on it.
        while(inputVector[j] > pivot)
            j--;

        // Is i lesser than or equal to j, if so, swap them.
        // Increment i, and decrement j
        if(i <= j)
        {
            int temp = inputVector[i];
            inputVector[i] = inputVector[j];
            inputVector[j] = temp;
            i++;
            j--;
        }
    }

    // Here we recursively apply the quick sort method
    // to the both sides.
    if(startIndex < j)
        QuickSort(inputVector, startIndex, j);
    if(i < endIndex)
        QuickSort(inputVector, i, endIndex);

}

int main()
{
    std::vector<int> input = { 1, 12, 5, 26, 7, 14, 3, 7, 2 };
    QuickSort(input, 0, input.size() - 1);

    for(unsigned int i = 0; i < input.size(); i++)
        std::cout << input[i] << " ";
    std::cout << std::endl;


    return 0;
}

/*******************************
  Input
  1, 12, 5, 26, 7, 14, 3, 7, 2

  Output
  1 2 3 5 7 7 12 14 26
*******************************/
