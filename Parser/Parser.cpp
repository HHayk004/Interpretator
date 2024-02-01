#include "../Tokenizer/Tokenizer.h"
#include "Parser.h"
#include <vector>

Statement::Statement(const std::vector<token>& tokens, const std::string& type) : m_tokens(tokens), type(m_type) {}

void Statement::setTokens(const std::vector<token>& tokens)
{
    m_tokens = tokens;
}

void Statement::setType(StatementType type)
{
    m_type = type;
}
.
std::vector<tokens> getTokens() const
{
    return m_tokens;
}

StatementType Statement::getType() const
{
    return m_type;
}

void Statement::PrintStatement() const
{
    for (int i = 0; i < m_tokens.size(); ++i)
    {
        m_tokens[i].printToken() << ' ';
    }
    std::cout << static_cast<int>(m_type);
}

void Statement::makeStatements(const std::vector<tokens>& tokens)
{
    std::vector<token> tmp_statement;
    for (int i = 0; i < tokens.size(); ++i)
    {
        if (tokens[i].getType == TokenType::Semicolon)
        {
            Statement statement(tmp_statement, statementTypeFunc(tmp_statement));
            if (StatementCheck(statment))
            {
                m_tokens.push_back(statement);
                statement.clear();
            }

            else
            {
                statement.printStatement();
                std::cerr << " is invalid statement:\n";
                exit(-1);
            }
        }
    }
}

bool Parser::StatementCheck(const Statement& statement) const
{
    std::vector<Token> tokens = statement.getTokens()
    if (token[0].getType() == TokenType::Type)
    {
        return DeclarationCheck(tokens);
    }

    else if (token[0].getType == TokenType::Identifier)
    {
        return ArithmeticCheck(tokens);
    }

    else if (tokens[0].getType == TokenType::Cout)
    {
        return coutCheck(tokens);
    }

    else
    {
        return false;
    }
}

bool Parser::DeclarationCheck(const std::vector<Token>& tokens)
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
            if (token.getType() == TokenType::Identifier && // type check)
            {
                //symbol table check;
            }

            else if (token.getType() == TokenType::NumberLiteral && 
                        token[0] == TokenType::String)
            {
                return false;
            }

            else
            {
                return false;
            }
        }

        for (int i = 4; i < tokens.size(); i += 2)
        {
            if (!tokens[i].isOperator())
            {
                return false;
            }
        }

    }
}
