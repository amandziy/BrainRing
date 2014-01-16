#ifndef LPTUNIXAPI_H
#define LPTUNIXAPI_H

#define LPT_BASE 0x378

#include "api/lpt/lptapi.h"

/**
 * @brief The LptUnixApi class.
 * Provides interface for LPT port on unix(-like) systems
 */
class LptUnixApi : public LptApi
{

public:
    explicit LptUnixApi();

/* Inherited from LptApi */
private:
    //@Override
    void setUp();

    //@Override
    bool updateOutput(int);
};

#endif // LPTUNIXAPI_H
