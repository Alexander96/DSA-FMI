#include <iostream>
using namespace std;
struct DA
{
    int *Data;
    int Used;
    int Size;
};
void Init(DA *Arr)
{
    Arr->Data = NULL;
    Arr->Used = 0;
    Arr->Size = 0;
}
void Reallocate(DA *Arr, int NewSize)
{
    int *temp = new int[NewSize];
    for(int i=0;i<Arr->Used;i++)
    {
        temp[i] = Arr->Data[i];
    }
    delete[] Arr->Data;
    Arr->Data = temp;
    Arr->Size = NewSize;
}

void Add(DA *Arr, int el)
{
    if(Arr->Size <= Arr->Used)
    {
        int NewSize = (Arr -> Size==0) ? 2 : Arr->Size*2;
        Reallocate(Arr, NewSize);
    }
    Arr->Data[Arr->Used++] = el;
}
void Free(DA *Arr)
{
    delete[] Arr->Data;
    Arr -> Size=0;
    Arr -> Used = 0;
}
int main()
{
    DA da;
    Init(&da);
    for(int i=0;i<100;i++)
    {
        Add(&da, i);
        cout<<da.Size<<" ";
    }
    Free(&da);
    return 0;
}
