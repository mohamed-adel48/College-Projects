#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *next = NULL;
};

template <class T>
class Stack
{
public:
    Node<T> *top;

    Stack<T>()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        return !top;
    }

    void push(T word)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = word;

        if(top != NULL)
            newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (!top)
            return -1;
        else
        {
            Node<T> *tmp = top;
            top = top->next;
            delete tmp;
        }
    }
    
    T peek() 
    {
        return top->data;
    }

};