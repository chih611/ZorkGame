#ifndef ZOORK_ROOM_H
#define ZOORK_ROOM_H

#include "Character.h"
// #include "NullPassage.h"
#include "RoomDefaultEnterCommand.h"
#include "Item.h"
#include "Room.h"
#include "Location.h"
#include <map>
#include <string>
#include <tuple>
class Passage;
class NullPassage;
class Room : public Location
{
public:
    Room(const std::string &, const std::string &);

    Room(const std::string &, const std::string &, std::shared_ptr<RoomDefaultEnterCommand>);

    void addItem(Item *);
    //    void removeItem(const std::string&);
    std::vector<Item *> getRoomItem(const std::string &);
    //    Item* retrieveItem(const std::string&);
    //    void addCharacter(Character*);
    //    void removeCharacter(const std::string&);
    //    Character* getCharacter(const std::string&);

    void addPassage(const std::string &, std::shared_ptr<Passage>);

    // void removePassage(const std::string &);

    std::shared_ptr<Passage> getPassage(const std::string &);

    std::shared_ptr<NullPassage> getNullPassage();

protected:
    std::vector<Item *> items;
    std::vector<Character *> characters;
    std::map<std::string, std::shared_ptr<Passage>> passageMap;
};
#include "Room.cpp"
#endif // ZOORK_ROOM_H
