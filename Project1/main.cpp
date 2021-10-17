#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <functional>
#include <cassert>

#include "IGameObject.h"
#include "Colors.h"

#include "Tile.h"
#include "OpenTile.h"
#include "ErrorTile.h"
#include "TrashTile.h"
#include "StoneTile.h"
#include "WaterTile.h"

#include "AdventureData.h"
#include "Cave.h"

// Extended ASCII: http://www.maxi-pedia.com/code+ASCII

using namespace std;
#define dbgln(x) cout << #x << ": " << (x) << endl;

// Purpose: The main 
int main()
{
   AdventureData::printCaveData(AdventureData::troll_cave_data);  // Debugging: print cave data

   Cave cave;
   createCave(AdventureData::troll_cave_data, cave);
   createCaveInteractive(AdventureData::interactive_troll_cave_data, cave);

   cout << endl << endl << endl;
   cout << "================================================" << endl;
   printCave(cave);
   //dbgln(cave[1][0]->getSymbol());
}

