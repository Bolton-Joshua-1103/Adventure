#pragma once
#include <string>
#include "IGameObject.h"

struct  ICreature{

   virtual ~ICreature() = default;
   virtual std::string getName() const = 0;
   // Hittable, Killable, Friendly(or not), Askable(interactable)
};

