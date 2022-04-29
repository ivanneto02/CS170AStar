#include "../headers/Problem.hpp"

Problem::Problem() {

    // Default node
    this->root = new Board();
    this->_height = 1;
    this->_size = 1;
}

Problem::Problem(Board* root) {

    this->root = root;
    this->_height = 1;
    this->_size = 1;
}

/*
This function expands a Board node given a board of arbitrary, unique positive
integers, with a zero denoting the "empty" spot.

Assumptions for this function:
    - Single empty spot in entire board
    - Unique positive integers
    - Square n x n board, not n x m (rectangular)
*/
void Problem::expand(Board* node) {

    // Go through every operator, add to children of node.
        // move left, add Board
        // move right, add Board
        // move up, add Board
        // move down, add Board
            
            // ** Make sure to set parent to `node` for each Board*

    // Maybe Board should calculate depth and height in itself.

}