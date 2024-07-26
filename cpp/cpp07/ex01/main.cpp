#include "iter.hpp"

int main()
{
    int arr1[] = {1,2,3,4,5};
    std::cout<< "arr1: " << std::endl;
    iter(arr1, 5, print);

    float arr2[] = {1.1, 1.2, 1.3, 1.4, 1.5};
    std::cout<< "arr2: " << std::endl;
    iter(arr2, 5, print);

    std::string arr3[] = {"A", "B", "C", "D", "E"};
    std::cout<< "arr3: " << std::endl;
    iter(arr3, 5, print);
}