#include "Array.hpp"

int main()
{
    Array<int> arr1(5);
    for (unsigned int i = 0; i < arr1.size(); i++)
        arr1[i] = i + 1;
    Array<int> arr2(arr1);
    Array<int> arr3;
    arr3 = arr1;
    for (unsigned int i = 0; i < arr1.size(); i++)
        std::cout << arr1[i] << " ";
    std::cout << std::endl;
    for (unsigned int i = 0; i < arr2.size(); i++)
        std::cout << arr2[i] << " ";
    std::cout << std::endl;
    for (unsigned int i = 0; i < arr3.size(); i++)
        std::cout << arr3[i] << " ";
    std::cout << std::endl;
    try
    {
        arr1[5] = 42;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught" << std::endl;
    }
    return 0;
}