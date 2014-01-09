#ifndef LPTUNIXAPI_H
#define LPTUNIXAPI_H

#define ZERO 0b00000000 //No signal on any LPT output
#define MAX_MASK 0b11111111 //Signal '1' on each LPT output
#define MAX_OUTPUTS 8

#include "api/portapi.h"

/**
 * @brief The LptUnixApi class.
 * Provides interface for LPT port on unix(-like) systems
 */
class LptUnixApi : public PortApi
{

/* parametes */
private:
    /**
     * @brief mask - the binnary mask of LPT outputs
     */
    int mask;

/* methods */
public:
    explicit LptUnixApi();

private:
    void setUp();

    bool updateOutput(int);
    int useBinnaryAnd(int);
    int useBinnaryOr(int);
    int getMask(QList<int> *);
    int getInvertedMask(QList<int> *);

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

#endif // LPTUNIXAPI_H
