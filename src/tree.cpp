// User Libraries
#include "tree.h"

/* Constructors and Destructor */

// Default constructor
Tree::Tree() {
    root = NULL;
}

// Copy constructor
Tree::Tree(const Tree &tree){
    // If we are not empty clear then rebuild
    if(root!=NULL)
        this->clear();
    this->build(tree.commands);
    this->commands = tree.commands;
}

// Destructor
Tree::~Tree(){
  if (root != NULL) {
        delete root;
        root = NULL; // Point it to NULL so we don't get garbage accessing it later
    }
}

// Assignment operator
Tree & Tree::operator= (const Tree& tree){

    // If we are not empty clear then rebuild
    if(root!=NULL)
        this->clear();
    
    // Now we rebuild with the passed tree commands
    this->build(tree.commands);
    this->commands = tree.commands;
    return *this;
}

// Returns whether the tree is empty
bool Tree::isEmpty() {

    if (root == NULL) 
        return true;
        
    return false;
}

// Builds the tree based on the passed commands in vector vIn
void Tree::build(std::vector< std::vector<std::string> > vIn) {
    this->commands = vIn;   
    if ((vIn.size() % 2) != 0) {
        if (vIn.at(0).at(0) == "exit") {
            root = new Exit_Command();
        }
        else if (vIn.at(0).at(0) == "test"){
            root = new Test_Command(vIn.at(0));
            }
        else {
            root = new System_Call(vIn.at(0));
        }
        if (vIn.size() > 1) {
            int i = 1;
            Base* command;
            while (i < (((int) vIn.size()) - 1)) {
                if (vIn.at(i + 1).at(0) == "exit") {
                    command = new Exit_Command();
                }              
                else if (vIn.at(i + 1).at(0) == "test"){
                    command = new Test_Command(vIn.at(i + 1));
                }
                else {
                    command = new System_Call(vIn.at(i + 1));
                }
    
                if (vIn.at(i).at(0) == "&&") {
                    root = new And_Connector(root, command);
                }
                else if (vIn.at(i).at(0) == "||") {
                   root = new Or_Connector(root, command);
                }
                else if (vIn.at(i).at(0) == ";") {
                    root = new Semicolon_Connector(root, command);
                }
                i += 2;
            }
        }
    }
}

// Empty the tree
void Tree::clear(){
  if (root != NULL) {
        delete root;
        root = NULL; // Point it to NULL so we don't get garbage accessing it later
        this->commands.clear(); // We clear all commands
    }
}

// Executes the tree commands
int Tree::execute(){
    return root->execute();
}

