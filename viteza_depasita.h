#pragma once
#include<exception>

class viteza_depasita : public std::exception
{
    const char* what_arg;
public:
    viteza_depasita(const char* what_arg = "") : what_arg(what_arg){}
    const char* what() const throw()
    {
        return what_arg;
    }
};
