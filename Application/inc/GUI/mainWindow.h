#pragma once 
#include <QMainWindow>
#include "./Components/dockWidget.h"
#include "./Components/fileDialog.h"
#include "./Components/toolBar.h"
#include "./Components/menu.h"
#include "./Components/circuitdesignview.h"

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
    void connectSignals();


private slots:
    void newFile();
    void openFile();
    void saveFile();
    void addProjectDialog();
    void zoomH(const QString& eventName);
    void addLogicGate(const QString &gateType);
    void updateUndoRedoActions();
    void redoActions(const QString& actionName);

private:
    LogicGatesDockWidget* dockWidget;    
    UndoRedoToolBar* undoRedoToolBar;
    AddProjectToolBar* addProject;
    ZoomToolBar* zoom;
    FileMenu *fileMenu;

    // New central widget
    CircuitDesignView *circuitView;
};
    

} // namespace gui
