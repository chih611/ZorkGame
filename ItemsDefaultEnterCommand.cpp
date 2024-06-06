#include "ItemsDefaultEnterCommand.h"

void ItemsDefaultEnterCommand::execute()
{
    std::cout << description << std::endl;
}

std::string ItemsDefaultEnterCommand::getNameObj()
{
    return gameObject->getName();
}

std::string ItemsDefaultEnterCommand::getDescObj()
{
    return gameObject->getDescription();
}
