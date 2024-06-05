#ifndef ZOORK_NULLPASSAGE_H
#define ZOORK_NULLPASSAGE_H
#include "Passage.h"

class NullPassage : Passage
{
public:
    // explicit NullPassage(const std::string &n, const std::string &d, Room *from, Room *to) : Passage(n, d, nullptr, nullptr) {}
    NullPassage(const std::string &n, const std::string &d, Room *from, Room *to);
    std::string getTo() const;
    std::string description;
};
#include "NullPassage.cpp"
#endif // ZOORK_NULLPASSAGE_H