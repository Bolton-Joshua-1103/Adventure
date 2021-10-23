#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <functional>
#include <cassert>
#include <conio.h>
#include <stdlib.h>

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
#include "Cave.h"
#include "main.h"

// Extended ASCII: http://www.maxi-pedia.com/code+ASCII

using namespace std;
#define dbgln(x) cout << #x << ": " << (x) << endl;

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
   cout << "You pressed: " << key_press << endl;
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

// Purpose: Render all graphics to the console
void renderGame() {

   system("CLS");
   printCave(GameController::cave);
}

void initializeGame() {
   // 
   GameController::resetController();
   createCave(AdventureData::troll_cave_data, GameController::cave); // init
   createCaveInteractive(AdventureData::interactive_troll_cave_data, GameController::cave); //init
   GameController::player = createPlayer(AdventureData::playerStartingRow, AdventureData::playerStartingCol, GameController::cave);
}

// Purpose: Determine if coordinates are inside the map
bool isInCaveRange(Coord& coord, Cave& cave) {
   if (coord.row < 0 || coord.row >= cave.size()) return false;
   if (coord.col < 0 || coord.col >= cave[coord.row].size()) return false;
   return true;
}


void movePlayer(const Coord& delta)
{
   auto& player = GameController::player;
   auto& old_cell = GameController::cave[player->row][player->col];
   Coord new_player_coord{ (player->row + delta.row), player->col + delta.col };
   if (isInCaveRange(new_player_coord, GameController::cave)) {
      player->row += delta.row;
      player->col += delta.col;// We will need to validate this to the correct cave range

      auto& new_cell = GameController::cave[player->row][player->col];

      old_cell.game_objects.pop_front(); // need to maek sure we're popping the player (pop_front may not be the correct functino) or validation
      new_cell.game_objects.push_front(player);
   }

}

bool playGame() {
   bool done{ false };// Determine if we are replaying

   initializeGame();

   AdventureData::printCaveData(AdventureData::troll_cave_data);  // Debugging: print cave data

   while (!done) {
      renderGame();

      cout << "Enter play command" << endl;
      auto cmd = getCmd();

      switch (cmd)
      {

      case CommandType::MoveUp:
      {
         cout << "Move player up" << endl;     
         movePlayer(Coord{-1,0});
      }
      break;

      case CommandType::MoveDown:
      {
         cout << "Move player down" << endl;
         movePlayer(Coord{ 1,0 });
      }
      break;

      case CommandType::MoveLeft:
      {
         cout << "Move player Left" << endl;
         movePlayer(Coord{ 0,-1 });
      }
      break;

      case CommandType::MoveRight:
      {
         cout << "Move player Right" << endl;
         movePlayer(Coord{ 0,1 });
      }
      break;

      case CommandType::ExitGame:
      {
         cout << "Exiting Game" << endl;
         done = true;
      }
      break;

      default:
      {
      }
         break;
      }
   }
   cout << "Do you want to play again (y/n)? ";
   bool play_again = ((char)_getch() == 'y') ? true : false;
   cout << endl;

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

