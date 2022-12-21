#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    vector<int> a;
    vector<int> b;

    while (true)
    {

        string dataset;
        cin >> dataset;

        int value;
        cin >> value;

        if (cin.fail())
        {
            break;
        }

        if (dataset == "a")
        {
            a.push_back(value);
        }
        else
        {
            b.push_back(value);
        }
    }

    int size = a.size() + b.size();

    for (int i = 0; i < size; i++)
    {
        if (a.size() != 0)
        {
            cout << a.front() << " ";
            a.erase(a.begin());
        }
        if (b.size() != 0)
        {
            cout << b.front() << " ";
            b.erase(b.begin());
        }
    }
}