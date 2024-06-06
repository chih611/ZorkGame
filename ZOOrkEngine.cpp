#include "ZOOrkEngine.h"
#include "NullPassage.h"
#include <utility>

ZOOrkEngine::ZOOrkEngine(std::shared_ptr<Room> start)
{
    player = Player::instance();

    player->setCurrentRoom(start.get());
    Room *currentRoom = player->getCurrentRoom();
    currentRoom->enter();

    std::vector<Item *> items = currentRoom->getRoomItem();
    for (Item *item : items)
    {
        std::cout << item->getDescription() << std::endl;
    }
}

void ZOOrkEngine::run()
{
    while (!gameOver)
    {
        std::cout << "> ";

        std::string input;
        std::getline(std::cin, input);

        std::vector<std::string> words = tokenizeString(input);
        std::string command = words[0];
        std::vector<std::string> arguments(words.begin() + 1, words.end());

        if (command == "go")
        {
            handleGoCommand(arguments);
        }
        else if ((command == "look") || (command == "inspect"))
        {
            handleLookCommand(arguments);
        }
        else if ((command == "take") || (command == "get"))
        {
            handleTakeCommand(arguments);
        }
        else if (command == "drop")
        {
            handleDropCommand(arguments);
        }
        else if (command == "quit")
        {
            handleQuitCommand(arguments);
        }
        else
        {
            std::cout << "I don't understand that command." << std::endl;
        }
    }
}

bool isValueInVector(const std::vector<std::string> &vec, const std::string &value)
{
    for (const std::string &str : vec)
    {
        if (str == value)
        {
            return true; // Value found in the vector
        }
    }
    return false; // Value not found in the vector
}
void ZOOrkEngine::handleGoCommand(std::vector<std::string> arguments)
{
    std::string direction;
    if (arguments[0] == "n" || arguments[0] == "north")
    {
        direction = "north";
    }
    else if (arguments[0] == "s" || arguments[0] == "south")
    {
        direction = "south";
    }
    else if (arguments[0] == "e" || arguments[0] == "east")
    {
        direction = "east";
    }
    else if (arguments[0] == "w" || arguments[0] == "west")
    {
        direction = "west";
    }
    else if (arguments[0] == "u" || arguments[0] == "up")
    {
        direction = "up";
    }
    else if (arguments[0] == "d" || arguments[0] == "down")
    {
        direction = "down";
    }
    else
    {
        direction = arguments[0];
    }
    player = Player::instance();
    Room *currentRoom = player->getCurrentRoom();
    auto passage = currentRoom->getPassage(direction);
    player->setCurrentRoom(passage->getTo());
    if (passage != nullptr)
    {
        passage->enter();
        Room *passageRoom = player->getCurrentRoom();
        std::vector<Item *> items = passageRoom->getRoomItem();
        for (Item *item : items)
        {
            std::cout << item->getDescription() << std::endl;
        }
    }
    else
    {
        auto nullPassage = currentRoom->getNullPassage();
        std::cout << nullPassage->getTo() << direction << std::endl;
    }
}

void ZOOrkEngine::handleLookCommand(std::vector<std::string> arguments)
{
    Room *currentRoom = player->getCurrentRoom();
    std::vector<Item *> items = currentRoom->getRoomItem();
    std::string object;
    bool nothingTolook = false;

    for (Item *item : items)
    {
        object = item->getName();
        if (arguments.size() == 0)
        {
            std::cout << item->getDescription() << std::endl;
            nothingTolook = true;
        }
        else if (object == arguments[0])
        {
            std::cout << item->getDescription() << std::endl;
            nothingTolook = true;
        }
    }
    if (!nothingTolook)
    {
        std::cout << "I only understood you as far as wanting to look." << std::endl;
        nothingTolook = false;
    }
}

void ZOOrkEngine::handleTakeCommand(std::vector<std::string> arguments)
{
    Room *currentRoom = player->getCurrentRoom();
    std::vector<Item *> items = currentRoom->getRoomItem();
    std::string object;
    if (arguments.size() == 0)
    {
        std::cout << "What do you want to take?" << std::endl;
    }
    else
    {
        bool nothingTolook = false;
        for (Item *item : items)
        {
            object = item->getName();
            if (object == arguments[0] && arguments.size() != 0)
            {
                if (item->getAttributeName() == "take")
                {
                    player->addItem(item);
                    currentRoom->removeItem(item);
                    std::cout << "You have taken the " << arguments[0] << "." << std::endl;
                    nothingTolook = true;
                }
                else
                {
                    std::cout << item->getAttributeDescription() << std::endl;
                    nothingTolook = true;
                }
            }
            if (!nothingTolook)
            {
                std::cout << "Item '" << arguments[0] << "' not found in the current room." << std::endl;
                nothingTolook = false;
            }
        }
        // // Assuming the item name to take is the first argument
        // std::string itemNameToTake = arguments[0];

        // // Find the item in the current room's items
        // auto it = std::find_if(items.begin(), items.end(), [&](Item *item)
        //                        { return item->getName() == itemNameToTake && item->getAttribute() == "take"; });

        // if (it != items.end())
        // {
        //     Item *itemToTake = *it;
        //     // Logic to add the item to the player's inventory
        //     player->addItem(itemToTake);
        //     // Remove the item from the room
        //     currentRoom->removeItem(itemToTake);
        //     std::cout << "You have taken the " << itemNameToTake << "." << std::endl;
        // }
        // else
        // {
        //     std::cout << "Item '" << itemNameToTake << "' not found in the current room." << std::endl;
        // }
    }
}

void ZOOrkEngine::handleDropCommand(std::vector<std::string> arguments)
{
    Room *currentRoom = player->getCurrentRoom();
    std::vector<Item *> items = currentRoom->getRoomItem();
    std::vector<Item *> inventory = player->getInventory();
    if (arguments.size() == 0)
    {
        std::cout << "What do you want to drop?" << std::endl;
    }
    std::string itemName = arguments[0];
    auto it = std::find_if(inventory.begin(), inventory.end(), [&](Item *item)
                           { return item->getName() == itemName; });

    if (it != inventory.end())
    {
        Item *itemToDrop = *it;
        player->removeItem(itemToDrop);
        currentRoom->addItem(itemToDrop);
        std::cout << "You have dropped the " << itemName << "." << std::endl;
    }
    else
    {
        std::cout << "You don't have a " << itemName << "." << std::endl;
    }
}

void ZOOrkEngine::handleQuitCommand(std::vector<std::string> arguments)
{
    std::string input;
    std::cout << "Are you sure you want to QUIT?> " << std::endl;
    std::cin >> input;
    std::string quitStr = makeLowercase(input);

    if (quitStr == "y" || quitStr == "yes")
    {
        gameOver = true;
    }
}

std::vector<std::string> ZOOrkEngine::tokenizeString(const std::string &input)
{
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string token;

    while (std::getline(ss, token, ' '))
    {
        tokens.push_back(makeLowercase(token));
    }

    return tokens;
}

std::string ZOOrkEngine::makeLowercase(std::string input)
{
    std::string output = std::move(input);
    // std::transform(output.begin(), output.end(), output.begin(), ::tolower);

    return output;
}
