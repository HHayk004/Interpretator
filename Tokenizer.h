#include <string>
#include <fstream>
#include <vector>

class Token {
    private:
        std::string m_name;
        std::string m_type;

    public:
        Token(const std::string& str = "", const std::string& type = "");
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

        void printTokens() const;

    public:
        Tokenizer(const char* str);
        ~Tokenizer();

        void readFile();
};
