#ifndef LPTWINDOWSAPI_H
#define LPTWINDOWSAPI_H

#include "api/lpt/lptapi.h"

/**
 * @brief The LptWindowsApi class.
 * Provides interface for LPT port on Windows OS
 */
class LptWindowsApi : public LptApi
{

public:
    explicit LptWindowsApi();

/* Inherited from LptApi */
private:
    //@Override
    void setUp();

    //@Override
    bool updateOutput(int);

};

#endif // LPTWINDOWSAPI_H
