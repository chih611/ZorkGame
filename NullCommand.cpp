#include "NullCommand.h"

void NullCommand::execute()
{
    std::cout << "\033[1mWelcome to ZORK.\033[0m\n";
    std::cout << description;
}
