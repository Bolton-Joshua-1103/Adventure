#pragma once
#include <iostream>
#include <memory>

#include "Cave.h"
#include "AdventureData.h"
#include "Player.h"
#include "Cell.h"

//using Cave = std::vector <std::vector <Cell>>;

class GameController {
public:
   static Cave cave;
   static void resetController();
   static std::shared_ptr<Player> player;
};