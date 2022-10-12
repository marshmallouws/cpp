#include <iostream>

using namespace std;

int main() {
    // vector dim
    int n;
    cin >> n;

    int *v1 = new int[n];
    int res = 0;

    // vector 1
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v1[i] = input;
    }

    // vector 2 input and calculating dot product
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        res += input * v1[i];
    }
    cout << res; 
}