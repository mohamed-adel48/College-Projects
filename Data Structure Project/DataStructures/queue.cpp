#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T>* next = NULL;
};

template <class T>
class Queue
{
public:
    Node<T> *front;
    Node<T> *rear;
    int size = -1;

    Queue<T>()
    {
        front = rear = NULL;
    }

    bool isEmpty()
    {
        return !front;
    }

// for testing
    int display()
    {
        if (!front)
            return -1;
        Node<T> *cur = front;
        while(cur)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void enQueue(T value)
    {
        Node<T> *newnode = new Node<T>;
        newnode->data = value;

        if (!front)
            front = rear = newnode;
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
        size++;
    }

    int deQueue()
    {
        if (!front)
            return 0;
        size--;
        if (front == rear)
        {
            delete front;
            front = rear = NULL;
            return 1;
        }
        Node<T> *tmp = front;
        front = front->next;
        delete tmp;
        return 1;
    }

    T Front()
    {
        return front->data;
    }

    T Rear()
    {
        return rear->data;
    }

    int Size()
    {
        return size;
    }

    int clear()
    {
        if (!front)
            return 0;
        while (front)
            deQueue();
        return 1;
    }
};

int main()
{
    string item;
    Queue<string> q;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the Item to enQueue: ";
        cin >> item;
        q.enQueue(item);
    }
    q.display();
}