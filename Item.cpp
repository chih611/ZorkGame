#include "Item.h"

#include <utility>

Item::Item(const std::string &n, const std::string &d) : GameObject(n, d),
                                                         useCommand(std::make_shared<ItemsDefaultEnterCommand>(this, d)) {}

Item::Item(const std::string &n, const std::string &d, std::shared_ptr<ItemsDefaultEnterCommand> c) : GameObject(n, d),
                                                                                                      useCommand(std::move(c)) {}

void Item::use()
{
    useCommand->execute();
}

std::string Item::getAttributeName()
{
    return useCommand->getNameObj();
}
std::string Item::getAttributeDescription()
{
    return useCommand->getDescObj();
}
void Item::setUseCommand(std::shared_ptr<ItemsDefaultEnterCommand> c)
{
    useCommand = c;
}