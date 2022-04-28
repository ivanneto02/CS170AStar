#ifndef __PROBLEMTESTEXPAND_HPP__
#define __PROBLEMTESTEXPAND_HPP__

#include "gtest/gtest.h"
#include "../headers/Problem.hpp"
#include <sstream>

TEST(ProblemTests, testExpand1) {
    /* Specific for 8 puzzle, will add more cases later. */

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    Board* root = 
    new Board(mat);

    Problem* myProblem = new Problem(root);

    myProblem->expand(root);

    std::ostringstream out;
    std::string compare;
    
    // MOVING LEFT
    compare = "- - - \n1 2 3 \n 4 5 6 \n7 0 8 \n- - - \n";
    root->getChild(0)->draw(out);
    EXPECT_EQ(out.str(), compare);
    out.clear();

    // MOVING RIGHT
    compare = "- - - \n1 2 3 \n 4 5 6 \n0 8 7 \n- - - \n";
    root->getChild(1)->draw(out);
    EXPECT_EQ(out.str(), compare);
    out.clear();

    // MOVING UP
    compare = "- - - \n1 2 3 \n 4 5 0 \n7 8 6 \n- - - \n";
    root->getChild(2)->draw(out);
    EXPECT_EQ(out.str(), compare);
    out.clear();

    // MOVING DOWN
    compare = "- - - \n1 2 0 \n 4 5 6 \n7 8 3 \n- - - \n";
    root->getChild(3)->draw(out);
    EXPECT_EQ(out.str(), compare);
    out.clear();
}

#endif