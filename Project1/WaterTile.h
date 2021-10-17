#pragma once
#include "Tile.h"
#include "Colors.h"

class WaterTile : public Tile
{
private:
   std::string water_obj_type{"WaterTile" };

   std::string water_symbol{ BGBrightBlueMacro "\xF7" ColorResetMacro };
public:
   const std::string& objType() const override { return water_obj_type; };
   const std::string& getSymbol() const override { return water_symbol; }
   // "0xf7"
};