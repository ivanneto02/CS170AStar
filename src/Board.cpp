#include "Board.hpp"

/*
This function assigns the matrix that A* needs to search through a "game" stage.
*/
void Board::setStage(const vector<vector<uint8_t>>& mat) {

    // Initialize the number of rows
    this->matrix = new vector<vector<uint8_t>>(mat.size());

    // Initialize all of the rows with the values
    for (unsigned int i = 0; i < mat.size(); i++) {

        this->matrix.at(i) = new vector<uint8_t> ( mat.at(i).size() );
    }
}

void Board::clear() {
    cout << "Board::clear() : TODO" << endl;
    return;
}

void Board::draw() {
    cout << "Board::draw() : TODO" << endl;
    return;
}