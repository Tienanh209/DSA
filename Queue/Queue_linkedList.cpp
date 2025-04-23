#include <iostream>
using namespace std;

class QueueNode
{
public:
    int data;
    QueueNode *next;

    QueueNode(int val)
    {
        this->data = val;
        this->next = nullptr;
    }
};

class Queue
{
private:
    QueueNode *front;
    QueueNode *rear;

public:
    Queue()
    {
        front = rear = nullptr;
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Function to add an element to the queue
    void enqueue(int val)
    {
        QueueNode *newNode = new QueueNode(val);
        if (isEmpty())
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    // Function to remove an element from the queue
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow !" << endl;
            return;
        }
        QueueNode *temp = front;
        front = front->next;
        delete temp;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return INT_MIN;
        }
        return front->data;
    }

    // Function to print the current state of the queue
    void printQueue()
    {
        QueueNode *temp = front;
        cout << "Queue: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.dequeue();
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.printQueue();
    q.dequeue();
    q.dequeue();
    q.printQueue();
    cout << q.getFront() << endl;
}