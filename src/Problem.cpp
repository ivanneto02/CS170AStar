#include "../headers/Problem.hpp"

Problem::Problem() {

    // Default node
    this->root = new Board();
    this->_height = 1;
    this->_size = 1;
    this->_heuristic = 1;
    root->setHeuristic(this->heuristicOf(root));
}

Problem::Problem(Board* root) {

    this->root = root;
    this->_height = 1;
    this->_size = 1;
    this->_heuristic = 1;
    root->setHeuristic(this->heuristicOf(root));
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
    
    // expand the node
    node->expand();

    for (int i = 0; i < 4; i++) {
        node->getChild(i)->setParent(node);
        node->getChild(i)->setDepth(node->getDepth() + 1);
        node->getChild(i)->setCost(node->getCost() + 1);
        node->setHeuristic(this->heuristicOf(node));
    }
}

int Problem::depthOf(Board* board) const {
    return board->getDepth();
}

int Problem::heightOf(Board* board) const {
    return -999;
}

int Problem::heuristicOf(Board* board) const {

    switch (this->_heuristic) {

        case 1:
            return board->noHeuristic();
            break;

        case 2:
            return board->misplacedHeuristic();
            break;

        case 3:
            return board->euclideanHeuristic();
            break;

        default:
            return board->noHeuristic();
            break;
    }
    
}