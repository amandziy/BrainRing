#include <QApplication>
#include <QStyleFactory>
#include <QTextCodec>

#include "dashboard.h"

#include "api/portapi.h"
#include "api/portapifactory.h"

/**
 * @brief applyGlobalAppStyle - set application wide style.
 * @param app - the QApplication instance
 */
void applyGlobalAppStyle(QApplication *application) {
    application->setStyle(QStyleFactory::create("Fusion"));
    QPalette stylePalette = application->palette();
      stylePalette.setColor(QPalette::Window, QColor(53,53,53));
      stylePalette.setColor(QPalette::Button, QColor(53,53,53));
      stylePalette.setColor(QPalette::Highlight, QColor(142,45,197));
      stylePalette.setColor(QPalette::ButtonText, QColor(255,255,255));
      application->setPalette(stylePalette);
}

/**
 * @brief applyCharsetEncoding - Setting application charset encoding.
 * @param charset - the encoding name
 */
void applyCharsetEncoding(const char* charset) {
    QTextCodec *codec = QTextCodec::codecForName(charset);
    QTextCodec::setCodecForLocale(codec);
}

/**
 * @brief main
 * @param argc - // -
 * @param argv - // -
 * @return execute result code
 */
int main(int argc, char *argv[])
{
    QApplication *application = new QApplication(argc, argv);

    applyGlobalAppStyle(application);

    applyCharsetEncoding("UTF-8");

    PortApi *portApi = (new PortApiFactory())->getPortApi();

    Dashboard dashboard;
    dashboard.show();

    return application->exec();
}
