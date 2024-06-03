#include "NullCommand.h"

void NullCommand::execute()
{
    std::cout << "Welcome to ZORK.\n";
    std::cout << description;
}
