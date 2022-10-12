#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, int> numbers;

    while (true)
    {
        int input;
        cin >> input;
        if (input == 0)
        {
            break;
        }
        else if (input < 1 && input > 1000)
        {
            continue;
        }

        int times = numbers[input];

        cout << numbers[input] << endl;
        numbers[input] += 1;
    }
}