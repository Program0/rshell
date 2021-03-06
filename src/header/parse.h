// Marlo Zeroth mzero001@ucr.edu 861309346
// Emmilio Segovia esego001@ucr.edu 861305177

#ifndef PARSE
#define PARSE
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include <map>

class Parse {
    private:
        std::string input;

    public:
        Parse();
        void setInput(std::string input);           //to be set by user during runtime
        int parse(std::vector< std::vector<std::string> > &vOut);  //returns success/failure int
        std::string trim(std::string str);
		bool checkParenthesis(std::vector< std::vector<std::string> > &vOut);
        bool badInput(std::string str, int &i, char connector);
};

#endif

