#include <iostream>

#include "parser.hpp"

int main(){
    const Node* root = parse();
    std::cout << "+++++++++++++++++++++++++++PARSED AST+++++++++++++++++++++++++++" << std::endl;
    root->print();
}