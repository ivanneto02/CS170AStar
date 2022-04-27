#ifndef __BOARD_TEST_SETSTAGE_HPP
#define __BOARD_TEST_SETSTAGE_HPP

#include <sstream>
#include "gtest/gtest.h"
#include "../headers/Board.hpp"

TEST(BoardTest, testSetStage1) {

    int w = 3;
    int h = 3;

    std::vector<std::vector<int>> origMat(h);
    for (int r = 0; r < origMat.size(); r++) { // Iterate through rows
        origMat.at(r) = std::vector<int>(w);
        for (int i = 0; i < origMat.at(0).size(); i++) { // Fill up row
            origMat.at(r).at(i) = 0;
        }
    }

    Board newBoard = Board();
    newBoard.setStage(origMat);

    std::ostringstream output;
    std::ostringstream compare;

    // Fill up compare string
    for (int i = 0; i < w; i++) {
       compare << "- "; 
    }
    compare << "\n";
    // For every row...
    for (int r = 0; r < h; r++) {
        // For every item in each row...
        for (int i = 0; i < w; i++) {
            compare << origMat.at(r).at(i) << " ";
        }
        compare << "\n";
    }
    for (int i = 0; i < w; i++) {
       compare << "- "; 
    }
    compare << "\n";

    std::vector<std::vector<int>> mat = newBoard.getMat();

    // Fill up Board string
    for (int i = 0; i < newBoard.getWidth(); i++) {
       output << "- "; 
    }
    output << "\n";
    // For every row...
    for (int r = 0; r < newBoard.getLength(); r++) {
        // For every item in each row...
        for (int i = 0; i < newBoard.getWidth(); i++) {
            output << mat.at(r).at(i) << " ";
        }
        output << "\n";
    }
    for (int i = 0; i < newBoard.getWidth(); i++) {
       output << "- "; 
    }
    output << "\n";

    EXPECT_EQ(compare.str(), output.str());
}

TEST(BoardTest, testSetStage2) {

    EXPECT_EQ(1, 1);
}

TEST(BoardTest, testSetStage3) {

    EXPECT_EQ(1, 1);
}

TEST(BoardTest, testSetStage4) {

    EXPECT_EQ(1, 1);
}

#endif