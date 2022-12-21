#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
Passenger *find(Passenger *q, unsigned int ticket)
{

    Passenger *tmp;
    tmp = &q[0];

    while (tmp != nullptr)
    {
        Passenger p = *tmp;
        if (p.ticket == ticket)
        {
            return tmp; // Gives the pointer to the specific passenger
        }
        tmp = tmp->next;
    }
    return nullptr;
}

// Task 2(b).  Implement this function
Passenger *remove(Passenger *q, unsigned int ticket)
{
    Passenger *tmp, *prev;
    tmp = &q[0];
    prev = nullptr;

    while (tmp != nullptr && (*tmp).ticket != ticket)
    {
        prev = tmp;
        tmp = tmp->next;

        // ticket not found
        if (tmp == nullptr)
            return q;
    }
    if (prev == nullptr && (*tmp).ticket == ticket)
    {
        q = tmp->next;
        return q;
    }
    prev->next = tmp->next;

    return q;
}

// Task 2(c).  Implement this function
Passenger *priority(Passenger *q)
{
    if (q == nullptr)
    {
        return nullptr; // We reached the end of the list
    }
    else if (!q->priority)
    {
        // We skip the passenger
        return priority(q->next);
    }
    else
    {
        // We create a new list, copying the contents of q
        Passenger *p = new Passenger;
        p->name = q->name;
        p->ticket = q->ticket;
        p->priority = q->priority;
        p->next = priority(q->next);
        return p;
    }
}

// Do not modify
void displayQueue(Passenger *q)
{
    if (q == nullptr)
    {
        return;
    }
    cout << q->name << " - ticket: " << q->ticket;
    if (q->priority)
    {
        cout << " (priority)";
    }
    cout << endl;
    displayQueue(q->next);
}
