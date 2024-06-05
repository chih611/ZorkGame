#ifndef ZOORK_NULLROOM_H
#define ZOORK_NULLROOM_H

#include "Room.h"
#include "RoomDefaultEnterCommand.h"

class NullRoom : public Room
{
public:
    explicit NullRoom(const std::string &n,
                      const std::string &d,
                      std::shared_ptr<RoomDefaultEnterCommand> c) : Room(n,
                                                                         d,
                                                                         nullptr) {}
};

#include "NullRoom.cpp"
#endif // ZOORK_NULLROOM_H
