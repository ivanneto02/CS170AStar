#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <iostream>

using namespace std;

class Board {

    private:
        // Variables
        uint16_t width;
        uint16_t length;
        uint16_t area;
        vector<vector<uint8_t>> matrix;

    public:
        // Constructors
        Board() { width = 200; length = 200; area = width*length; }
        Board(uint16_t w, uint16_t l) : width(w), length(l), area(w*l) {}

        // Common functions
        uint16_t area() const { return this->area; }
        uint16_t width() const { return this->width; }
        uint16_t length() const { return this->length; }

        // Functionality
        void setStage(const vector<vector<uint8_t>>&);
        void clear();
        void draw();
        
};

#endif