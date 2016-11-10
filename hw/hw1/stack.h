#ifndef STACK 
#define STACK
template <class T>
struct elem
{
    T data;
    elem *link;
};
template <class T>
class Stack
{
    elem<T> *top;
    unsigned int count;
    public:
    Stack(){top=NULL;count=0;}
    void add(const T& a)
    {
        elem<T> *p = new elem<T>;
        p->data = a;
        p->link = top;
        top=p;
        count++;
    }
    bool pop(T& a)
    {
        if(count==0)return false;
        elem<T> *p = top;
        a = p->data;
        top = top->link;
        delete p;
        count--;
        return true;
    }
    bool viewTop(T &a)const
    {
        if(count==0)return false;
        a = top->data;
        return true;
    }
    int getCount()const
    {
        return count;
    }
    bool isEmpty()const
    {
        return count == 0;
    }
    ~Stack()
    {
        while(count)
        {
            elem<T> *p = top;
            top = top->link;
            delete p;
            count--;
        }
    }
};
#endif
