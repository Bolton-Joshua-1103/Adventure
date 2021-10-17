#pragma once
#include "Tile.h"
#include "Colors.h"

class GrassTile : public Tile
{
private:
   const std::string grass_obj_type = "GrassTile";
   const std::string grass_symbol = BGDarkGreenMacro "\xB0" ColorResetMacro;
public:
   const std::string& objType() const override { return grass_obj_type; };
   const std::string& getSymbol() const override { return grass_symbol; }  // Block char in extended ascii char set
   // "0xdb"
};