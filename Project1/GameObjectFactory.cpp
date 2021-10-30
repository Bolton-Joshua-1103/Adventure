#include "GameObjectFactory.h"
#include "AdventureData.h"

#include "StoneTile.h"
#include "TrashTile.h"
#include "OpenTile.h"
#include "WaterTile.h"
#include "ErrorTile.h"
#include "GrassTile.h"
#include "Sword.h"
#include "Troll.h"

using namespace std;

// Purpose: Create the concrete game object give an object char that identifies the type of object to create
// type erasure - using inheritted aspects (usually interfaces) to control objects of different types at the same time.
std::shared_ptr<IGameObject> createGameObject(char object_type_char) {
   const auto& ErrorTileChar = AdventureData::ErrorTileChar;
   switch (object_type_char)
   {
   case '*':            return make_shared<StoneTile>();
   case 'X':            return make_shared<TrashTile>();
   case ' ':            return make_shared<OpenTile>();
   case 'w':            return make_shared<WaterTile>();
   case 'g':            return make_shared<GrassTile>();
   case ErrorTileChar:  return make_shared<ErrorTile>();
   case 's':            return make_shared<Sword>();
   case 'T':            return make_shared<Troll>();
//   case 'P':            return make_shared<Player>();
   default:             return make_shared<ErrorTile>(); // Make an ErrorTile by default
   }
}