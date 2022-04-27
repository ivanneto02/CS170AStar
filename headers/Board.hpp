#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <iostream>
#include <vector>
#include <ostream>

class Board {
    /* This class acts as a "node" class */

    private:
        // Variables
        int width;
        int length;
        int area;
        std::vector<std::vector<int>> matrix;

    public:
        // Constructors
        Board();
        Board(int, int);
        Board(std::vector<std::vector<int>>);

        // Common functions
        int getArea() const { return this->area; }
        int getWidth() const { return this->width; }
        int getLength() const { return this->length; }
        std::vector<std::vector<int>> getMat() const { return this->matrix; }

        // Functionality
        void setStage(const std::vector<std::vector<int>>);
        void clear();
        void draw(std::ostream&);
};

#endif