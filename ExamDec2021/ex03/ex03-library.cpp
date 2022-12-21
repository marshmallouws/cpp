#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
Hotel::Hotel()
{
    this->roomNames.push_back("Daisy");
    this->roomOccupancy["Daisy"] = {"Alan Smithee", "xyz890"};

    this->roomNames.push_back("Geranium");

    this->roomNames.push_back("Lotus");
    this->roomOccupancy["Lotus"] = {"Kathryn Bigelow", "456abc"};

    this->roomNames.push_back("Orchid");
    this->roomOccupancy["Orchid"] = {"Alan Smithee", "abc123"};

    this->roomNames.push_back("Tulip");
    this->roomOccupancy["Tulip"] = {"Denis Villeneuve", "123xyz"};
}

// Task 3(a).  Implement this method
void Hotel::addRoom(string name)
{
    for (string roomName : roomNames)
    {
        if (roomName == name)
        {
            return;
        }
    }

    roomNames.push_back(name);
}

// Task 3(b).  Implement this method
void Hotel::addGuest(string roomName, string guestName, string guestId)
{
    bool available = false;

    // Check if room exists and if it is occupied
    for (string room : roomNames)
    {
        if (room == roomName && !roomOccupancy.count(roomName))
        {
            available = true;
        }
    }

    if (!available)
    {
        return;
    }

    for (std::map<string, Guest>::iterator it = roomOccupancy.begin(); it != roomOccupancy.end(); ++it)
    {
        if (it->second.id == guestId)
        {
            return;
        }
    }

    roomOccupancy[roomName] = {guestName, guestId};
}

// Task 3(c).  Implement this method
void Hotel::findRoomByGuest(string guestName, string guestId)
{
    for (string room : roomNames)
    {
        if (!roomOccupancy.count(room))
        {
            continue;
        }

        Guest g = roomOccupancy[room];

        bool print = false;
        if (g.name == guestName && g.id == guestId)
        {
            print = true;
        }
        else if (g.name == guestName && guestId == "*")
        {
            print = true;
        }
        else if (guestName == "*" && g.id == guestId)
        {
            print = true;
        }
        else if (guestName == "*" && guestId == "*")
        {
            print = true;
        }

        if (print)
            cout << room << endl;
    }
}

// Do not modify
void Hotel::display()
{
    for (auto it = this->roomNames.begin(); it != this->roomNames.end(); it++)
    {
        cout << "Room '" << *it << "' is ";
        if (this->roomOccupancy.find(*it) == this->roomOccupancy.end())
        {
            cout << "empty" << endl;
        }
        else
        {
            cout << "occupied by " << this->roomOccupancy[*it].name;
            cout << " (id: " << this->roomOccupancy[*it].id << ")" << endl;
        }
    }
}
