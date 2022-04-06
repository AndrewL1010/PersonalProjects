#include "tictactoe.h"
#include <string>
#include <iostream>
#include <iomanip>

const int tictactoe::OUT_WIDTH = 2;
// output that the position is empty
const char tictactoe::OUT_BLANK = ' ';
// should be as long as WIDTH + 1
const std::string tictactoe::OUT_ROOF = "---"; 
// output a wall around the number
const char tictactoe::OUT_WALL = '|';
// corner of a number
const char tictactoe::OUT_CORNER = '+';
tictactoe::tictactoe(){
    grid =  {{"  ", "  ", "  "},
            {"  ", "  ", "  "},
            {"  ", "  ", "  "}};
    turn = 0;
    player = "X";
}
void tictactoe::printHorizontalLine(int n) {
   std::cout << OUT_CORNER;
   for (int i = 0; i < n; i++)  {
      std::cout << OUT_ROOF << OUT_CORNER;
   }
   std::cout << std::endl;
}
void tictactoe::printGrid(){
   // print a top line
   printHorizontalLine(3);
   for (int i = 0; i < 3; i++) {
      std::cout << OUT_WALL;
      for (int j = 0; j < 3; j++) {
         std::cout << std::setw(tictactoe::OUT_WIDTH);
         if(grid[i][j] != "       "){
            std::cout << grid[i][j];
        }
         

         std::cout << OUT_BLANK << OUT_WALL;
      } // for j
      std::cout << std::endl;
      printHorizontalLine(3);
   } // for i
   std::cout << std::endl;
}
bool tictactoe::checkWinner(){
    if(grid[0][0] == player && grid[0][1] == player && grid[0][2] == player){
        return true;
    }
    else if(grid[1][0] == player && grid[1][1] == player && grid[1][2] == player){
        return true;
    }
    else if(grid[2][0] == player && grid[2][1] == player && grid[2][2] == player){
        return true;
    }
    else if(grid[0][0] == player && grid[1][0] == player && grid[2][0] == player){
        return true;
    }
    else if(grid[0][1] == player && grid[1][1] == player && grid[2][1] == player){
        return true;
    }
    else if(grid[0][2] == player && grid[1][2] == player && grid[2][2] == player){
        return true;
    }
    else if(grid[0][0] == player && grid[1][1] == player && grid[2][2] == player){
        return true;
    }
    else if(grid[0][2] == player && grid[1][1] == player && grid[2][0] == player){
        return true;
    }
    return false;
}
void tictactoe::place(){
    if(turn%2 == 0){
        player = "X";
    }
    else{
        player = "O";
    }
    int row = -1;
    int col = -1;

    std::cout << "It is player " << player << "'s turn\n";

    while((row < 1 || row > 3) && (col < 1 || col > 3)){
        std::cout << "Please choose a valid spot\n";
        std::cout << "Choose a row\n";
        std::cin >> row;
        std::cout << "choose a column\n";
        std::cin >> col;
    }
    if(grid[row-1][col-1] == "  "){
        std::string letter;
        if(player == "X"){
            grid[row-1][col-1] = "X";
        }
        else{
            grid[row-1][col-1] = "O";
        }
        
    }
    turn++;
    printGrid();
}
void tictactoe::startGame(int count){
    int start = 0;
    while(start < 9){
        place();
        if(checkWinner()){
            std::cout << "THE WINNER IS PLAYER " + player + "\n";
            break;
        }
        start++;
    }
    if(start == 8){
        std::cout << "Unfortunately, there was no winner\n";
    }

}
int main(){

    tictactoe game = tictactoe();

    int count = 0;
    game.printGrid();
    game.startGame(count);
    





}
