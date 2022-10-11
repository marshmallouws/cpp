#include <iostream>

using namespace std;

int *determineIntervals(int intervals, int highestInput)
{
}

int main()
{
    int intervals;
    int size;
    int *numbers = new int[size];
    int max = 0;

    cin >> intervals;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int input;
        cin >> input;
        numbers[i] = input;

        if (input > max)
        {
            max = input;
        }
    }

    int *intervalsArray = determineIntervals(intervals, max);
}