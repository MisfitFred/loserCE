/**
 * @author your name (you@domain.com)
 * @brief
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <string>
class iocmd
{
public:
    virtual ~iocmd();
    virtual void execute(void) = 0;
 
protected:
    iocmd() {};
    std::string cmd;
};
