#ifndef __PROBLEM_HPP__
#define __PROBLEM_HPP__

#include "Board.hpp"

class Problem {

    private:
        Board* root;
        int _height;
        int _size;

    public:
        // Constructors
        Problem();
        Problem(Board*);

        // Accessors
        int height()  const { return this->_height; }
        int size() const { return this->_size; }
        
        int depthOf(Board*) const;
        int heightOf(Board*) const;
        int misplacedHeuristic(Board*) const;
        int euclideanHeuristic(Board*) const;

        Board* getRoot() const { return this->root; }

        // Modifiers
        void expand(Board*);
};

#endif