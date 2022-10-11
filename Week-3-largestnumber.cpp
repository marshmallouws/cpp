#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int *numbers = new int[n];
    int largest = -1;
    bool isLargestPrinted = false;

    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        numbers[i] = input;

        if(input > largest)
        {
            largest = input;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(!isLargestPrinted && numbers[i] == largest) {
            cout << "*" << numbers[i] << "* ";
        } else {
            cout << numbers[i] << " ";
        }
    }
}