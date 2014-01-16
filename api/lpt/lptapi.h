#ifndef LPTAPI_H
#define LPTAPI_H

#define ZERO 0b00000000 //No signal on any LPT output
#define MAX_MASK 0b11111111 //Signal '1' on each LPT output
#define MAX_OUTPUTS 8

#include "api/portapi.h"

/**
 * @brief The LptApi class.
 * Provides common functionality to access and use LPT port
 */
class LptApi : PortApi {

/* parameters */
private:
    /**
     * @brief mask - the binnary mask of LPT outputs
     */
    int mask;
/* methods */
public:
    explicit LptApi();

protected:
    int useBinnaryAnd(int);
    int useBinnaryOr(int);
    int getMask(QList<int> *);
    int getInvertedMask(QList<int> *);

/* virtual */
protected:
    virtual void setUp() = 0;
    virtual bool updateOutput(int) = 0;

/* inherited from PortApi */
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

#endif // LPTAPI_H
