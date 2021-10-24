#pragma once
#include <vector>
#include <memory>
#include "AdventureData.h"
#include "PlayerWindowCoords.h"
#include "Cell.h"
#include "Player.h"

using Cave = std::vector <std::vector <Cell>>;

void printCave(const Cave& cave);
void printPlayerView(PlayerWindowCoords& camera_coords, const Cave& cave);
void createCave(const CaveData& cave_data, Cave& cave);
bool isInCaveRange(Coord& coord, Cave& cave);

void createCaveInteractive(const std::vector<InteractiveData>& interactive_object_list, Cave& cave);
std::shared_ptr<Player> createPlayer(size_t cave_row, size_t cave_col, Cave& cave);
PlayerWindowCoords calcCameraRange(const Coord& player_coordinates, const Cave& cave);