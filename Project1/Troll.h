#pragma once

#include "IGameObject.h"
#include "Colors.h"
#include "ICreature.h"

class Troll : public IGameObject, public ICreature
{

private:

   std::string object_type{ "Player" };
   std::string object_symbol{ BGDarkBlueMacro BrightWhiteMacro "\x9D" ColorResetMacro };
public:
   // IGameObject's Methods
   const std::string& objType() const override { return object_type; };
   const std::string& getSymbol() const override { return object_symbol; };

   bool isDisplayable() const override { return true; };
   bool isSolid() const override { return true; };

   // ICreature Methods
   std::string getName() const override { return "troll"; };
};
