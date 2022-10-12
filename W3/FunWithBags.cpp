#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

void display(set<int> s)
{
    set<int>::iterator itr;

    // Displaying set elements
    for (itr = s.begin();
         itr != s.end(); itr++)
    {
        cout << *itr << " ";
    }
}

int main()
{
    set<int> bag;

    while (true)
    {

        string input;
        getline(cin, input);

        if (input.find("quit") != string::npos)
        {
            break;
        }

        string res[2];
        stringstream ssin(input);

        for (int i = 0; i < 2; i++)
        {
            ssin >> res[i];
        }

        string cmd = res[0];
        int number = stoi(res[1]);

        if (cmd.find("add") != string::npos)
        {
            bag.insert(number);
        }
        else if (cmd.find("qry") != string::npos)
        {
            bag.count(number) == 0 ? cout << "F" : cout << "T";
        }
        else if (cmd.find("del") != string::npos)
        {
            bag.erase(number);
        }
    }
}