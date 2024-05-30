// #include "NullPassage.h"
#include "Room.h"
#include <string>
#include <utility>

Room::Room(const std::string &n, const std::string &d) : Location(n, d)
{
    std::shared_ptr<RoomDefaultEnterCommand> enterCommand = std::make_shared<RoomDefaultEnterCommand>(this);
    enterCommand->execute();
}

// Room::Room(const std::string &n, const std::string &d, std::shared_ptr<Command> c) : Location(n, d, std::move(c)) {}

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
    // if (passageMap.contains(direction))
    // {
    //     return passageMap[direction];
    // }
    // else
    // {
    //     std::cout << "It is impossible to go " << direction << "!\n";
    //     return std::make_shared<NullPassage>(this);
    // }
    auto it = passageMap.find(direction);
    if (it != passageMap.end())
    {
        return it->second; // Return the passage if found
    }
    return nullptr;
}
