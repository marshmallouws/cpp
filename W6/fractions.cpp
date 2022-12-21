#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class fraction
{
private:
    // Internal representation of a fraction as two integers
    int numerator;
    int denominator;

public:
    // Class constructor
    fraction(int n, int d);
    // Methods to update the fraction
    void add(fraction f);
    void mult(fraction f);
    void div(fraction f);
    // Display method
    void display(void);
};

/*
class frac : public fraction
{
private:
    int numerator;
    int denominator;

public:
    frac(int n, int d)
    {
        numerator = n;
        denominator = d;
    }

    void add(fraction f)
    {
    }

    void mult(fraction f)
    {
    }
    void div(fraction f)
    {
    }
};*/
