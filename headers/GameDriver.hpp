#ifndef __GAMEDRIVER_HPP__
#define __GAMEDRIVER_HPP__

// Currently just using C++ STD Queue
#include <queue>
#include <set>
#include "Board.hpp"
#include "Problem.hpp"

class GameDriver {

    private:
        std::queue<Board*> frontier;
        std::set<Board*> explored;

    public:

        Board* graphSearch(Problem*);
};

#endif