#include "GameController.h"

using namespace std;

Cave GameController::cave; // def ctor

shared_ptr<Player> GameController::player; // def ctor

void GameController::resetController() {
   // reset the cave
   GameController::cave.clear(); // Reset game controller
}