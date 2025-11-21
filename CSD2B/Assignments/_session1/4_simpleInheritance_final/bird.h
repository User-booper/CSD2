#include "pet.h"

class Bird: public Pet
{
public:
  //constructor and destructor
  Bird(std::string name);
  ~Bird();

  // methods
  void fly();
};
