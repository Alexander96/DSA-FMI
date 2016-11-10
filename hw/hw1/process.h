#ifndef PROCESS
#define PROCESS
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "stack.h"

using namespace std;

struct oper
{
    string sym;
    string op;
    string as;
};
class Input
{
    string file_name_operators;
    string file_name_expression;
    vector<oper> operators;
    string expression;
    public:
        Input(string name1, string name2)
        {
            file_name_expression = name1;
            file_name_operators = name2;
        }
        string get_file_name_operators() const
        {
            return file_name_operators;
        }
        string get_file_name_expression() const
        {
            return file_name_expression;
        }
        bool validate()
        {
            string line;
            ifstream file (file_name_expression);
            if (file.is_open())
            {
                getline(file, line);
                file.close();
            }
            else
            {
                cout << "Unable to open file "<<file_name_expression<<endl;
            }
            process_operators();
            vector<string> characters = split(line, ' ');
            for(int i=0;i<characters.size();i++)
            {
                bool check = validate_character(characters[i]);
                if(!check)
                {
                    cout<<"Error"<<endl;
                    return false;
                }
            }
            return true;
        }
    private:
        vector<string> split(const string &s, char delim)
        {
            vector<string> elems;
            stringstream ss;
            ss.str(s);
            string item;
            while (getline(ss, item, delim)) {
                elems.push_back(item);
            }
            return elems;
        }
        void process_operators()
        {
            string line;
            ifstream file (file_name_operators);
            if (file.is_open())
            {
                while(getline(file, line))
                {
                    vector<string> line_split = split(line, ' ');
                    oper o;
                    o.sym = line_split[0];
                    o.op = line_split[1];
                    o.as = line_split[2];
                    operators.push_back(o);
                }
                file.close();
            }
            else
            {
                cout << "Unable to open file "<<file_name_expression<<endl;
            }
        }
        bool isNumber(string str)
        {
            char* endptr = 0;
            strtod(str.c_str(), &endptr);

            if(*endptr != '\0' || endptr == str)
                return false;
            return true;
        }
        bool validate_character(string &s)
        {
            bool is_number = isNumber(s);
            bool is_sym = false;
            for(int i=0;i<operators.size();i++)
            {
                if(operators[i].sym == s)
                {
                    is_sym = true;
                }
            }
            if(is_number || is_sym)
                return true;
            return false;
        }
};
#endif
