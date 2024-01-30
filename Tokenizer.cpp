#include "Tokenizer.h"
#include <iostream>
#include <cctype>

Token::Token(const std::string& name, const std::string& type) : m_name(name), m_type(type) {}

void Token::setName(const std::string& str) {
    m_name = str;
}

void Token::setType(const std::string& str) {
    m_type = str;
}

std::string Token::getName() const {
    return m_name;
}

std::string Token::getType() const {
    return m_type;
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
    for (int i = 0; i < m_tokens.size(); ++i)
    {
        delete m_tokens[i];
    }
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
                m_tokens.push_back(new Token(token_name));
                token_name = "";
                continue;
            }

            if (std::isalnum(token_name.back()) != std::isalnum(line[i]))
            {
                m_tokens.push_back(new Token(token_name));
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
        m_tokens.push_back(new Token(token_name));
    } 
}

void Tokenizer::printTokens() const
{
    for (int i = 0; i < m_tokens.size(); ++i)
    {
        std::cout << m_tokens[i]->getName() << ' ' << m_tokens[i]->getType() << std::endl;
    }
}
