#pragma once
#include "Tile.h"
#include "Colors.h"

class StoneTile : public Tile
{
private:
   const std::string stone_obj_type = "StoneTile";
   const std::string stone_symbol = BrightBlackMacro "\xdb" ColorResetMacro;
public:
   const std::string& objType() const override { return stone_obj_type; };
   const std::string& getSymbol() const override { return stone_symbol; }  // Block char in extended ascii char set
   // "0xdb"
};