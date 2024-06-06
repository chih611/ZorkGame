#include "Passage.h"
#include <iostream>
#include <string>
#include <utility>

Room::Room(const std::string &n, const std::string &d) : Location(n, d) {}

Room::Room(const std::string &n, const std::string &d, std::shared_ptr<RoomDefaultEnterCommand> c) : Location(n, d, std::move(c))
{
    setEnterCommand(std::make_shared<RoomDefaultEnterCommand>(this));
}

void Room::addItem(Item *item)
{
    items.push_back(item);
}

void Room::removeItem(Item *item)
{
    auto it = std::find(items.begin(), items.end(), item);
    if (it != items.end())
    {
        items.erase(it);
    }
}
std::vector<Item *> Room::getRoomItem()
{
    return items;
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
        return it->second;
    }
    else
    {
        return nullptr;
    }
}

std::shared_ptr<NullPassage> Room::getNullPassage()
{
    return std::make_shared<NullPassage>("null-passage", "It is impossible to go ", nullptr, nullptr);
}
