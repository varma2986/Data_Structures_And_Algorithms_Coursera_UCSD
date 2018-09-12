#include <iostream>
#include <stack>
#include <string>
#include <sstream>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    std::string output= "Success";
    std::stringstream posss;

    std::stack <Bracket> opening_brackets_stack;
    int position;
    for (position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            Bracket b(next,position+1);
            opening_brackets_stack.push(b);
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if (opening_brackets_stack.empty()) {
              posss << position+1;
              output = posss.str();
              break;
            }
            Bracket top = opening_brackets_stack.top();
            opening_brackets_stack.pop();
            if(!top.Matchc(next)) {
              posss << position+1;
              output = posss.str();
              break;
            }
        }
    }
    if(position==text.length() && !opening_brackets_stack.empty()) {
      Bracket top = opening_brackets_stack.top();
      posss << top.position;
      output = posss.str();
    }
    // Printing answer, write your code here
    std::cout<<output;
    return 0;
}
