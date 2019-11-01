//Array implementation of Stack of integers

#include <iostream>

using namespace std;

class Stack
{
    private:
        int size;
        int top;
        int* array;
    public:
        Stack(int size);
        void push(int x);
        void pop();
        void peek();
        void isEmpty();
};

Stack::Stack(int size)
{
    top = -1;
    Stack::size = size;
    array = new int[size];
}

void Stack::push(int x)
{
    if(top < size-1)
    {
        top = top+1;
        array[top] = x;
        cout << "Element " << x << " is pushed in" << endl;
    }
    else
        cout << "Stack Overflow" << endl;
}

void Stack::pop()
{
    if(top > -1)
    {
        cout << "Element " << array[top] << " is popped out" << endl;
        top = top-1;
    }
    else
        cout << "Stack Underflow" << endl;
}

void Stack::peek()
{
    if(top > -1)
        cout << "Element " << array[top] << " is at top" << endl;
    else
        cout << "Stack is empty" << endl;
}

void Stack::isEmpty()
{
    if(top > -1)
        cout << "Stack is not empty" << endl;
    else
        cout << "Stack is empty" << endl;
}

int main()
{
    Stack s(3);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    s.peek();
    s.isEmpty();
    s.pop();
    s.isEmpty();
    s.pop();
    s.isEmpty();
    s.peek();
    s.pop();
    s.isEmpty();
    s.peek();
    return 0;
}
