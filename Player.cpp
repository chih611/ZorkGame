#include "Player.h"

Player *Player::playerInstance = nullptr;

void Player::setCurrentRoom(Room *room)
{
    currentRoom = room;
}

Room *Player::getCurrentRoom() const
{
    return currentRoom;
}

void Player::addItem(Item *itemToTake)
{
    inventory.push_back(itemToTake);
}

void Player::removeItem(Item *item)
{
    auto it = std::remove(inventory.begin(), inventory.end(), item);
    if (it != inventory.end())
    {
        inventory.erase(it, inventory.end());
    }
}

std::vector<Item *> Player::getInventory() const
{
    return inventory;
}
