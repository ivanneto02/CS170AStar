#include "../headers/Board.hpp"

// Constructors
Board::Board() {
    this->width = 3;
    this->length = 3;
    this->area = this->width * this->length;
    
    this->matrix = std::vector<std::vector<int>>(this->length);

    // Initialize every item to 0.
    // For every row
    for (int r = 0; r < this->length; r++) {
        this->matrix.at(r) = std::vector<int>(this->width);
        // For every item in each row...
        for (int i = 0; i < this->width; i++) {
            this->matrix.at(r).at(i) = 0;
        }
    }
}

Board::Board(int w, int l) {
    this->width = w;
    this->length = l;
    this->area = this->width * this->length;
    
    this->matrix = std::vector<std::vector<int>>(this->length);

    // Initialize every item to 0.
    // For every row
    for (int r = 0; r < this->length; r++) {
        this->matrix.at(r) = std::vector<int>(this->width);
        // For every item in each row...
        for (int i = 0; i < this->width; i++) {
            this->matrix.at(r).at(i) = 0;
        }
    }
}

Board::Board(std::vector<std::vector<int>> mat) {

    this->width = mat.at(0).size();
    this->length = mat.size();
    this->area = this->width * this->length;
    
    this->matrix = std::vector<std::vector<int>>(this->length);

    // Initialize every item to item value.
    // For every row
    for (int r = 0; r < this->length; r++) {
        this->matrix.at(r) = std::vector<int>(this->width);
        // For every item in each row...
        for (int i = 0; i < this->width; i++) {
            this->matrix.at(r).at(i) = mat.at(r).at(i);
        }
    }
}
// Endof constructors

/*
This function assigns the matrix that A* needs to search through a "game" stage.
*/
void Board::setStage(const std::vector<std::vector<int>> mat) {

    // Clear previous matrix
    this->matrix.clear();

    // Set matrix
    this->matrix = std::vector<std::vector<int>>(mat.size());

    // Set new board parameters
    this->width = mat.at(0).size();
    this->length = mat.size();
    this->area = this->width * this->length;

    // Initialize every item to item value.
    // For every row
    for (int r = 0; r < mat.size(); r++) {
        this->matrix.at(r) = std::vector<int>(this->width);
        // For every item in each row...
        for (int i = 0; i < mat.at(0).size(); i++) {
            this->matrix.at(r).at(i) = mat.at(r).at(i);
        }
    }
}

// Clears the board in Board object
void Board::clear() {
    // For every row
    for (int r = 0; r < this->matrix.size(); r++) {
        // For every item in each row...
        for (int i = 0; i < this->matrix.at(r).size(); i++) {

            this->matrix.at(r).at(i) = 0;
        }
    }
}

// Draws the board to out ostream
void Board::draw(std::ostream& out) {
    for (int i = 0; i < this->width; i++) { out << "-" << " "; }
    out << "\n";

    // For every row...
    for (int r = 0; r < this->matrix.size(); r++) {

        // For every item in row
        for (int i = 0; i < this->matrix.at(r).size(); i++) {
            out << matrix.at(r).at(i) << " ";
        }
        out << "\n";
    }

    for (int i = 0; i < this->width; i++) { out << "-" << " "; }
    out << "\n";
}