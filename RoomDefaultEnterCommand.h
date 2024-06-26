//
// Created by Richard Skarbez on 5/7/23.
//

#ifndef ZOORK_ROOMDEFAULTENTERCOMMAND_H
#define ZOORK_ROOMDEFAULTENTERCOMMAND_H

#include "Command.h"

class RoomDefaultEnterCommand : public Command
{
public:
    RoomDefaultEnterCommand() : Command(gameObject) {}
    explicit RoomDefaultEnterCommand(GameObject *g) : Command(g) {}

    void execute() override;
};

#include "RoomDefaultEnterCommand.cpp"
#endif // ZOORK_ROOMDEFAULTENTERCOMMAND_H
