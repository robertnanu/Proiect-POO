#pragma once

#include<iostream>
#include<string>
#include<memory>

class Entitate
{
public:
    Entitate()
    {
        std::cout<<"Jocul a inceput!"<<std::endl;
    }

    ~Entitate()
    {
        std::cout<<"Jocul s-a terminat!"<<std::endl;
    }

    void Print() {}
};


