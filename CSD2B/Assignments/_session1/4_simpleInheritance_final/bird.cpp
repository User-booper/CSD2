#include "bird.h"

//constructor and destructor

Bird::Bird(std::string name) : Pet(name)
{
  std::cout << "Bird::Bird - constructor, name: "
    << name << "\n";
}
Bird::~Bird()
{
  std::cout << "Bird::~Bird - destructor, name: "
    << name << "\n";
}

// methods
void Bird::fly()
{
  std::cout << name << " is flying.\n";
}
