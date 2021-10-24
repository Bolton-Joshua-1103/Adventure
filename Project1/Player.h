#pragma once
#include "IGameObject.h"
#include "Colors.h"
#include "Coord.h"

class Player : public IGameObject
{
private:


   std::string player_obj_type{ "Player" };
   std::string player_symbol{ BrightYelloMacro "\xEB" ColorResetMacro };

public:

   const int view_distance{ 5 };
   Coord location{ 0, 0 };
   Player(size_t _row, size_t _col)
   {
      location.row = _row;
      location.col = _col;
   }



   const std::string& objType() const override { return player_obj_type; };
   const std::string& getSymbol() const override { return player_symbol; };

   bool isDisplayable() const override { return true; };
   bool isSolid() const override { return true; };
};