#ifndef ZOORK_NULLPASSAGE_H
#define ZOORK_NULLPASSAGE_H
#include "Passage.h"

class NullPassage : public Passage
{
public:
    explicit NullPassage(Room *from);
};
#endif // ZOORK_NULLPASSAGE_H