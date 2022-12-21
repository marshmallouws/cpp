#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of SensorBuffer's
//             constructor and methods

// Task 4(b).  Write a working implementation of write() and writeCount()

// Task 4(c).  Write a working implementation of read()

// Task 4(d).  Write a working implementation of readAvg()

SensorBuffer::SensorBuffer(unsigned int n)
{
    this->n = n;
    this->writeCounter = 0;
}

void SensorBuffer::write(int v)
{
    data.push_back(v);
    writeCounter++;
}

unsigned int SensorBuffer::writeCount()
{
    return writeCounter;
}

int SensorBuffer::read()
{
    if (writeCounter == 0)
    {
        return 0;
    }
    return data.back();
}

int SensorBuffer::readAvg()
{
    if (writeCounter == 0)
    {
        return 0;
    }

    int elem = writeCounter < n ? writeCounter : n;
    int res = 0;
    auto tmp = data;
    for (int i = 0; i < elem; i++)
    {
        res += tmp.back();
        tmp.pop_back();
    }
    return res / elem;
}

// Do not modify
Buffer::~Buffer()
{
    // Empty destructor
}
