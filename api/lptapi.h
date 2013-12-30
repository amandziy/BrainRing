#ifndef LPTAPI_H
#define LPTAPI_H

#include <QObject>

class LptApi : public QObject
{
    Q_OBJECT

public:
    explicit LptApi(QObject *parent = 0) {
        LptApi::setParent(parent);
    }

signals:

public slots:

};

#endif // LPTAPI_H
