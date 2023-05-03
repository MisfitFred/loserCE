/**
 * @author your name (you@domain.com)
 * @brief
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "iocmd.h"
#include <string>
class iocmd_uci : public  iocmd
{
    iocmd_uci(std::string command)
    {
        this->cmd = command;
    }
    void execute(void);

    private:

    uci *receiver;

};
