#ifndef LPTWINDOWSAPI_H
#define LPTWINDOWSAPI_H

#include "api/portapi.h"

/**
 * @brief The LptWindowsApi class.
 * Provides interface for LPT port on Windows OS
 */
class LptWindowsApi : public PortApi
{

public:
    explicit LptWindowsApi();

/* Inherited from PortApi */
public:

    //@Override
    void drop();

    //@Override
    void turnOnAll();

    //@Override
    void turnOn(int id);

    //@Override
    void turnOn(QList<int> *ids);

    //@Override
    void turnOff(int id);

    //@Override
    void turnOff(QList<int> *ids);
};

#endif // LPTWINDOWSAPI_H
