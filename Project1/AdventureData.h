#pragma once
#include <vector>
#include <string>

using CaveData = std::vector<std::string>;
//using InteractiveData = std::vector<char>;
struct InteractiveData {
   int row{};
   int col{};
   char token{'!'};
};

class AdventureData
{
public:
   static const CaveData troll_cave_data; // Declaration
   static const std::vector<InteractiveData> interactive_troll_cave_data;
   static void printCaveData(const CaveData& cave_data);
   static const size_t playerStartingRow{ 18 };
   static const size_t playerStartingCol { 18 };
   static const char ErrorTileChar = '!';
};