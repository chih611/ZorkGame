#include "Location.h"

Location::Location(const std::string &n, const std::string &d) : GameObject(n, d),
                                                                 enterCommand(std::make_shared<NullCommand>(d)) {}

Location::Location(const std::string &n, const std::string &d, std::shared_ptr<RoomDefaultEnterCommand> c) : GameObject(n, d),
                                                                                                             enterCommand(
                                                                                                                 std::move(c)) {}

void Location::enter()
{
    enterCommand->execute();
}

void Location::setEnterCommand(std::shared_ptr<Command> c)
{
    enterCommand = std::move(c);
}