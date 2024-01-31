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

bool Parser::StatementCheck(Statement& statement) const
{
    std::vector<Token> tokens = statement.getTokens()
    int index = 0;
    if (tokens.size <= 2)
    {
        return false;
    }

    if (tokens[0].isType())
    {
        index = 1;
    }

    for (int i = index; i < tokens.size(); ++i)
}
