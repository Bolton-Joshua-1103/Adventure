#pragma once
#include <vector>
#include <memory>
#include "IGameObject.h"

class Cell {
public:
   std::vector<std::shared_ptr<IGameObject>> game_objects;

};