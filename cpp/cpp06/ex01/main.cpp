#include "Serializer.hpp"

int main()
{
    Data data;
    data.num = 42;
    data.str = "Hello World!";
    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);
    if (ptr->num == data.num && ptr->str == data.str)
        std::cout << "Success!\n num: " << ptr->num << " str: " << ptr->str << std::endl;
    else
        std::cout << "Failure!" << std::endl;
    return (0);
}