#pragma once
#include <vector>
#include <string>

using CaveData = std::vector<std::string>;

class AdventureData
{
public:
   static const CaveData troll_cave_data; // Declaration
   static void printCaveData(const CaveData& cave_data);

   static const char ErrorTileChar = '!';
};