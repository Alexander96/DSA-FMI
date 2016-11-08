#include <iostream>
#include "Stack.h"
using namespace std;
int main()
{
    LinkedStack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    cout<<"size: "<<stack.GetSize()<<endl; 
    cout<<"peek: "<<stack.Peek()<<endl;
    int a;
    bool b = stack.Pop(a);
    cout<<"pop: "<<a<<endl;
    cout<<"empty? "<<stack.IsEmpty()<<endl;
    cout<<"peek: "<<stack.Peek()<<endl;
    stack.RemoveAll();
    cout<<"empty? "<<stack.IsEmpty()<<endl;
    cout<<"bb"<<endl;
    return 0;
}
