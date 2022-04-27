#ifndef __ASTAR_HPP__
#define __ASTAR_HPP__

#include "Board.hpp"

class AStar {

    private:
        bool verbose;
        Board* board;

    public:
        AStar();
        AStar(Board*);

        // Accessors
        bool verbose() const { return this->verbose; }

        // Modifiers
        void verbose(bool);
        void setBoard(Board*); // Optional, to set the board whenever.

};

#endif