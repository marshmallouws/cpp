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

    // Inplace sort
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (auto v : a)
    {
        cout << v << " ";
    }

    for (auto v : b)
    {
        cout << v << " ";
    }
}