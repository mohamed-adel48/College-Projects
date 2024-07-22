#include <iostream>
#include "..\DataStructures\Stack.cpp"
using namespace std;

int main()
{
    cout << "Enter Word: ";
    string word; cin >> word;
    Stack<char> stack;
    for (int i = 0; i < word.size(); i++)
        stack.push(word[i]);

    for (int i = 0; i < word.size()/2; i++)
    {
        if (stack.peek() != word[i]) { cout << "No"; return 0; }
        stack.pop();
    }
    cout << "Yes\n";
}