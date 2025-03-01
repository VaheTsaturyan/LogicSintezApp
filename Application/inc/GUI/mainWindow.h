#pragma once 
#include <QMainWindow>
#include "./Components/dockWidget.h"
#include "./Components/fileDialog.h"
#include "./Components/toolBar.h"
#include "./Components/menu.h"

namespace gui
{
 
class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
private:
    void initComponents();
    void addComponents();

private slots:
    void newFile();
    void openFile();
    void saveFile();

private:
    LogicGatesDockWidget* dockWidget;    
    UndoRedoToolBar* undoRedoToolBar;
    AddProjectToolBar* addProject;
    ZoomToolBar* zoom;
    FileMenu *fileMenu;
};
    

} // namespace gui
