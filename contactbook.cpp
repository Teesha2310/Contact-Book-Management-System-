#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Contact
{
public:
    string name;
    string phone;
};

vector<Contact> contacts;

void saveToFile()
{
    ofstream fout("contacts.txt");

    for(auto c : contacts)
    {
        fout << c.name << endl;
        fout << c.phone << endl;
    }

    fout.close();
}

void loadFromFile()
{
    contacts.clear();

    ifstream fin("contacts.txt");

    Contact c;

    while(getline(fin, c.name))
    {
        getline(fin, c.phone);
        contacts.push_back(c);
    }

    fin.close();
}

void addContact()
{
    Contact c;

    cin.ignore();

    cout << "\nEnter Name : ";
    getline(cin, c.name);

    cout << "Enter Phone Number : ";
    getline(cin, c.phone);

    contacts.push_back(c);

    saveToFile();

    cout << "\nContact Added Successfully\n";
}

void displayContacts()
{
    if(contacts.size() == 0)
    {
        cout << "\nNo Contacts Found\n";
        return;
    }

    cout << "\n===== CONTACT LIST =====\n";

    for(auto c : contacts)
    {
        cout << "\nName : " << c.name;
        cout << "\nPhone : " << c.phone;
        cout << "\n-----------------------";
    }
}

void searchContact()
{
    string searchName;

    cin.ignore();

    cout << "\nEnter Name To Search : ";
    getline(cin, searchName);

    bool found = false;

    for(auto c : contacts)
    {
        if(c.name == searchName)
        {
            cout << "\nContact Found\n";
            cout << "Name : " << c.name << endl;
            cout << "Phone : " << c.phone << endl;

            found = true;
        }
    }

    if(!found)
    {
        cout << "\nContact Not Found\n";
    }
}

void updateContact()
{
    string searchName;

    cin.ignore();

    cout << "\nEnter Contact Name To Update : ";
    getline(cin, searchName);

    bool found = false;

    for(int i = 0; i < contacts.size(); i++)
    {
        if(contacts[i].name == searchName)
        {
            cout << "Enter New Name : ";
            getline(cin, contacts[i].name);

            cout << "Enter New Phone Number : ";
            getline(cin, contacts[i].phone);

            saveToFile();

            cout << "\nContact Updated Successfully\n";

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "\nContact Not Found\n";
    }
}

void deleteContact()
{
    string searchName;

    cin.ignore();

    cout << "\nEnter Contact Name To Delete : ";
    getline(cin, searchName);

    bool found = false;

    for(int i = 0; i < contacts.size(); i++)
    {
        if(contacts[i].name == searchName)
        {
            contacts.erase(contacts.begin() + i);

            saveToFile();

            cout << "\nContact Deleted Successfully\n";

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "\nContact Not Found\n";
    }
}

int main()
{
    loadFromFile();

    int choice;

    do
    {
        cout << "\n\n===== CONTACT BOOK MANAGEMENT SYSTEM =====";

        cout << "\n1. Add Contact";
        cout << "\n2. Display Contacts";
        cout << "\n3. Search Contact";
        cout << "\n4. Update Contact";
        cout << "\n5. Delete Contact";
        cout << "\n6. Exit";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addContact();
                break;

            case 2:
                displayContacts();
                break;

            case 3:
                searchContact();
                break;

            case 4:
                updateContact();
                break;

            case 5:
                deleteContact();
                break;

            case 6:
                cout << "\nThank You!";
                break;

            default:
                cout << "\nInvalid Choice";
        }

    } while(choice != 6);

    return 0;
}
