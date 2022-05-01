#include "../headers/HeuristicStrategy.hpp"
#include "../headers/Board.hpp"

Heuristic::Heuristic() {}

MisplacedTileHeuristic::MisplacedTileHeuristic() : Heuristic() {}
int MisplacedTileHeuristic::heuristic(const Board* board) const {
    int cnt = 0;
    for (int r = 0; r < board->getMat().size(); r++) {
        for (int i = 0; i < board->getMat().at(0).size(); i++) {
            if (i+1 != board->getMat().at(r).at(i)) { cnt++; }
        }
    }
    return cnt;
}

EuclideanHeuristic::EuclideanHeuristic() : Heuristic() {}
int EuclideanHeuristic::heuristic(const Board* board) const {
    int cnt = 0;
    int meant_x;
    int meant_y;
    int delta_x;
    int delta_y;

    std::vector<std::vector<int>> mat = board->getMat();

    for (int r = 0; r < mat.size(); r++) {
        for (int i = 0; i < mat.at(0).size(); i++) {
            
            // Get where the number is supposed to be
            meant_x = ( (mat.at(r).at(i)-1) % (mat.at(r).size()) );
            meant_y = ( (mat.at(r).at(i)-1) / (mat.at(r).size()) );
            delta_x = std::fabs((i % (mat.at(r).size()) ) - meant_x);
            delta_y = std::fabs((i / (mat.at(r).size()) ) - meant_y);
            
            // Add it to the count
            cnt += (delta_x + delta_y);
        }
    }

    return cnt;
}

UniformCostHeuristic::UniformCostHeuristic() : Heuristic() {}
int UniformCostHeuristic::heuristic(const Board* board) const {
    return 0;
}