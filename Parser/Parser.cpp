#include "../Tokenizer/Tokenizer.h"
#include "Parser.h"
#include <iostream>
#include <string>
#include <vector>

Statement::Statement(const std::vector<Token>& tokens) : m_tokens(tokens) {}

void Statement::setTokens(const std::vector<Token>& tokens)
{
    m_tokens = tokens;
}

std::vector<Token> Statement::getTokens() const
{
    return m_tokens;
}

void Statement::printStatement() const
{
    for (int i = 0; i < m_tokens.size(); ++i)
    {
        m_tokens[i].printToken();
        std::cout << ' ';
    }

    std::cout << std::endl;
}

void Parser::run(const std::vector<Token>& tokens)
{
    std::vector<Token> tmp_statement;
    for (int i = 0; i < tokens.size(); ++i)
    {
        if (tokens[i].getType() == TokenType::Semicolon)
        {
            Statement statement(tmp_statement);
            if (!statementImpl(statement))
            {
                statement.printStatement();
                std::cerr << " is invalid statement:\n";
                exit(-1);
            }

            tmp_statement.clear();
        }

        else
        {
            tmp_statement.push_back(tokens[i]);
        }
    }
}

bool Parser::statementImpl(const Statement& statement)
{
    std::vector<Token> tokens = statement.getTokens();

    if (tokens[0].isType())
    {
        return declarationImpl(tokens);
    }

    else if (tokens[0].getType() == TokenType::Identifier)
    {
        return arithmeticImpl(tokens);
    }

    else if (tokens[0].getType() == TokenType::Cout)
    {
        return coutImpl(tokens);
    }

    else
    {
        return false;
    }
}

bool Parser::declarationImpl(const std::vector<Token>& tokens)
{
    if (tokens.size() == 1 || tokens[1].getType() != TokenType::Identifier)
    {
        return false;
    }

    if (tokens.size() > 2)
    {
        if (tokens[2].getType() != TokenType::Assignment)
        {
            return false;
        }
        
        for (int i = 3; i < tokens.size(); i += 2)
        {
	    
        }
    }
}

bool Parser::arithmeticImpl(const std::vector<Token>& tokens)
{

}

bool Parser::coutImpl(const std::vector<Token>& tokens)
{
	if (tokens.size() != 3 || tokens[1].getType() != TokenType::CoutFlow)
    {
        return false;
    }

    if (tokens[2].getType() == TokenType::NumberLiteral)
    {
        std::cout << stod(tokens[2].getName()) << std::endl;
        return true;
    }

    return false;
}
