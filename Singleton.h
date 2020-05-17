#pragma once

#include<iostream>

class Random
{
public:
    Random(const Random&) = delete;

    static Random& Get()
    {
        static Random instance;
        return instance;
    }

    static float Float() { return Get().IFloat(); }
private:
    float IFloat() { return m_RandomGenerator; }
    Random() {}

    float m_RandomGenerator = 2.0f;
};
