#include <QApplication>
#include <QStyleFactory>

#include "dashboard.h"

#include "api/lptapi.h"
#include "api/lptapifactory.h"

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    //Apply palette and style
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QPalette stylePalette = application.palette();
      stylePalette.setColor(QPalette::Window, QColor(53,53,53));
      stylePalette.setColor(QPalette::Button, QColor(53,53,53));
      stylePalette.setColor(QPalette::Highlight, QColor(142,45,197));
      stylePalette.setColor(QPalette::ButtonText, QColor(255,255,255));
      application.setPalette(stylePalette);

    LptApi *api = (new LptApiFactory())->getLptPortApi();

    Dashboard dashboard;
    dashboard.show();

    return application.exec();
}
