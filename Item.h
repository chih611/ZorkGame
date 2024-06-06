#ifndef ZOORK_ITEM_H
#define ZOORK_ITEM_H

#include "Command.h"
#include "GameObject.h"
#include "ItemsDefaultEnterCommand.h"

class Item : public GameObject
{
public:
    Item(const std::string &, const std::string &);

    Item(const std::string &, const std::string &, std::shared_ptr<ItemsDefaultEnterCommand>);

    virtual void use();

    void setUseCommand(std::shared_ptr<ItemsDefaultEnterCommand>);

    std::string getAttributeName();

    std::string getAttributeDescription();

protected:
    std::shared_ptr<ItemsDefaultEnterCommand> useCommand;
};
#include "Item.cpp"
#endif // ZOORK_ITEM_H
