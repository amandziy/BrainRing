#include "lptunixapi.h"

/**
 * @brief LptUnixApi::LptUnixApi.
 */
LptUnixApi::LptUnixApi() : PortApi() {
    setUp();
}

/**
 * @brief LptUnixApi::setUp - initialize LPT api.
 */
void LptUnixApi::setUp() {
    mask = ZERO;
    if (!updateOutput(ZERO)) {
        // TODO: add logging for failed update
    }
}

/**
 * @brief LptUnixApi::updateOutput - set mask to outputs.
 * @param m - the mask to set
 * @return 'true' if operation was successfull
 */
bool LptUnixApi::updateOutput(int m) {
    // TODO: provide implementation
    return true; //temporary
}

/**
 * @brief LptUnixApi::useBinnaryAnd - do binnary AND operarion with mask.
 * @param m - submask to apply
 * @return updated mask value
 */
int LptUnixApi::useBinnaryAnd(int m) {
    return (updateOutput(mask & m)) ? (mask & m) : mask;
}

/**
 * @brief LptUnixApi::useBinnaryOr - do binnary OR operation with mask.
 * @param m - submask to apply
 * @return updated mask value
 */
int LptUnixApi::useBinnaryOr(int m) {
    return (updateOutput(mask | m)) ? (mask | m) : mask;
}

/**
 * @brief LptUnixApi::getMask - builds binnary mask.
 * @param outputs - the list of required output ids
 * @return mask
 */
int LptUnixApi::getMask(QList<int> *outputs) {
    int m = ZERO;
    if (outputs && !outputs->isEmpty()) {
        foreach (int out, *outputs) {
            if (out > 0 && 1 <= MAX_OUTPUTS) {
                m = m | (1 << (out-1));
            } else {
                //TODO: log warn
            }
        }
    } else {
        // TODO: log warn
    }
    return m;
}

/**
 * @brief LptUnixApi::getInvertedMask - build binnary mask and return inverted value
 * @param outputs - the list of required output ids
 * @return mask
 */
int LptUnixApi::getInvertedMask(QList<int> *outputs) {
    //f.e. 0b01100101 ^ 0b11111111 = 0b10011010
    return getMask(outputs) ^ MAX_MASK;
}


/* == Inherited from PortApi == */
/**
 * @brief LptUnixApi::drop.
 * Sets Zero-mask on parrallel port outputs
 */
void LptUnixApi::drop() {
    mask = useBinnaryAnd(ZERO);
}

/**
 * @brief LptUnixApi::turnOnAll.
 * Sets Max value on parrallel port outputs
 */
void LptUnixApi::turnOnAll() {
    mask = useBinnaryOr(MAX_MASK);
}

/**
 * @brief LptUnixApi::turnOn.
 * Prepares and sets mask on parallel port for specific output
 *
 * @param id - the output number
 */
void LptUnixApi::turnOn(int id) {
    QList<int> *ids = new QList<int>();
    ids->append(id);
    turnOn(ids);
}

/**
 * @brief LptUnixApi::turnOn.
 * Prepares and sets mask on parallel port for specific outputs
 *
 * @param ids - the list of outputs
 */
void LptUnixApi::turnOn(QList<int> *ids) {
    mask = useBinnaryOr(getMask(ids));
}

/**
 * @brief LptUnixApi::turnOff.
 * Prepares and sets Zero-mask on parallel port for specific output
 *
 * @param id - the output number
 */
void LptUnixApi::turnOff(int id) {
    QList<int> *ids = new QList<int>();
    ids->append(id);
    turnOff(ids);
}

/**
 * @brief LptUnixApi::turnOff.
 * Prepares and sets Zero-mask on parallel port for specific outputs
 *
 * @param id - the list of outputs
 */
void LptUnixApi::turnOff(QList<int> *ids) {
    mask = useBinnaryAnd(getInvertedMask(ids));
}




