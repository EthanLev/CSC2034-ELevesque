#pragma once
#include <string>

class IRepairable {

public:
    virtual ~IRepairable() {}; // interfaces need a destructor
    
    virtual std::string repair() = 0; // = 0 means pure virtual function, has to be overridden by children classess
};