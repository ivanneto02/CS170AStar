#include "../headers/GameDriver.hpp"

GameDriver::GameDriver() {
    this->goal = nullptr;
    this->count = 0;
}

/* Can run AStar and Uniform Cost Search */
Board* GameDriver::graphSearch(Problem* problem) {

    // Initialize the frontier using the initial state of problem
    this->frontier.push(problem->getRoot());
    this->frontier_set.insert(problem->getRoot());

    // loop do
    // while (true) {
    while (true) {

        // If frontier is empty, then return failure
        if (this->frontier.size() == 0) { return nullptr; }

        // Pick the smallest leaf, based on AStar
        Board* leaf = this->frontier.top();

        // std::cout << "REMOVING" << std::endl;
        // leaf->draw(std::cout);
        // std::cout << "FROM FRONTIER PRIORITY QUEUE" << std::endl;

        // std::cout << "AND" << std::endl;
        // this->frontier.top()->draw(std::cout);
        // std::cout << "FROM QUEUE SET" << std::endl;

        // // Print out the frontier set
        // std::cout << "\nPrinting frontier: {";
        // for (std::set<Board*>::iterator it = this->frontier_set.begin(); it != this->frontier_set.end(); it++) {
        //     std::cout << (*it)->f_valueFrom() << " ";
        // }
        // std::cout << "} size: " <<  this->frontier_set.size() << std::endl;

        this->frontier.pop();
        this->frontier_set.erase(leaf);

        // std::cout << "PQUEUE_SIZE: " << this->frontier.size() << std::endl;
        // std::cout << "SQUEUE_SIZE: " << this->frontier_set.size() << std::endl;

        // for (std::set<Board*>::iterator it = this->frontier_set.begin(); it != this->frontier_set.end(); it++) {
        //     if ( *(*it) == (*leaf)) {
        //         std::cout << "Trying to remove " << (*it)->f_valueFrom() << std::endl;
        //         this->frontier_set.erase(*it);
        //     }
        // }

        // If leaf is the goal, return it
        if ((*(this->goal) == *leaf)) { 
            return leaf;
        } // Overloaded==

        // Add to explored set if not
        this->explored.insert(leaf);

        // If not in explored, expand
        std::cout << "=================================================\nCurrent expanding node with g(n) = " << leaf->getCost() << " and h(n) = " << problem->heuristicOf(leaf) << "\n";
        leaf->draw(std::cout);
        problem->expand(leaf);
        this->count++;
        std::cout << "Expanding node...\n\n";

        // Add the children to the frontier if not there or in explored
        for (int i = 0; i < 4; i++) {

            // std::cout << "Currently trying..." << std::endl;
            // leaf->getChild(i)->draw(std::cout);

            // Child is not in frontier
            bool in_frontier = false;
            for (std::set<Board*>::iterator it = this->frontier_set.begin(); it != this->frontier_set.end(); it++) {
                if (*(*it) == *(leaf->getChild(i))) {
                    in_frontier = true;
                    break;
                }
            }

            // Child is not in explored
            bool in_explored = false;
            for (std::set<Board*>::iterator it = this->explored.begin(); it != this->explored.end(); it++) {
                if (*(*it) == *(leaf->getChild(i))) {
                    in_explored = true;
                    break;
                }
            }
            
            // std::cout << "Status: " << in_frontier << " " << in_explored << " ADD: " << (!in_frontier && !in_explored) << ", f: " << leaf->getChild(i)->f_valueFrom() << std::endl;

            // switch(i) {
            //     case 0:
            //         std::cout << "LEFT : ";
            //         break;
            //     case 1:
            //         std::cout << "RIGHT: ";
            //         break;
            //     case 2:
            //         std::cout << "UP   : ";
            //         break;
            //     case 3:
            //         std::cout << "DOWN : ";
            //         break;
            //     default:
            //         std::cout << "DEF  : ";
            //         break;
            // }
            // std::cout << "in_frontier, in_explored: " << in_frontier << " " << in_explored << " -- ";

            // If both conditions are met, push into frontier
            if ( !in_frontier && !in_explored ) {
                // std::cout << "Adding ";
                // switch(i) {
                //     case 0:
                //         std::cout << "LEFT  f = ";
                //         break;
                //     case 1:
                //         std::cout << "RIGHT f = ";
                //         break;
                //     case 2:
                //         std::cout << "UP    f = ";
                //         break;
                //     case 3:
                //         std::cout << "DOWN  f = ";
                //         break;
                //     default:
                //         std::cout << "DEF   f = ";
                //         break;
                // }
                // std::cout << leaf->getChild(i)->f_valueFrom();
                this->frontier.push( leaf->getChild(i) );
                this->frontier_set.insert( leaf->getChild(i) );
            }
            // std::cout << std::endl;
        }
        // // Print out the frontier set
        // std::cout << "Printing frontier: {";
        // for (std::set<Board*>::iterator it = this->frontier_set.begin(); it != this->frontier_set.end(); it++) {
        //     std::cout << (*it)->f_valueFrom() << " ";
        // }
        // std::cout << "} size: " <<  this->frontier_set.size() << std::endl;

        // std::cout << "=================================================" << std::endl;
    } 
}

// Control
void GameDriver::beginGame() {

    int pChoice;
    int aChoice;

    std::cout << "Welcome to 862228249 8 puzzle solver.\n";
    std::cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle.\n";
    std::cin >> pChoice;
    std::cout << "\n";

    std::cout << "Enter your puzzle, use a zero to represent the blank\n";

    int rows = 3;
    int cols = 3;

    std::vector<std::vector<int>> mat(rows);

    // Iterate through the rows
    for (int r = 0; r < rows; r++) {

        std::cout << "Enter row " << r + 1 << ", use space or tabs between numbers: ";

        mat.at(r) = std::vector<int>(cols); // make a row

        // Collect integer items
        for (int i = 0; i < cols; i++) {
            std::cin >> mat.at(r).at(i);
        }

    }

    int heur;

    std::cout << "\nEnter your choice of algorithm\n"
              << "1. Uniform Cost Search\n"
              << "2. A* with the Misplaced Tile heuristic\n"
              << "3. A* with the Eucledian Distance heuristic\n";
    
    std::cin >> heur;
    std::cout << "\n" << std::endl;

    // Set the goal vector
    std::vector<std::vector<int>> goalVector(rows);

    // Iterate through the rows
    int cnt = 1;
    for (int r = 0; r < rows; r++) {
        goalVector.at(r) = std::vector<int>(cols); // make a row

        for (int i = 0; i < cols; i++) { // enter items
            goalVector.at(r).at(i) = cnt++;
        }
    }
    cnt = 0;

    // Make the goal equal to a Board with vector equal to the
    // goal vector
    this->goal = new Board(goalVector);

    goalVector.at(rows-1).at(cols-1) = cnt++; // set empty tile

    // Set the goal state
    this->goal = new Board(goalVector);

    // Root Board, start state
    Board* root = new Board(mat);

    // Problem that we pass onto the graph search
    Problem* myProblem = new Problem(root);

    root->setContext(myProblem);

    // Set the heuristic
    myProblem->setHeuristic(heur);

    // Graph search algorithm
    Board* solution = this->graphSearch(myProblem);
    if (solution != nullptr) {
        std::cout << "Goal!!!" << std::endl;
        solution->draw(std::cout);
        std::cout << "\n"
                  << "To solve this problem the search algorithm expanded a total of " << this->count << " nodes.\n"
                  << "The maximum number of nodes in the queue at any one time: " << "YYY.\n"
                  << "The depth of the goal node was: " << "ZZZ." << std::endl;
    }
    else {
        std::cout << "Failure!!!\n\n"
                  << "No answer was found. :(" << std::endl;
    }

}