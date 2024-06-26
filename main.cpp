// #include "RoomDefaultEnterCommand.h"
#include "Passage.h"
#include "Player.h"
#include "Room.h"
#include "NullRoom.h"
#include "ZOOrkEngine.h"
#include "Command.h"

int main()
{
    std::shared_ptr<Room> start_foyer = std::make_shared<Room>("foyer",
                                                               "You are standing in foyer.\n");
    std::shared_ptr<Room> nonplace = std::make_shared<NullRoom>("nonplace",
                                                                "You are standing in nonplace.", nullptr);
    std::shared_ptr<Room> living_room = std::make_shared<Room>("living-room",
                                                               "\033[1mLiving room\033[0m\nYou are standing in living room.", nullptr);
    std::shared_ptr<Room> bed_room = std::make_shared<Room>("bath-room",
                                                            "You are standing in bed room.", nullptr);
    std::shared_ptr<Room> kitchen = std::make_shared<Room>("kitchen",
                                                           "\033[1mKitchen\033[0m\nYou are standing in kitchen.", nullptr);
    std::shared_ptr<Room> dining_room = std::make_shared<Room>("dining-room",
                                                               "\033[1mDining room\033[0m\nYou are standing in dining room", nullptr);
    std::shared_ptr<Room> study_room = std::make_shared<Room>("study-room",
                                                              "You are standing in study room", nullptr);
    std::shared_ptr<Room> cellar = std::make_shared<Room>("cellar-room",
                                                          "You are standing in cellar", nullptr);
    std::shared_ptr<Room> hallway = std::make_shared<Room>("hallway",
                                                           "You are standing in hallway", nullptr);
    std::shared_ptr<Room> gallery = std::make_shared<Room>("gallery",
                                                           "You are standing in gallerylook", nullptr);
    std::shared_ptr<Room> attic = std::make_shared<Room>("attic",
                                                         "Kitchen You are standing in attic", nullptr);

    Passage::createBasicPassage(start_foyer.get(), kitchen.get(), "south", true);
    Passage::createBasicPassage(start_foyer.get(), nonplace.get(), "north", true);
    Passage::createBasicPassage(start_foyer.get(), living_room.get(), "east", true);
    Passage::createBasicPassage(start_foyer.get(), bed_room.get(), "west", true);
    Passage::createBasicPassage(kitchen.get(), dining_room.get(), "east", true);
    Passage::createBasicPassage(kitchen.get(), study_room.get(), "south", true);
    Passage::createBasicPassage(kitchen.get(), cellar.get(), "west", true);
    Passage::createBasicPassage(study_room.get(), hallway.get(), "east", true);
    Passage::createBasicPassage(study_room.get(), gallery.get(), "south", true);
    Passage::createBasicPassage(study_room.get(), attic.get(), "west", true);

    GameObject *takeAbleObj = new GameObject("take", "You can take this item!");
    ItemsDefaultEnterCommand *takeAbleCmd = new ItemsDefaultEnterCommand(takeAbleObj, "");
    std::shared_ptr<ItemsDefaultEnterCommand> canTake(takeAbleCmd);
    Item *kitchen_items_knife = new Item("knife",
                                         "There is a sharpest knife in the word.", canTake);
    Item *kitchen_items_table = new Item("table",
                                         "There is a table.", canTake);
    Item *foyer_items = new Item("nothing",
                                 "Oops!, there's nothing to look here");

    Character *thief = new Character("thief",
                                     "A lean and hungry gentleman sneaks into the room.\nHe eyes your belongings greedily.\nThe Thief deftly picks up the jeweled sword.\nBefore you can react, he slips away into the shadows.\n",
                                     std::vector<string>{"steal", "attack"});

    kitchen->addItem(kitchen_items_knife);
    kitchen->addItem(kitchen_items_table);
    start_foyer->addItem(foyer_items);

    living_room->addCharacter(thief);

    ZOOrkEngine zoork(start_foyer);

    zoork.run();

    return 0;
}
