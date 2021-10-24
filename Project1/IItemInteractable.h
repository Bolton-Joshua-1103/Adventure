#pragma once
#include <string>

struct  IItemInteractable {

   virtual ~IItemInteractable() = default;
   virtual std::string getName() const = 0;
   virtual std::string standingOnItem() const = 0;
};
