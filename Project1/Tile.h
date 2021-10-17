#pragma once
#include "IGameObject.h"

class Tile : public IGameObject
{
   private:
      std::string tile_obj_type{ "Tile" };
      std::string tile_symbol{ "?" };

  public:
   const std::string& objType() const override { return tile_obj_type; };
   const std::string& getSymbol() const override { return tile_symbol; };

   bool isDisplayable() const override {return true; };
};