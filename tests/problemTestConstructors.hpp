#ifndef __PROBLEMTESTCONST_HPP__
#define __PROBLEMTESTCONST_HPP__

#include "gtest/gtest.h"
#include "../headers/Problem.hpp"

TEST(ProblemTests, testConstructor1) {

    Problem* myProblem = new Problem();

    EXPECT_EQ(myProblem->height(), 1);
    EXPECT_EQ(myProblem->size(), 1);
}

TEST(ProblemTests, testConstructor2) {

    Problem*
}

TEST() {


}

#endif
