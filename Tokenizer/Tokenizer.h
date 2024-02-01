#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>

enum class TokenType {
    Bool, Char, Int, Double, String, // basic types
    NumberLiteral, StringLiteral, // literals
    Quote, DoubleQuote,
    Plus, Minus, Multiply, Division, // arithmetic operators
    Assignment,
    Condition, Cycle, 
    Cout,
    CoutFlow,
    Equal, SmallEqual, BigEqual, Small, Big, // comparison operators
    ArrayOpen, ArrayClose, ScopeOpen, ScopeClose, BraceOpen, BraceClose, // braces
    Semicolon,
    Identifier,
    None // invalid token
};

class Token {
    private:
        std::string m_name;
        TokenType m_type;

    public:
        Token(const std::string& name = "", TokenType type = TokenType::Identifier);
        ~Token() = default;

        void setName(const std::string& str);
        void setType(TokenType str);

        std::string getName() const;
        TokenType getType() const;

        void printToken() const;

        bool isType() const;
        bool isLiteral() const;
        bool isIdentifier() const;
        bool isOperator() const;
};

class Tokenizer {
    private:
        std::fstream m_file;
        std::vector<Token> m_tokens;
        
        const std::unordered_map<std::string, TokenType> token_types = {
            {"int", TokenType::Int}, {"double", TokenType::Double}, {"char",  TokenType::Char}, {"bool", TokenType::Bool}, {"string", TokenType::String},
            {"'", TokenType::Quote}, {"\"", TokenType::DoubleQuote},
            {"if", TokenType::Condition}, {"while", TokenType::Cycle}, {"std::cout", TokenType::Cout},
            {"=", TokenType::Assignment}, 
            {"+", TokenType::Plus}, {"-", TokenType::Minus}, 
            {"/", TokenType::Division}, {"*", TokenType::Multiply},
            {"==", TokenType::Equal}, {"<=", TokenType::SmallEqual}, {">=", TokenType::BigEqual},
            {"<", TokenType::Small}, {">", TokenType::Big},
            {"cout", TokenType::Cout},
            {"<<", TokenType::CoutFlow},
            {"[", TokenType::ArrayOpen}, {"]", TokenType::ArrayClose},
            {"{", TokenType::ScopeOpen}, {"}", TokenType::ScopeClose},
            {"(", TokenType::BraceOpen}, {")", TokenType::BraceClose},
            {";", TokenType::Semicolon}
        };
        
        void makeTokens(const std::string& line);
		
	    TokenType tokenType(const std::string& token) const;

        void printTokens() const;

    public:
        Tokenizer(const char* str);
        ~Tokenizer();

	    std::vector<Token> getTokens() const;

        void readFile();
};
#endif
