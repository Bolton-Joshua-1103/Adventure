#pragma once
#include "IGameObject.h"
#include "Colors.h"

class Sword : public IGameObject
{

private:

   std::string sword_obj_type{ "Player" };
   std::string sword_symbol{ BrightRedMacro "\xc5" ColorResetMacro };
public:
   const std::string& objType() const override { return sword_obj_type; };
   const std::string& getSymbol() const override { return sword_symbol; };

   bool isDisplayable() const override { return true; };
   bool isSolid() const override { return false; };
};