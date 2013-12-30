#ifndef LPTUNIXAPI_H
#define LPTUNIXAPI_H

#include <QObject>
#include "api/lptapi.h"

class LptUnixApi : public LptApi
{

public:
    explicit LptUnixApi(QObject *parent = 0);

signals:

public slots:

};

#endif // LPTUNIXAPI_H
