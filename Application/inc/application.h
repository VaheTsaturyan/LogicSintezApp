#pragma once

#include <QApplication>


class MyApplication : public QApplication
{
Q_OBJECT
public:
    explicit MyApplication(int &argc, char **argv);

    static MyApplication* instance();

public slots:
    void openJsonFile(const QString& path);
    void saveJsonFile(const QString& path);
    void addProjectJsonFile(const QString& path);

private:

};