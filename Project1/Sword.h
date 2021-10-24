#pragma once
#include "IGameObject.h"
#include "Colors.h"
#include "IItemInteractable.h"

class Sword : public IGameObject, public IItemInteractable
{

private:

   std::string sword_obj_type{ "Player" };
   std::string sword_symbol{ BrightRedMacro "\xc5" ColorResetMacro };
public:
   // IGameObject's Methods
   const std::string& objType() const override { return sword_obj_type; };
   const std::string& getSymbol() const override { return sword_symbol; };

   bool isDisplayable() const override { return true; };
   bool isSolid() const override { return false; };

   // IITemInteractable Methods
   //std::string getName() const override { return std::string{ "Sword" }; };
   std::string getName() const override { return "sword"; };
   virtual std::string standingOnItem() const { return "You are standing on a Flaming sword!"; };
};