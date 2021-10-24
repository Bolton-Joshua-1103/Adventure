#include <iostream>
#include <cassert>
#include <tuple>
#include <algorithm>
#include <utility>
#include <functional>
#include "Cave.h"
#include "IGameObject.h"
#include "GameObjectFactory.h"
#include "GameController.h"
#include "Coord.h"
#include "IItemInteractable.h"

using namespace std;

#define dbgln(x) std::cout << #x << ": " << (x) << std::endl;

// Purpose: Determine if coordinates are inside the map
bool isInCaveRange(Coord& coord, Cave& cave) {
   if (coord.row < 0 || coord.row >= static_cast<int>(cave.size())) return false;
   if (coord.col < 0 || coord.col >= static_cast<int>(cave[coord.row].size())) return false;
   return true;
}

// Purpose: Print out the cave using the fancy symbols
void printCave(const Cave& cave)
{
   for (const auto& cave_data : cave) {
      for (const auto& cave_cell : cave_data) {
         for (const auto& game_obj : cave_cell.game_objects) {
            // Print first displayable object, then break.
            if (game_obj->isDisplayable()) {
               std::cout << game_obj->getSymbol();
               break;
            }
         }
      }
      std::cout << std::endl;
   }
}

// Purpose: Print out the interactable objects inside the player's cell
void printCellInteractableObj(const Cave& cave) {
   const auto& player_cave_cell = cave[GameController::player->location.row][GameController::player->location.col];
   for (const auto& game_obj_sptr : player_cave_cell.game_objects) {
      const auto& interactable_ptr = dynamic_cast<IItemInteractable*>(game_obj_sptr.get());
      if(interactable_ptr != nullptr){
         cout << interactable_ptr->standingOnItem() << endl;
      }
   }
}

// Purpose: Print player window based on player view distance (WIP) @@@@
void printPlayerView(PlayerWindowCoords& camera_coords, const Cave& cave) {
   //finally here
   cout << "Finally here" << endl;
   for (int row_index{ camera_coords.cave_upper_left.row };row_index < camera_coords.cave_lower_left.row; ++row_index) {
      for (int col_index{ camera_coords.cave_lower_left.col };col_index < camera_coords.cave_lower_right.col; col_index++) {
         for (const auto& game_obj : cave[row_index][col_index].game_objects) {
               if (game_obj->isDisplayable()) {
               std::cout << game_obj->getSymbol();
               break;
            }
         }
      }
      std::cout << std::endl;
   }
}

// Purpose: Print out the cave around the player
PlayerWindowCoords calcCameraRange(const Coord& player_coordinates, const Cave& cave) {
   /*
   {
   // const int GameController::player->view_distance{ GameController::player->view_distance };
   Coord upper_left{ player_coordinates.row - GameController::player->view_distance, player_coordinates.col - GameController::player->view_distance };
   Coord lower_right{ player_coordinates.row + GameController::player->view_distance, player_coordinates.col + GameController::player->view_distance };

   //auto var = PlayerWindowCoords window_coords(player_coordinates);


  //  This code was working yesterday but we had max() and min() in the wrong places
   /*
   lower_right.row = max(lower_right.row, static_cast<int>(cave.size()));
   lower_right.col = max(lower_right.col, static_cast<int>(cave[(lower_right.row)-1].size()));

   upper_left.row = min(upper_left.row, 0);
   upper_left.col = min(upper_left.col, 0);
   

   lower_right.row = min(lower_right.row, static_cast<int>(cave.size() - 1));
   lower_right.col = min(lower_right.col, static_cast<int>(cave[(lower_right.row) - 1].size()));

   //dbgln(lower_right.row);
   //dbgln(lower_right.col);

   upper_left.row = max(upper_left.row, 0);
   upper_left.col = max(upper_left.col, 0);

   //dbgln(upper_left.row);
   //dbgln(upper_left.col);

   Extents extent{};
   extent.height = lower_right.row - upper_left.row;
   extent.width = lower_right.col - upper_left.col;

   //dbgln(extent.height);
   //dbgln(extent.width);

   //auto var = std::make_pair(upper_left, extent);
}
   */
   auto var = PlayerWindowCoords{ player_coordinates };
   return var;

}

// Purpose: Use the CaveData to created objects in the cave
void createCave(const CaveData& cave_data, Cave& cave)
{
   for (const auto& cave_data_row : cave_data)
   {
      cave.emplace_back(); // Create an new empty row for the cave
      for (const auto& cave_data_elem : cave_data_row)
      {
         auto new_tile_smart_ptr = createGameObject(cave_data_elem);
         Cell temp_cell{};
         temp_cell.game_objects.push_back(new_tile_smart_ptr);
         cave.back().push_back(std::move(temp_cell));
      }
   }
}

// Purpose: Create interactable cave objects
void createCaveInteractive(const vector<InteractiveData>& interactive_data_list, Cave& cave) {
   for (const auto& data : interactive_data_list) {
      auto& current_cell = cave[data.row][data.col];
      auto game_object = createGameObject(data.token);
      current_cell.game_objects.push_front(game_object); // 
   }
}

shared_ptr<Player> createPlayer(size_t cave_row, size_t cave_col, Cave& cave) {
   assert(cave_row < cave.size());
   assert(cave_col < cave[cave_row].size());
   auto player = make_shared<Player>(cave_row, cave_col);
   cave[cave_row][cave_col].game_objects.push_front(player);
   return player;
}