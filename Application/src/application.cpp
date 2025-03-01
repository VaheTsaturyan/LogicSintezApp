#include "../inc/application.h"

#include <iostream>


MyApplication::MyApplication(int &argc, char **argv) : QApplication(argc, argv)
{

}

MyApplication *MyApplication::instance()
{
    return static_cast<MyApplication*>(QApplication::instance());
}

void MyApplication::saveJsonFile(const QString &path)
{
    std::cout<<path.toStdString()<<std::endl;
}


void MyApplication::addProjectJsonFile(const QString &path)
{
    std::cout<<path.toStdString()<<std::endl;
}


void MyApplication::openJsonFile(const QString &path)
{
    std::cout<<path.toStdString()<<std::endl;
}
