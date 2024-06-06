#ifndef ZOORK_ITEMSDEFAULTENTERCOMMAND_H
#define ZOORK_ITEMSDEFAULTENTERCOMMAND_H

#include "Command.h"
#include "Item.h"
#include <utility>

class ItemsDefaultEnterCommand : public Command
{
public:
    ItemsDefaultEnterCommand() : Command(gameObject) {}
    explicit ItemsDefaultEnterCommand(GameObject *g, const std::string &d) : Command(g), description(d) {}

    void execute() override;

    std::string getNameObj();

    std::string getDescObj();

private:
    std::string description;
};

#include "ItemsDefaultEnterCommand.cpp"
#endif // ZOORK_ItemsDefaultEnterCommand_H
