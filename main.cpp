#include <QtWidgets/QApplication>

#include "audio.h"


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Audio *audio = new Audio();
    audio->show();

    int returnCode = app.exec();
    delete audio;

    return returnCode;
}
