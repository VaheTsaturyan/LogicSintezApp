#pragma once
#include <QApplication>
#include <memory>
#include "./Document/document.h"


class MyApplication : public QApplication
{
Q_OBJECT
public:
    explicit MyApplication(int &argc, char **argv);

    static MyApplication* instance();

    std::shared_ptr<doc::Document> getDocument();

public slots:
    void openJsonFile( const QString& path );
    void saveJsonFile( const QString& path );
    void addProjectJsonFile( const QString& path );
    void editorControl( const QString& actionName );

private:
    std::shared_ptr<doc::Document> doc_;
    
};