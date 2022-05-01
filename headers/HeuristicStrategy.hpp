#ifndef __HEURISTIC_STRATEGY_HPP__
#define __HEURISTIC_STRATEGY_HPP__

#include "Board.hpp"
#include <cmath>

class Heuristic {

    private:
        int _heuristic;
        Board* board;

    public:
        Heuristic(Board* board) { this->board = board; }
        virtual int heuristic() const = 0;
};

class MisplacedTileHeuristic {

    public:
        MisplacedTileHeuristic(Board* board) : Heuristic(board) {}

        virtual int heuristic() const {
            int cnt = 0;
            for (int r = 0; r < this->board->getMat().size(); r++) {
                for (int i = 0; i < this->board->getMat().at(0).size(); i++) {
                    if (i+1 != this->board->getMat().at(r).at(i)) { cnt++; }
                }
            }
            return cnt;
        }
};

class EuclideanHeuristic {

    public:
        EuclideanHeuristic(Board* board) : Heuristic(board) {}

        virtual int heuristic() const {
            int cnt = 0;
            int meant_x;
            int meant_y;
            int delta_x;
            int delta_y;

            std::vector<std::vector<int>> mat = this->board->getMat();

            for (int r = 0; r < mat.size(); r++) {
                for (int i = 0; i < mat.at(0).size(); i++) {
                    
                    // Get where the number is supposed to be
                    meant_x = ( (mat.at(r).at(c)-1) % (mat.at(r).size()) );
                    meant_y = ( (mat.at(r).at(c)-1) / (mat.at(r).size()) );
                    delta_x = std::fabs((i % (mat.at(r).size()) ) - meant_x);
                    delta_y = std::fabs((i / (mat.at(r).size()) ) - meant_y);
                    
                    // Add it to the count
                    cnt += (delta_x + delta_y);
                }
            }

            return cnt;
        }

};

class UniformCostHeuristic {

    public:
        UniformCostHeuristic(Board* board) : Heuristic(board) {}

        virtual int heuristic() const {

            return 0;
        }
};

#endif