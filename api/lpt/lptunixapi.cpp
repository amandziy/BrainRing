#include <sys/io.h>
#include <iostream>

#include "lptunixapi.h"

using namespace std;

/**
 * @brief LptUnixApi::LptUnixApi.
 */
LptUnixApi::LptUnixApi() : LptApi() {
    setUp();
}

/**
 * @brief LptUnixApi::setUp - initialize LPT api.
 */
void LptUnixApi::setUp() {
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
    if (!ioperm(LPT_BASE, 1, 1)) {
        outb(m, LPT_BASE);
        cout << "Value:\t" << m << "\thas written to LPT output." << endl;
        return true;
    } else {
        cout << "ERROR: Unable to access LPT port." << endl;
        return false; //temporary
    }
}




