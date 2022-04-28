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

        int depth;

        // Keep track of parent node
        Board* parent;

        // Children nodes
        std::vector<std::vector<Board*>> children;

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
        Board* getChild(int) const;

        // Functionality
        void setStage(const std::vector<std::vector<int>>);
        void clear();
        void draw(std::ostream&);
        void setParent(Board* parent) { this->parent = parent; }
        void expand();
};

#endif