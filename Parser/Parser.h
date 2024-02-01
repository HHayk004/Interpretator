#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <unordered_map>
#include <vector>

struct VariableData {
    TokenType m_type;
    std::string m_val;
};

class SymbolTable {
	private:
        std::unordered_map<std::string, VariableData> m_table;

	public:
        SymbolTable(TokenType type, std::string val);
        bool variableCheck(const std::string& name);
};

class Statement {
    private:
        std::vector<Token> m_tokens;

    public:
        Statement(const std::vector<Token>& tokens = {});
        ~Statement() = default;

        void setTokens(const std::vector<Token>& tokens);

        std::vector<Token> getTokens() const;

        void printStatement() const;
};

class Parser {
    private:
        std::vector<SymbolTable> m_stack;
       
        bool statementImpl(const Statement& statement);
        
        bool declarationImpl(const std::vector<Token>& tokens);
        bool arithmeticImpl(const std::vector<Token>& tokens);
        bool coutImpl(const std::vector<Token>& tokens);

    public:
        ~Parser() = default;

        void run(const std::vector<Token>& tokens);

        void printStatements() const;
};
#endif
