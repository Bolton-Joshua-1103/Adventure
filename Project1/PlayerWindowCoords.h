#pragma once
#include "Coord.h"

struct PlayerWindowCoords {
   Coord upper_left{}; // Lowest Row, Lowest Column
   Coord upper_right{}; // Lowest Row, Highest Column

   Coord lower_left{}; // Highest Row, Lowest Column
   Coord lower_right{}; // Highest Row, Highest Column

   int row_delta{}; // how 'deep' into the edge the window is past the  (up and down, per cave row)
   int col_delta{}; // how 'deep' into the edge the window is past the  (left and right, per cave column)

   int player_view_distance{5}; // @@ potential syncing problem with player actual view distance

   Coord cave_upper_left{}; //These should always be inside the cave vector parameters
   Coord cave_upper_right{};

   Coord cave_lower_left{};
   Coord cave_lower_right{};



   void printWindowCoords();
   void printCaveWindowCoords();
   PlayerWindowCoords() = delete;
   void calcWindowCoords(const Coord& location);//do not use default constructor, always make with a location reference 
   PlayerWindowCoords(const Coord& location);
};