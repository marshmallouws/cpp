#include <iostream>
#include <map>
#include <string>

using namespace std;

bool isPrime(int number)
{
    if (number == 2)
    {
        return true;
    }

    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
}

bool canFactorPrime(int number, int prime)
{
    // eg. number: 60, prime 2
    // canFactor = true
    if (number % prime == 0)
    {
        return true;
    }
    return false;
}

int main()
{
    int input;
    cin >> input;
    int newNumber = input;
    bool canFactor = true;
    string res("");

    map<int, int> factors;

    while (canFactor)
    {
        for (int i = 2; i < input; i++)
        {
            if (i == input - 1)
            {
                canFactor = false;
                break;
            }

            if (isPrime(i))
            {
                if (canFactorPrime(newNumber, i))
                {
                    cout << i;
                    newNumber = newNumber / i;
                    break;
                }
            }
        }
    }
}