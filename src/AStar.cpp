#include "AStar.hpp"

AStar::AStar() {

    cout << "AStar::Constructor() : TODO" << endl;
}

AStar::AStar(Board*) {
    
    cout << "AStar::Constructor(Board*) : TODO" << endl;
}

// Modifiers
void verbose(bool val) {

    this->verbose = val;
}

void setBoard(Board* board) {

    this->Board = board;
}

