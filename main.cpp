#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Tokenizer/Tokenizer.h"
#include "Parser/Parser.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Wrong count of files: Must be one\n";
        exit(-1);
    }

    Tokenizer tokenizer(argv[1]);
    tokenizer.readFile();
    Parser parser;
    parser.run(tokenizer.getTokens());
}
