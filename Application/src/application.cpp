#include "../inc/application.h"

#include <iostream>
#include "application.h"
#include "../inc/Editor/editor.h"

MyApplication::MyApplication(int &argc, char **argv) : QApplication(argc, argv)
{

}

MyApplication *MyApplication::instance()
{
    return static_cast<MyApplication*>(QApplication::instance());
}

std::shared_ptr<doc::Document> MyApplication::getDocument()
{
    return doc_;
}

void MyApplication::saveJsonFile(const QString &path)
{
    std::cout<<path.toStdString()<<std::endl;
}


void MyApplication::addProjectJsonFile(const QString &path)
{
    std::cout<<path.toStdString()<<std::endl;
}

void MyApplication::editorControl(const QString &actionName)
{
    edt::Editor& editor = edt::Editor::getEditor();
    if( actionName.toStdString() == "redo" ){
        editor.redo();
        return;
    }
    editor.undo();
}

void MyApplication::openJsonFile(const QString &path)
{
    std::cout<<path.toStdString()<<std::endl;
}
