#include <iostream>
using namespace std;

class Stack
{
    int top, cap;
    int *a;

public:
    Stack(int cap)
    {
        this->cap = cap;
        top = -1;
        a = new int[cap];
    }

    ~Stack()
    {
        delete[] a;
    }

    bool push(int x)
    {
        if (top >= cap - 1)
        {
            cout << "Stack Overflow\n";
            return false;
        }
        a[++top] = x;
        return true;
    }

    int pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow\n";
            return 0;
        }
        return a[top--];
    }

    int peek()
    {
        if (top < 0)
        {
            cout << "Stack is Empty\n";
            return 0;
        }
        return a[top];
    }

    bool isEmpty()
    {
        return top < 0;
    }

    void display()
    {
        if (top < 0)
            return;
        cout << "Stack: ";
        for (int i = top; i >= 0; i--)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s(10);
    s.push(2);
    s.push(5);
    s.push(3);
    s.display();
    cout << "Deleted: " << s.pop() << endl;
    s.display();
    cout << "The first element of stack: " << s.peek() << endl;
};