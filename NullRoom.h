#ifndef ZOORK_NULLROOM_H
#define ZOORK_NULLROOM_H

#include "Room.h"
#include "NullCommand.h"

class NullRoom : public Room
{
public:
    // NullRoom(const std::string, const std::string, const NullCommand &);
    NullRoom();
};

#include "NullRoom.cpp"
#endif // ZOORK_NULLROOM_H
