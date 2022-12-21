#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_
#include <vector>
using namespace std;

class Buffer
{
public:
    virtual void write(int v) = 0;
    virtual int read() = 0;
    virtual ~Buffer();
};

// Task 4(a).  Declare the class SensorBuffer, by extending Buffer
// Write your code here

class SensorBuffer : public Buffer
{
public:
    SensorBuffer(unsigned int n);
    void write(int v);
    int read();
    int readAvg();
    unsigned int writeCount();

private:
    vector<int> data;
    unsigned int n;
    unsigned int writeCounter;
};

#endif /* EX04_LIBRARY_H_ */
