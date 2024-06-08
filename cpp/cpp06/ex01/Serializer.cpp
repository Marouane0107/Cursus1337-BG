#include "Serializer.hpp"

Serializer::Serializer(){}
Serializer::~Serializer(){}

Serializer::Serializer(Serializer const &o){
}

Serializer &Serializer::operator=(Serializer const &o)
{
    *this = o;
    return (*this);
}
 