#include <iostream>
#include "../DataStructures/Map.cpp"
using namespace std;

int main()
{
    Map<string, string> Contacts;
    string tmpName, tmpPhone;
    int ask = 0;
    do
    {
        cout << "WELCOME IN CONTACTS MANGER\n[1] Add New Contact\n[2] RemoveContact\n[3] Search\n[4] Show ALl Contacts\n[5] Distroy\n[0] Exit\n";
        cin >> ask;

        switch (ask)
        {
        case 1:
        {
            cout << "Name: "; cin >> tmpName; 
            cout << "Phone: "; cin >> tmpPhone; 
            Contacts.insert(tmpName, tmpPhone);
            break;
        }
        case 2:
        {
            cout << "Enter Name want to deleted\n";
            cin >> tmpName;
            if (Contacts.remove(tmpName) == 0)
                cout << "Name not Found\n";
            else
                cout << "Success..\n";
            break;
        }
        case 3:
        {
            cout << "Name: ";
            cin >> tmpName;
            pairs<string, string> *con = Contacts.search(tmpName);
            if (!con)
                cout << "Not Found\n";
            else
                cout << "Name: " << con->key << " Phone: " << con->value << '\n';
            break;
        }
        case 4:
        {
            cout << "\n--------Contacts--------\n";
            Contacts.display();
            cout << "\n------------------------\n";
            break;
        }
        case 5:
        {
            cout << "\nAll Contacts Has been removed\n";
            Contacts.distroy();
            Contacts.display();
            cout << '\n';
            break;
        }

        default:
            break;
        }
    } while (ask != 0);
}