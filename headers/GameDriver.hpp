#ifndef __GAMEDRIVER_HPP__
#define __GAMEDRIVER_HPP__

// Currently just using C++ STD Queue
#include <queue>
#include <set>
#include "Board.hpp"
#include "Problem.hpp"

/* Comparator to push Board poiters into priority queue */
class Comp {

    public:
        bool operator()(Board* a, Board* b) {
            return ( a->f_valueFrom() ) > ( b->f_valueFrom() );
        }
};

/* Pretty much the AStar class */
class GameDriver {

    private:
        std::priority_queue<Board*, std::vector<Board*>, Comp> frontier;
        std::set<Board*> frontier_set;
        std::set<Board*> explored;
        Board* goal;
        int count;

    public:
        // Constructors
        GameDriver();

        // Control
        Board* graphSearch(Problem*);
        void beginGame();
};

#endif