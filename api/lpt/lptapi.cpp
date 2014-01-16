#include "lptapi.h"

/**
 * @brief LptApi::LptApi.
 */
LptApi::LptApi() : PortApi() {
    mask = ZERO;
}

/**
 * @brief LptApi::useBinnaryAnd - do binnary AND operarion with mask.
 * @param m - submask to apply
 * @return updated mask value
 */
int LptApi::useBinnaryAnd(int m) {
    return (updateOutput(mask & m)) ? (mask & m) : mask;
}

/**
 * @brief LptApi::useBinnaryOr - do binnary OR operation with mask.
 * @param m - submask to apply
 * @return updated mask value
 */
int LptApi::useBinnaryOr(int m) {
    return (updateOutput(mask | m)) ? (mask | m) : mask;
}

/**
 * @brief LptApi::getMask - builds binnary mask.
 * @param outputs - the list of required output ids
 * @return mask
 */
int LptApi::getMask(QList<int> *outputs) {
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
 * @brief LptApi::getInvertedMask - build binnary mask and return inverted value
 * @param outputs - the list of required output ids
 * @return mask
 */
int LptApi::getInvertedMask(QList<int> *outputs) {
    //f.e. 0b01100101 ^ 0b11111111 = 0b10011010
    return getMask(outputs) ^ MAX_MASK;
}


/** Inherited from PortApi */
/**
 * @brief LptApi::drop.
 * Sets Zero-mask on parrallel port outputs
 */
void LptApi::drop() {
    mask = useBinnaryAnd(ZERO);
}

/**
 * @brief LptApi::turnOnAll.
 * Sets Max value on parrallel port outputs
 */
void LptApi::turnOnAll() {
    mask = useBinnaryOr(MAX_MASK);
}

/**
 * @brief LptApi::turnOn.
 * Prepares and sets mask on parallel port for specific output
 *
 * @param id - the output number
 */
void LptApi::turnOn(int id) {
    QList<int> *ids = new QList<int>();
    ids->append(id);
    turnOn(ids);
}

/**
 * @brief LptApi::turnOn.
 * Prepares and sets mask on parallel port for specific outputs
 *
 * @param ids - the list of outputs
 */
void LptApi::turnOn(QList<int> *ids) {
    mask = useBinnaryOr(getMask(ids));
}

/**
 * @brief LptApi::turnOff.
 * Prepares and sets Zero-mask on parallel port for specific output
 *
 * @param id - the output number
 */
void LptApi::turnOff(int id) {
    QList<int> *ids = new QList<int>();
    ids->append(id);
    turnOff(ids);
}

/**
 * @brief LptApi::turnOff.
 * Prepares and sets Zero-mask on parallel port for specific outputs
 *
 * @param id - the list of outputs
 */
void LptApi::turnOff(QList<int> *ids) {
    mask = useBinnaryAnd(getInvertedMask(ids));
}
