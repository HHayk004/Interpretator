#include "Tokenizer.h"
#include <iostream>
#include <string>
#include <cctype>

Token::Token(const std::string& name, TokenType type) : m_name(name), m_type(type) {}

void Token::setName(const std::string& str) {
    m_name = str;
}

void Token::setType(TokenType type) {
    m_type = type;
}

std::string Token::getName() const {
    return m_name;
}

TokenType Token::getType() const {
    return m_type;
}

void Token::printToken() const
{
    std::cout << m_tokens[i].getName() << ' ' << static_cast<int>(m_tokens[i].getType());
}

bool Token::isType() const
{
    return m_type == TokenType::Bool || m_type == TokenType::Char || m_type == TokenType::Int 
            || m_type == TokenType::Double || m_type == String;
}

bool Token::isIdentifier() const
{
    return m_type == Identifier;
}

bool isOperator() const
{
    return m_type == TokenType::Plus || m_type == TokenType::Minus || m_type == TokenType::Multiply
            || m_type == TokenType::Division;
}

Tokenizer::Tokenizer(const char* str) : m_file(str, std::ios::in)
{
    if (!m_file.is_open())
    {
        std::cerr << "Error with file openning:\n";
        exit(-1);
    }
}

Tokenizer::~Tokenizer()
{
    m_file.close();
}

void Tokenizer::readFile()
{
    std::string line;
    while (!m_file.eof())
    {
        std::getline(m_file, line);
        makeTokens(line);
    }

    printTokens();
}

void Tokenizer::makeTokens(const std::string& line)
{
    std::string token_name;
    for (int i = 0; i < line.size(); ++i)
    {
        if (!token_name.empty())
        {
            if (line[i] == ' ' || line[i] == '\n')
            {
                m_tokens.push_back(Token(token_name, tokenType(token_name)));
                token_name = "";
                continue;
            }

            if (std::isalnum(token_name.back()) != std::isalnum(line[i]))
            {
                m_tokens.push_back(Token(token_name, tokenType(token_name)));
                token_name = "";
            }

            token_name += line[i];
        }

        else if (line[i] != ' ' && line[i] != '\n')
        {
            token_name += line[i];
        }
    }

    if (!token_name.empty())
    {
        m_tokens.push_back(Token(token_name, tokenType(token_name)));
    } 
}

TokenType Tokenizer::tokenType(const std::string& token) const
{
    if (token_types.find(token) != token_types.end())
    {
        return token_types[token];
    }

    if (std::isalpha(token[0]))
    {
        return TokenType::Identifier;
    }

    if ('0' <= token[0] && token[0] <= '9')
    {
        try
        {
            stoi(token);
            return TokenType::NumberLiteral;
        }

        catch(std::invalid_argument const& ex)
        {
            return TokenType::stringLiteral;
        }
    }

    return TokenType::None;
}

void Tokenizer::printTokens() const
{
    for (int i = 0; i < m_tokens.size(); ++i)
    {
        m_tokens[i].printToken();
        std::cout << std::endl;
    }
}
