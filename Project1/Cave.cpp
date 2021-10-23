#include <iostream>
#include <cassert>
#include "Cave.h"
#include "AdventureData.h"
#include "IGameObject.h"
#include "GameObjectFactory.h"


using namespace std;
// Purpose: Print out the cave using the fancy symbols
void printCave(const Cave& cave)
{
   for (const auto& cave_data : cave) {
      for (const auto& cave_cell : cave_data) {
         for (const auto& game_obj : cave_cell.game_objects) {
            // Print first displayable object, then break.
            if (game_obj->isDisplayable()) {
               cout << game_obj->getSymbol();
               break;
            }
         }
         //cout << cave_elem->getSymbol();
      }
      cout << endl;
   }
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