#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

void increaseSize(vector<int> v, int diff);

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

    if (a.size() != b.size())
    {
        int difference = int(a.size()) - int(b.size());
        if (a.size() > b.size())
        {
            increaseSize(b, difference);
        }
        else
        {
            increaseSize(a, difference);
        }
    }

    int res = 0;
    for (int i = 0; i < a.size(); i++)
    {
        res += a[i] * b[i];
    }

    cout << res;
}

void increaseSize(vector<int> v, int diff)
{
    for (int i = 0; i < diff; i++)
    {
        v.push_back(0);
    }
}