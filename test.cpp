#include <iostream>
#include <string>
using namespace std;

int main()
{

    string bio;

    cout << "Tell us about yourself: ";

    getline(cin, bio);

    cout << "Your bio says: " << bio;
}