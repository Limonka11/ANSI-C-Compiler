#include "parser.hpp"
#include "wrapper.hpp"

#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    std::ofstream out(argv[4]);
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    std::ifstream in(argv[2]);
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cout to out.txt!

    std::string src = argv[2];

    wrapper code(true);
    const Node* root = parse(src);
    root->codegen(code);

    code.print(std::cout);

    return 0;
}