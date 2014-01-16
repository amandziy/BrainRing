#include "lptwindowsapi.h"

/**
 * @brief LptWindowsApi::LptWindowsApi
 */
LptWindowsApi::LptWindowsApi() : LptApi() {
    setUp();
}

/**
 * @brief LptWindowsApi::setUp - initialize LPT api.
 */
void LptWindowsApi::setUp() {
    if (!updateOutput(ZERO)) {
        // TODO: add logging for failed update
    }
}

/**
 * @brief LptWindowsApi::updateOutput - set mask to outputs.
 * @param m - the mask to set
 * @return 'true' if operation was successfull
 */
bool LptWindowsApi::updateOutput(int m) {
    // TODO: provide implementation
    return true; //temporary
}
