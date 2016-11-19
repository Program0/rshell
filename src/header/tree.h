// Marlo Zeroth marlo.zeroth@email.ucr.edu 861309346
// Emmilio Segovia esego001@ucr.edu 861305177

#ifndef TREE_H
#define TREE_H

// System libraries
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>

// User Libraries
#include "base.h" // Root - used to polymorphically and recursively call connector or command execute()
#include "command.h" // Leaf - performs system calls
#include "exit_command.h" // Leaf - performs exit command
#include "and_connector.h" // Node - connects leaves using logical && connector
#include "or_connector.h" // Node - connects leaves using logical || connector
#include "semicolon_connector.h" // Node - connects leaves using ; connector
#include "test_command.h"
#include "system_call.h"



class Tree {
private:
    Base* root;

    // Stores the 
    std::vector<std::vector<std::string> > commands;
    
    // Utility functions
    
    /*
    *  Helper function for the execute() function.
    *  Recursively traverses the tree in post-order
    *  and returns the status of the node->execute()
    *  function. If at any time a value of -1 is
    *  returned we exit the recursion and return -1.    
    */ 
    int executeCommand(Base * node, int status);

public:
    /* Constructors and Destructor */

    // Default constructor
    Tree();

    // Copy constructor 
    Tree(const Tree &tree);

    // Destructor - Recursively deallocates
    ~Tree();

    // Assignment operator
    Tree& operator= (const Tree& tree);

	//root accessor
	void setRoot(Base* r);

    // Builds the command tree based on parsed user input
    Base* build(std::vector<std::vector<std::string> > vIn);

    // Returns whether the tree is empty
    bool isEmpty();

    // Clears the tree of all system calls
    void clear();

    // Executes the stored system calls
    int execute();

};

#endif // TREE_H

