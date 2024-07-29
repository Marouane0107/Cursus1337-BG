#include "Array.hpp"


int main()
{
    Array<int> arr(5);
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i + 1;
        std::cout << arr[i] << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;
    try
    {
        arr[-2] = -2;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-----------------------------------" << std::endl;
    try
    {
        arr[1] = 1337;
        std::cout << arr[1] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}