#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    bool isSorted = true;
    int *numbers = new int(n);

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        numbers[i] = input;
        if (i != 0 && input < numbers[i - 1])
        {
            isSorted = false;
        }
    }

    if (isSorted)
    {
        cout << "SORTED";
    }
    else
    {
        cout << "UNSORTED";
    }
}