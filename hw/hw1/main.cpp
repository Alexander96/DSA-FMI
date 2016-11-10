#include <iostream>
#include <string>
#include "stack.h"
#include "input.h"
using namespace std;
int main()
{
    Stack<double> stack;
    Input input("expression.txt", "operators.txt");
    bool valid = input.validate();
    return 0;
}
