#include "animal.h"

Animal::Animal(std::string name)
{
  std::cout << "Animal::Animal - constructor, name: "
    << name << "\n";
  this->name = name;
}

Animal::~Animal()
{
  std::cout << "Animal::~Animal - destructor, name: "
    << name << "\n";
}

void Animal::walk()
{
  std::cout << name << " is walking\n";
}