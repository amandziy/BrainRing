#ifndef PORTAPIFACTORY_H
#define PORTAPIFACTORY_H

#include "api/portapi.h"
#include "api/lptunixapi.h"
#include "api/lptwindowsapi.h"

class PortApiFactory {

private:
    PortApi *portApi;

public:
    explicit PortApiFactory() { /*default constructor*/ }

    PortApi *getPortApi() {
        if (!portApi) {

        // select system specific API
        #ifdef Q_OS_WIN32 || Q_OS_WIN64
            portApi = new LptWindowsApi();
        #else
            portApi = new LptUnixApi();
        #endif

        }
        return portApi;
    }

};

#endif // PORTAPIFACTORY_H
