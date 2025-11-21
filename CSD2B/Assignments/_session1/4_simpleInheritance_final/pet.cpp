#include "pet.h"
#include "animal.h"

//constructor and destructor
Pet::Pet(std::string name) : Animal(name)
{
  std::cout << "Pet::Pet - constructor, name: "
    << name << "\n";
  this->name = name;
}

Pet::~Pet()
{
  std::cout << "Pet::~Pet - destructor, name: "
    << name << "\n";
}

void Pet::sleep()
{
  std::cout << name << " is sleeping\n";
}
void Pet::eat()
{
  std::cout << name << " is eating\n";
}
void Pet::drink(){
  std::cout << name << " is drinking\n";
}