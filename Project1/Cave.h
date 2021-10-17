#pragma once
#include <vector>
#include <memory>
#include "AdventureData.h"
#include "Cell.h"

using Cave = std::vector <std::vector <Cell>>;
void printCave(const Cave& cave);
void createCave(const CaveData& cave_data, Cave& cave);

void createCaveInteractive(const std::vector<InteractiveData>& interactive_object_list, Cave& cave);