#include "Cell.h"

using namespace std;

bool Cell::canPlayerEnter() {
   for (const auto& obj : game_objects) {
      if (obj->isSolid()) {
         return false;
      }
   }
   return true;
}