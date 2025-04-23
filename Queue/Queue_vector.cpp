#include <vector>
#include <iostream>
using namespace std;
class Queue
{
    vector<int> q;

public:
    bool isEmpty()
    {
        return q.empty();
    }

    void enqueue(int x)
    {
        q.push_back(x);
    }

    void dequeue()
    {
        if (!isEmpty())
            q.erase(q.begin());
    }

    int getFront()
    {
        return isEmpty() ? -1 : q.front();
    }

    void display()
    {
        for (int i = 0; i < q.size(); i++) // for (int i:q)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
};

int main()
{
    Queue q;
    cout << q.isEmpty() << endl;
}