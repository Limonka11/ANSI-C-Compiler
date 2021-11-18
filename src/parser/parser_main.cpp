#include "Parser/parser.hpp"

#include <iostream>

int main() {

        const astNode* root = parse();
        root->print();

        return 0;
}