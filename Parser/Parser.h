#include "../Tokenizer/Tokenizer.h"
#include <vector>

enum class StatementType {
    Declaration,
    Arithmetic,
    Condition
}

class Statement {
    private:
        std::vector<Token> m_tokens;
        StatementType m_type;

    public:
        Statement(const std::vector<Token>& tokens = {}, const std::string& type = "");
        ~Statement() = default;

        void setTokens(const std::vector<Token>& tokens);
        void setType(StatementType type);

        std::vector<Token> getTokens() const;
        StatementType getType() const;

        void printStatement() const;
}

class Parser {
    private:
        std::vector<Statements> m_statemets;
        static bool statementCheck(const Statement& statement);
        
        static bool delcarationCheck(const std::vector<Token>& tokens);
        static bool arithmeticCheck(const std::vector<token>& tokens);
        static bool coutCheck(const std::vector<token>& tokens);

    public:
        ~Parser() = default;

        makeStatements(const std::vector<Tokens>& tokens);

        StatementType statementTypeFunc(const std::vector<Tokens>& tokens) const;

        void printStatements() const;
};
