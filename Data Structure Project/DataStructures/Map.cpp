#include <iostream>
using namespace std;

template <class k, class v>
struct pairs
{
    k key;
    v value;
    pairs<k, v> *Next = NULL;
    pairs<k, v> *Prev = NULL;
};

template <class k, class v>
class Map
{

public:
    pairs<k, v> *head;
    pairs<k, v> *tail;

    Map<k, v>()
    {
        head = tail = NULL;
    }

    void insert(k key, v value)
    {
        pairs<k, v> *newPairs = new pairs<k, v>;
        newPairs->key = key;
        newPairs->value = value;

        if (!head)
            head = tail = newPairs;
        else
        {
            tail->Next = newPairs;
            newPairs->Prev = tail;
            tail = newPairs;
            tail->Next = NULL;
        }
    }

    int remove(k key)
    {
        if (!head)
            return 0;

        if(head->key == key)
        {
            pairs<k, v> *tmp = head;
            head = head->Next;
            delete tmp;
            return 1;
        }

        if(tail->key == key)
        {
            pairs<k, v> *tmp = tail;
            tail = tail->Prev;
            tail->Next = NULL;
            delete tmp;
            return 1;
        }

        pairs<k, v> *it = head;
        while (it)
        {
            if (it->Next->key == key)
            {
                pairs<k, v> *tmp = it->Next;
                it->Next->Next->Prev = it;
                it->Next = it->Next->Next;
                delete tmp;
                return 1;
            }
            it = it->Next;
        }
        return 0;
    }

    pairs<k, v> *search(k key)
    {
        if (!head)
            return NULL;
        pairs<k, v> *cur = head;
        while(cur)
            if(cur->key == key)
                return cur;
        return NULL;
    }

    void display()
    {
        if (!head)
            cout << "empty...\n";
        else
        {
            pairs<k, v> *cur = head;
            while(cur)
            {
                cout << "Key: " <<cur->key << " Value: " <<cur->value << endl;
                cur = cur->Next;
            }
        }
    }

    void distroy()
    {
        pairs<k, v> *cur = head, *tmp;
        while(cur)
        {
            tmp = cur;
            cur = cur->Next;
            delete tmp;
        }
    }

    // string allMap()
    // {
    //     string res = "";
    //     pairs<k, v> *cur = head;
    //     while (head)
    //     {
    //         res += "Key: " + cur->key + " Value: " + cur->value + '\n';
    //         cur = cur->Next;
    //     }
    // }
};