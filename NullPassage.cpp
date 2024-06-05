#include "NullPassage.h"

NullPassage::NullPassage(const std::string &n, const std::string &d, Room *from, Room *to) : Passage(n, d, nullptr, nullptr)
{
    NullPassage::description = d;
}
std::string NullPassage::getTo() const
{
    return description;
}