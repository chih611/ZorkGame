#include "RoomDefaultEnterCommand.h"
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
                                                                "You are standing in nonplace.\n", nullptr);
    std::shared_ptr<Room> living_room = std::make_shared<Room>("living-room",
                                                               "You are standing in living room.\n", nullptr);
    std::shared_ptr<Room> bed_room = std::make_shared<Room>("bath-room",
                                                            "You are standing in bed room.\n", nullptr);
    std::shared_ptr<Room> kitchen = std::make_shared<Room>("kitchen",
                                                           "You are standing in kitchen\n", nullptr);
    std::shared_ptr<Room> dining_room = std::make_shared<Room>("dining-room",
                                                               "You are standing in dining room\n", nullptr);
    std::shared_ptr<Room> study_room = std::make_shared<Room>("study-room",
                                                              "You are standing in study room\n", nullptr);
    std::shared_ptr<Room> cellar = std::make_shared<Room>("cellar-room",
                                                          "You are standing in cellar\n", nullptr);
    std::shared_ptr<Room> hallway = std::make_shared<Room>("hallway",
                                                           "You are standing in hallway\n", nullptr);
    std::shared_ptr<Room> gallery = std::make_shared<Room>("gallery",
                                                           "You are standing in gallery\n", nullptr);
    std::shared_ptr<Room> attic = std::make_shared<Room>("attic",
                                                         "Kitchen You are standing in attic\n", nullptr);

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

    // GameObject *knifeGameObject = new GameObject("knife", "A sharp knife");
    // RoomDefaultEnterCommand *lookAtKnifeCommand = new RoomDefaultEnterCommand(knifeGameObject);
    // std::shared_ptr<Command> lookAtKnifeSharedPtr(lookAtKnifeCommand);

    Item *kitchen_arround = new Item("kitchen",
                                     "There is a knife on the table.\n");
    // Item *kitchen_items = new Item("knife",
    //                                "This is a sharpest knife in the word\n", lookAtKnifeSharedPtr);
    kitchen->addItem(kitchen_arround);
    ZOOrkEngine zoork(start_foyer);

    zoork.run();

    return 0;
}
