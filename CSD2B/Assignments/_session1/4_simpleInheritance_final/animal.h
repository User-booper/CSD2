#ifndef _ANIMAL_H_
#define _ANIMAL_H_
#include <iostream>


class Animal
{
public:
    Animal::Animal(std::string name); //constructor
    ~Animal(); //destructor

    void walk();
protected:
    std::string name;
};

#endif