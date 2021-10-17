#pragma once
#include "Tile.h"
class OpenTile : public Tile
{
private:
   std::string open_obj_type{"OpenTile"};
   std::string open_symbol{" "};
public:
   const std::string& objType() const override { return open_obj_type; };
   const std::string& getSymbol() const override { return open_symbol; }
};