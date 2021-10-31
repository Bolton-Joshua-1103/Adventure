#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <functional>
#include <cassert>
#include <conio.h>
#include <stdlib.h>
#include <cassert>

#include "IGameObject.h"
#include "Colors.h"
#include "Coord.h"

#include "Tile.h"
#include "OpenTile.h"
#include "ErrorTile.h"
#include "TrashTile.h"
#include "StoneTile.h"
#include "WaterTile.h"

#include "AdventureData.h"
#include "GameController.h"
#include "PlayerWindowCoords.h"
#include "Cave.h"
#include "main.h"

// Extstd::endled ASCII: http://www.maxi-pedia.com/code+ASCII

using namespace std;
#define dbgln(x) std::cout << #x << ": " << (x) << std::endl;

enum class CommandType {
   NoCommand = 0,
   MoveUp,
   MoveDown,
   MoveRight,
   MoveLeft,
   MoveUpRight,
   MoveUpLeft,
   MoveDownRight,
   MoveDownLeft,
   PickUp,
   ExitGame,
};

CommandType getCmd() {
   auto cmd = CommandType::NoCommand;

   auto key_press = _getch();
   std::cout << "You pressed: " << key_press << std::endl;
   switch (key_press) {
   case '8': {cmd = CommandType::MoveUp; } break;
   case '2': {cmd = CommandType::MoveDown; } break;
   case '4': {cmd = CommandType::MoveLeft; } break;
   case '6': {cmd = CommandType::MoveRight; } break;
   case '5': {cmd = CommandType::PickUp; } break;
   default:
      break;
   }

   return cmd;
}

// Purpose: Print Player Inventory to screen
void printPlayerInventory(const Player& player) {
   cout << "Inventory: ";
   for (const auto& item : player.inventory) {
      cout << item.second->getName() << " ";
   }
   cout << endl;
}
// Purpose: Rstd::endler all graphics to the console
void renderGame() {
   system("CLS");
   printCave(GameController::cave);
   printCellInteractableObj(GameController::cave);
   printPlayerInventory(*GameController::player);
}

void initializeGame() {
   // 
   GameController::resetController();
   createCave(AdventureData::troll_cave_data, GameController::cave); // init
   createCaveInteractive(AdventureData::interactive_troll_cave_data, GameController::cave); //init
   GameController::player = createPlayer(AdventureData::playerStartingRow, AdventureData::playerStartingCol, GameController::cave);
}

void movePlayer(const Coord& delta)
{
   auto& player = GameController::player;
   auto& old_cell = GameController::cave[player->location.row][player->location.col];
   Coord new_player_coord{ (player->location.row + delta.row), player->location.col + delta.col };
   if (isInCaveRange(new_player_coord, GameController::cave)) {

      auto& new_cell = GameController::cave[new_player_coord.row][new_player_coord.col];
      if (new_cell.canPlayerEnter()) {

         player->location.row += delta.row;
         player->location.col += delta.col;

         assert(old_cell.game_objects.front() != nullptr); // make sure there is something in the front of the cell dequeue
         assert(dynamic_cast<Player*>(old_cell.game_objects.front().get()) != nullptr); // Checking to see if this is a player (or can be evaluated to a player via an inheritance relationship)
         old_cell.game_objects.pop_front(); // need to maek sure we're popping the player (pop_front may not be the correct functino) or validation
         new_cell.game_objects.push_front(player);
      }
   }
}

// Purpose: Removes an item from the cell deque and adds it to the players inventory
// The player must be in the cell they wish to pick up the item from. (as we're removing from the cell the player is in)
void pickUpItem() {
   auto& player_cave_cell = GameController::cave[GameController::player->location.row][GameController::player->location.col];

   auto erased2 = std::erase_if(player_cave_cell.game_objects, [&](const auto& gameobject) {

      bool erase{ false };
      const auto& interactable_ptr = dynamic_cast<IItemInteractable*>(gameobject.get());
      if (interactable_ptr != nullptr) {
         // castable(it is interactable)
         erase = true;

         std::shared_ptr<IItemInteractable>tmp_ptr = std::dynamic_pointer_cast<IItemInteractable>(gameobject);//Converting to the correct pointer type (IItemInteractable) for player.inventory(map<string,IItemInteractable>)
         GameController::player->inventory.insert({ interactable_ptr->getName(), tmp_ptr }); // Inserted into player inventory
      }
      return erase;
      });
}

bool playGame() {
   bool done{ false };// Determine if we are replaying

   initializeGame();

   AdventureData::printCaveData(AdventureData::troll_cave_data);  // Debugging: print cave data

   while (!done) {
      renderGame();
      PlayerWindowCoords cameraCoord = calcCameraRange(GameController::player->location, GameController::cave);// @@@ Crashing our program :D
      printPlayerView(cameraCoord, GameController::cave);
      std::cout << "Enter play command" << std::endl;
      auto cmd = getCmd();

      switch (cmd)
      {
      case CommandType::PickUp:
      {
         pickUpItem();
      }
      break;

      case CommandType::MoveUp:
      {
         std::cout << "Move player up" << std::endl;
         movePlayer(Coord{ -1,0 });
      }
      break;

      case CommandType::MoveDown:
      {
         std::cout << "Move player down" << std::endl;
         movePlayer(Coord{ 1,0 });
      }
      break;

      case CommandType::MoveLeft:
      {
         std::cout << "Move player Left" << std::endl;
         movePlayer(Coord{ 0,-1 });
      }
      break;

      case CommandType::MoveRight:
      {
         std::cout << "Move player Right" << std::endl;
         movePlayer(Coord{ 0,1 });
      }
      break;

      case CommandType::ExitGame:
      {
         std::cout << "Exiting Game" << std::endl;
         done = true;
      }
      break;

      default:
      {
      }
      break;
      }
   }
   std::cout << "Do you want to play again (y/n)? ";
   bool play_again = ((char)_getch() == 'y') ? true : false;
   std::cout << std::endl;

   return play_again;

}

// Purpose: The main 
int main()
{
   bool playing = true;

   while (playing) {
      bool replay = playGame(); // enter the main game loop
      playing = replay; // Check to see if we are going to replay
   }
}

