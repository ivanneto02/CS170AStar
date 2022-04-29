#ifndef __PROBLEMTESTHEURISTIC_HPP__
#define __PROBLEMTESTHEURISTIC_HPP__

#include "gtest/gtest.h"
#include "../headers/Problem.hpp"
 
/*
NOTE:

I am not actually going to calculate the heuristic by hand for every testcase
right now as I am not aware of what heuristic to use. So, I am instead going
to stub it out with -999 values in the EXPECT_EQ(left, right) calls.
*/


TEST(ProblemTests, testHeuristic1) {

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 0, 8}};

    Board* root = new Board(mat);
    Problem* myProblem = new Problem(root);

    EXPECT_EQ(myProblem->heuristic(root), 1); // one right
}

TEST(ProblemTests, testHeuristic2) {

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    Board* root = new Board(mat);
    Problem* myProblem = new Problem(root);

    EXPECT_EQ(myProblem->heuristic(root), 0); // don't move
}

TEST(ProblemTests, testHeuristic3) {

    std::vector<std::vector<int>> mat = {{4, 1, 2}, {5, 6, 0}, {7, 8, 3}};

    Board* root = new Board(mat);
    Problem* myProblem = new Problem(root);

    EXPECT_EQ(myProblem->heuristic(root), -999); // ADD ACTUAL HEURISTIC
}

TEST(ProblemTests, testHeuristic4) {

    std::vector<std::vector<int>> mat = {{4, 1, 2}, {0, 8, 6}, {5, 7, 3}};

    Board* root = new Board(mat);
    Problem* myProblem = new Problem(root);

    EXPECT_EQ(myProblem->heuristic(root), -999); // ADD ACTUAL HEURISTIC
}

TEST(ProblemTests, testHeuristic5) {

    std::vector<std::vector<int>> mat = {{1, 8, 2}, {4, 0, 6}, {5, 7, 3}};

    Board* root = new Board(mat);
    Problem* myProblem = new Problem(root);

    EXPECT_EQ(myProblem->heuristic(root), -999); // ADD ACTUAL HEURISTIC
}

TEST(ProblemTests, testHeuristic6) {

    std::vector<std::vector<int>> mat = {{0, 8, 2}, {1, 4, 6}, {5, 7, 3}};

    Board* root = new Board(mat);
    Problem* myProblem = new Problem(root);

    EXPECT_EQ(myProblem->heuristic(root), -999); // ADD ACTUAL HEURISTIC
}

#endif