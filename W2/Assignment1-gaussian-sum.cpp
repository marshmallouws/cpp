#include <iostream>

using namespace std;

int main()
{
    int n;
    int res = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        res += i + 1;
    }
    cout << res;
}