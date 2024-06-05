#ifndef ZOORK_ITEM_H
#define ZOORK_ITEM_H

#include "Command.h"
#include "GameObject.h"
#include "ItemsDefaultEnterCommand.h"

class Item : public GameObject
{
public:
    Item(const std::string &, const std::string &);

    Item(const std::string &, const std::string &, std::shared_ptr<Command>);

    virtual void use();

    void setUseCommand(std::shared_ptr<Command>);

protected:
    std::shared_ptr<Command> useCommand;
};
#include "Item.cpp"
#endif // ZOORK_ITEM_H
