#pragma once
#include "Tile.h"

class ErrorTile : public Tile
{
   private:
      std::string error_obj_type{ "ErrorTile" };
      std::string error_symbol{ "!" };
public:
   const std::string& objType() const override { return error_obj_type; };
   const std::string& getSymbol() const override { return error_symbol; }
};