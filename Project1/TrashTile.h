#pragma once
#include "Tile.h"

class TrashTile : public Tile
{
   private:
      std::string trash_obj_type{"TrashTile"};
      std::string trash_symbol{ "T" };
public:
   const std::string& objType() const override { return trash_obj_type; };
   const std::string& getSymbol() const override { return trash_symbol; }
};