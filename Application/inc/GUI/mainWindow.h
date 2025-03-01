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
    // New slots to handle zoom actions
    void zoomH(const QString& eventName);
    
    // New slot to handle logic gate addition
    void addLogicGate(const QString &gateType);
    
    // New slots for undo/redo
    void updateUndoRedoActions();

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
