#pragma once
#include <deque>
#include <memory>
#include "IGameObject.h"

class Cell {
public:
   std::deque<std::shared_ptr<IGameObject>> game_objects;
   bool canPlayerEnter();

};