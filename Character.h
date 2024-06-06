#ifndef ZOORK_CHARACTER_H
#define ZOORK_CHARACTER_H

#include "GameObject.h"
#include "Item.h"
#include <vector>
using namespace std;
class Player;
class Character : public GameObject
{
public:
    Item *stolen;
    Character(const std::string &, const std::string &, std::vector<string> tags);
    string getSpecificCharactersTags(string);
    void addTag(const std::string &t);
    void steal(std::vector<Item *> &, Player *);
    void printInventory() const;
    Item *getStolenItem();

protected:
    std::vector<Item *>
        inventory;
    std::vector<std::string> tags;

    //    int health;
    //    int attack;
    //    int move;
    //    int initiative;
};
#include "Character.cpp"
#endif // ZOORK_CHARACTER_H
