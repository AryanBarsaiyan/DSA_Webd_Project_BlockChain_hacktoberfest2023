#include <iostream>

void printArray(int *array, int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << array[i] << std::endl;
}

void insertionSort(int *array, int n)
{
    int j;
    int temp;

    for (int i = 0; i < n; ++i)
    {
        j = i;
        while (j > 0 && array[j] < array[j - 1])
        {
            temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
            j--;
        }
    }
}

int main()
{
    int array[] = {95, 45, 48, 98, 1, 485, 65, 478, 1, 2325};
    int n = sizeof(array)/sizeof(array[0]);

    std::cout << "Before Insertion Sort :" << std::endl;
    printArray(array, n);

    insertionSort(array, n);

    std::cout << "After Insertion Sort :" << std::endl;
    printArray(array, n);
    return (0);
}
