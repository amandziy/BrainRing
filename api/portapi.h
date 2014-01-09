#ifndef PORTAPI_H
#define PORTAPI_H

#include <QList>

/**
 * @brief The PortApi class.
 * Common interface for all possible ports that can be used in APP purposes
 */
class PortApi
{

protected:
    explicit PortApi() {
        //default constructor
    }

public:

    /**
     * @brief drop - turn off all outputs
     */
    virtual void drop() = 0;

    /**
     * @brief turnOnAll - turn on all outputs
     */
    virtual void turnOnAll() = 0;

    /**
     * @brief turnOn - turn on the output
     * @param id - the output id
     */
    virtual void turnOn(int id) = 0;

    /**
     * @brief turnOn - turn on few outputs
     * @param ids - list of outputs
     */
    virtual void turnOn(QList<int> *ids) = 0;

    /**
     * @brief turnOff - turn off the output
     * @param id - the output id
     */
    virtual void turnOff(int id) = 0;

    /**
     * @brief turnOff - turn off few outputs
     * @param ids - list of outputs
     */
    virtual void turnOff(QList<int> *ids) = 0;

};

#endif // PORTAPI_H
