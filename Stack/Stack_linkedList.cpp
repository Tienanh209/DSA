#include <iostream>
using namespace std;

class StackNode
{
public:
    int data;
    StackNode *next;

    StackNode()
    {
        this->data = 0;
        this->next = nullptr;
    }

    StackNode(int value)
    {
        this->data = value;
        this->next = nullptr;
    }
};

class Stack
{
    StackNode *top;

public:
    Stack()
    {
        this->top = nullptr;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(int value)
    {
        StackNode *newNode = new StackNode(value);
        if (!newNode)
        {
            cout << "Stack Overflow" << endl;
        }
        newNode->next = top;
        this->top = newNode;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        StackNode *nodeToDelete = top;
        top = top->next;
        delete nodeToDelete;
    }

    int peek()
    {
        if (!isEmpty())
            return top->data;
        return INT_MIN;
    }

    void display()
    {
        StackNode *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    Stack stack;
    cout << stack.isEmpty() << endl;
    stack.pop();
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    cout << stack.peek() << endl;

    stack.pop();
    stack.display();
};