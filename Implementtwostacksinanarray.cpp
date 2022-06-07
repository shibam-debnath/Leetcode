// Shibam Debnath
// June ,2022

#include <iostream>
#include <stdlib.h>
using namespace std;
#define ll long long

class twoStacks
{

public:
    // class variables/methods which can be used anywhere(global var type)
    int *arr;
    int n1, n2;
    int size;

    // constructor that initialises a array of size n
    twoStacks(int n)
    {
        size = n;
        // declare arry size
        arr = new int[n];
        n1 = 0;
        n2 = n - 1;
    }

    void push1(int x)
    {
        arr[n1] = x;
        n1++;
    }

    void push2(int x)
    {
        arr[n2] = x;
        n2--;
    }

    int pop1()
    {
        int a = arr[n1 - 1];
        n1--;
        return a;
    }

    int pop2()
    {
        int b = arr[n2 + 1];
        n2++;
        return b;
    }
    void show()
    {
        cout << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }
};

int main()
{
    twoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    ts.show();
    cout << "Popped element from stack1 is "
         << " : " << ts.pop1()
         << endl;
    ts.push2(40);
    cout << "\nPopped element from stack2 is "
         << ": " << ts.pop2()
         << endl;
    ts.show();
    return 0;
}