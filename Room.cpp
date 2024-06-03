#include "Passage.h"
#include "Room.h"
#include <iostream>
#include <string>
#include <utility>

Room::Room(const std::string &n, const std::string &d) : Location(n, d) {}

Room::Room(const std::string &n, const std::string &d, std::shared_ptr<RoomDefaultEnterCommand> c) : Location(n, d, std::move(c))
{
    setEnterCommand(std::make_shared<RoomDefaultEnterCommand>(this));
}

void Room::addPassage(const std::string &direction, std::shared_ptr<Passage> p)
{
    passageMap[direction] = std::move(p);
}

// void Room::removePassage(const std::string &direction)
// {
//     if (passageMap.contains(direction))
//     {
//         passageMap.erase(direction);
//     }
// }

std::shared_ptr<Passage> Room::getPassage(const std::string &direction)
{
    auto it = passageMap.find(direction);
    if (it != passageMap.end())
    {
        return it->second; // Return the passage if found
    }
    else
    {
        // std::shared_ptr<NullPassage> p = std::make_shared<NullPassage>(this);
        return nullptr;
    }
}

// std::shared_ptr<NullPassage> Room::getNullPassage(const std::string &direction)
// {
//     std::cout << "It is impossible to go " << direction << "!\n";
//     std::shared_ptr<NullPassage> p = std::make_shared<NullPassage>(this);
//     return p;
// }
