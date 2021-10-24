#pragma once
#include <string>

struct  IGameObject {

   virtual ~IGameObject() = default;

   virtual const std::string& objType() const = 0;
   virtual const std::string& getSymbol() const = 0;

   virtual bool isDisplayable() const = 0;
   virtual bool isSolid() const = 0;
};