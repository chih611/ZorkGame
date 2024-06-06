
#include "Character.h"

#include <random>
#include <chrono>

Character::Character(const std::string &n, const std::string &d, std::vector<string> t) : GameObject(n, d), tags(t) {}

string Character::getSpecificCharactersTags(string c)
{
    for (const std::string &tag : tags)
    {
        if (tag == c)
        {
            return tag;
        }
        else
        {
            return "nothing";
        }
    }
}

void Character::addTag(const std::string &tag)
{
    if (std::find(tags.begin(), tags.end(), tag) == tags.end())
    {
        tags.push_back(tag);
    }
}
void Character::steal(std::vector<Item *> &items, Player *player)
{
    if (items.empty())
    {
        std::cout << "Nothing to steal!" << std::endl;
        return;
    }

    // Generate a random index
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, items.size() - 1);

    int randomIndex = dis(gen);
    Item *stolenItem = items[randomIndex];

    // Add the stolen item to the inventory
    inventory.push_back(stolenItem);

    // Remove the stolen item from the original list
    items.erase(items.begin() + randomIndex);

    // player->removeItem(stolenItem);
    stolen = stolenItem;
    std::cout
        << "Thief has stolen your " << stolenItem->getName() << "!" << std::endl;
}
Item *Character::getStolenItem()
{
    return stolen;
}

void Character::printInventory() const
{
    std::cout << "Thief's inventory contains:" << std::endl;
    for (const Item *item : inventory)
    {
        std::cout << "- " << item->getName() << ": " << item->getDescription() << std::endl;
    }
}