#ifndef LPTAPIFACTORY_H
#define LPTAPIFACTORY_H

#include "api/lptapi.h"
#include "api/lptunixapi.h"
#include "api/lptwindowsapi.h"

class LptApiFactory {

private:
    LptApi *lptApi;

public:
    explicit LptApiFactory() { /*default constructor*/ }

    LptApi *getLptPortApi() {
        if (!lptApi) {

        // select system specific API
        #ifdef Q_OS_WIN32 || Q_OS_WIN64
            lptApi = new LptWindowsApi();
        #else
            lptApi = new LptUnixApi();
        #endif

        }
        return lptApi;
    }

};

#endif // LPTAPIFACTORY_H
