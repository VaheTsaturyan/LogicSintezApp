#include "./inc/GUI/mainWindow.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication *app = new QApplication(argc, argv);
    gui::MainWindow *win = new gui::MainWindow();
    win->show();
    return app->exec();


}