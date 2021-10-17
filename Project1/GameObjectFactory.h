#pragma once
#include <memory>
#include "IGameObject.h"

std::shared_ptr<IGameObject> createGameObject(char object_type_char);