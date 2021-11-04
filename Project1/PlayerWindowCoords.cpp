#include "PlayerWindowCoords.h"
#include "GameController.h"


void PlayerWindowCoords::printWindowCoords() {
   std::cout << "Upper_left(row,col): (" << upper_left.row << "," << upper_left.col << ")." << std::endl;
   std::cout << "Upper_right(row,col): (" << upper_right.row << "," << upper_right.col << ")." << std::endl;
   std::cout << "Lower_left(row,col): (" << lower_left.row << "," << lower_left.col << ")." << std::endl;
   std::cout << "Lower_right(row,col): (" << lower_right.row << "," << lower_right.col << ")." << std::endl;
   std::cout << "Row Delta: (" << row_delta << ")." << std::endl;
   std::cout << "Col Delta: (" << col_delta << ")." << std::endl;
}

void PlayerWindowCoords::printCaveWindowCoords() {
   std::cout << "Cave Upper_left(row,col): (" << cave_upper_left.row << "," << cave_upper_left.col << ")." << std::endl;
   std::cout << "Cave Upper_right(row,col): (" << cave_upper_right.row << "," << cave_upper_right.col << ")." << std::endl;
   std::cout << "Cave Lower_left(row,col): (" << cave_lower_left.row << "," << cave_lower_left.col << ")." << std::endl;
   std::cout << "Cave Lower_right(row,col): (" << cave_lower_right.row << "," << cave_lower_right.col << ")." << std::endl;
}

void PlayerWindowCoords::calcWindowCoords(const Coord& location) {
   upper_left = Coord{ location.row - GameController::player->view_distance, location.col - (GameController::player->view_distance) };
   upper_right = Coord{ location.row - GameController::player->view_distance, location.col + ( GameController::player->view_distance) };
   lower_left = Coord{ location.row + GameController::player->view_distance, location.col - (GameController::player->view_distance) };
   lower_right = Coord{ location.row + GameController::player->view_distance, location.col + (GameController::player->view_distance) };
}

PlayerWindowCoords::PlayerWindowCoords(const Coord& location) : upper_left{ location.row - GameController::player->view_distance, location.col - GameController::player->view_distance },
upper_right{ location.row - GameController::player->view_distance, location.col + GameController::player->view_distance },
lower_left{ location.row + GameController::player->view_distance, location.col - GameController::player->view_distance },
lower_right{ location.row + GameController::player->view_distance, location.col + GameController::player->view_distance }, player_view_distance{ 5 }
{
   if (upper_left.row < 0 || lower_right.row >= static_cast<int>(GameController::cave.size())) {
      row_delta = (upper_left.row < 0) ? upper_left.row : abs(static_cast<int>(GameController::cave.size()) - (lower_right.row));
   }
   else { row_delta = 0; }
   if (upper_left.col < 0 || lower_right.col >= static_cast<int>(GameController::cave[location.row].size())) {
      col_delta = (upper_left.col < 0) ? (upper_left.col) : abs(static_cast<int>(GameController::cave[location.row].size()) - (lower_right.col));
   }
   else { col_delta = 0; }

   cave_upper_left = Coord{ upper_left.row - row_delta, upper_left.col - col_delta }; //These should always be inside the cave vector parameters
   cave_upper_right = Coord{ upper_right.row - row_delta, upper_right.col - col_delta };

   cave_lower_left = Coord{ lower_left.row - row_delta, lower_left.col - col_delta };
   cave_lower_right = Coord{ lower_right.row - row_delta, lower_right.col - col_delta };

   printWindowCoords();
   std::cout << std::endl;
   printCaveWindowCoords();
}