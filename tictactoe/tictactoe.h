#include <iostream>
#ifndef tictactoe_H
#define tictactoe_H
#include <string>
#include <vector>


class tictactoe{
    public:

        // create empty 3x3 grid
        tictactoe();
    
    
        //print 3x3 grid
        void printGrid();

        bool checkWinner();

        void startGame(int count);

    private:

        std::vector<std::vector<std::string>> grid;
        
    // for pretty printing
      // width of a cell for up to 2 digits
      static const int OUT_WIDTH;
      // roof of a cell
      static const std::string OUT_ROOF; 
      // vertical wall around a cell
      static const char OUT_WALL;
      // show that the grid is empty
      static const char OUT_BLANK;
      // corner of a cell
      static const char OUT_CORNER;

       static void printHorizontalLine(int n);
       void place();
       int turn;
       std::string player;


};
#endif