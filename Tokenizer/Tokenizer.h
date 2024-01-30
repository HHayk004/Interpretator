#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>

class Token {
    private:
        std::string m_name;
        std::string m_type;

    public:
        Token(const std::string& name = "", const std::string& type = "");
        virtual ~Token() = default;

        void setName(const std::string& str);
        void setType(const std::string& str);

        std::string getName() const;
        std::string getType() const;
};

/*
class Identifier : public Token {
    public:
        Identifier(const std::string& str);
};

class Operator : public Token {
    public:
        Operator(const std::string& str);
};
*/

class Tokenizer {
    private:
        std::fstream m_file;
        std::vector<Token*> m_tokens;

        void makeTokens(const std::string& line);
		
	    std::string tokenType(const std::string& token);

        void printTokens() const;

    public:
        Tokenizer(const char* str);
        ~Tokenizer();

        void readFile();

    public:
        std::unordered_map<std::string, std::string> token_types = {
            {"int", "type"}, {"double", "type"}, {"char", "type"}, {"bool", "type"}, {"string", "type"},
            {"main", "start"}, {"if", ""}, {"while", "cycle"}, {"std::cout", "keyword"},
            {"=", "assignment"}, 
            {"+", " arithmetic operator"}, {"-", "arithmetic operator"}, 
            {"/", "arithmetic operator"}, {"*", "arithmetic operator"},
            {"==", "comparision operator"}, {"<=", "comparision operator"}, {"=>", "comparision operator"},
            {"<", "comparision operator"}, {"==", "comparision operator"},
            {"<<", "cout operator"},
            {"[", "array open"}, {"]", "array close"},
            {"{", "scope open"}, {"}", "scope close"},
            {"()", "main id"}, {"(", "brace open"}, {")", "brace close"},
            {";", "statement end"}
        };
};
