#include "../../inc/GUI/mainWindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QDebug>
#include "mainWindow.h"

namespace gui
{
    
    
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    initComponents();
    addComponents();
    connectSignals();
    
    // Connect signals from the file menu to slots in MainWindow
    //connect(fileMenu,   &FileMenu::newFileRequested,            this, &MainWindow::newFile);
    //connect(fileMenu,   &FileMenu::openFileRequested,           this, &MainWindow::openFile);
    //connect(fileMenu,   &FileMenu::saveFileRequested,           this, &MainWindow::saveFile);
    //connect(fileMenu,   &FileMenu::exitRequested,               this, &MainWindow::close);
    //connect(addProject, &AddProjectToolBar::actionTriggered,    this, &MainWindow::addProjectDialog);
}

void MainWindow::initComponents()
{
    fileMenu = new FileMenu(this);
    dockWidget = new LogicGatesDockWidget(this);
    undoRedoToolBar = new UndoRedoToolBar(this);
    addProject = new AddProjectToolBar(this);
    zoom = new ZoomToolBar(this);
    
    circuitView = new CircuitDesignView(this);
}


void MainWindow::addComponents()
{
    addDockWidget(Qt::RightDockWidgetArea, dockWidget);
    addToolBar(Qt::TopToolBarArea, undoRedoToolBar);
    addToolBar(Qt::TopToolBarArea, addProject);
    addToolBar(Qt::TopToolBarArea, zoom);
    menuBar()->addMenu(fileMenu);

    setCentralWidget(circuitView);
}


void MainWindow::connectSignals()
{
    // Connect existing signals
    connect(fileMenu, &FileMenu::newFileRequested, this, &MainWindow::newFile);
    connect(fileMenu, &FileMenu::openFileRequested, this, &MainWindow::openFile);
    connect(fileMenu, &FileMenu::saveFileRequested, this, &MainWindow::saveFile);
    connect(fileMenu, &FileMenu::exitRequested, this, &MainWindow::close);
    connect(addProject, &AddProjectToolBar::actionTriggered, this, &MainWindow::addProjectDialog);
    
    // Connect new signals
    
    // Zoom actions
    connect(zoom, &ZoomToolBar::actionTriggered, this, &MainWindow::zoomH);
    //connect(zoom, SIGNAL(zoomOutTriggered()), this, SLOT(zoomOut()));
    //connect(zoom, SIGNAL(resetZoomTriggered()), this, SLOT(resetZoom()));
    
    // Logic gates dock widget
    connect(dockWidget, SIGNAL(logicGateSelected(const QString&)), 
            this, SLOT(addLogicGate(const QString&)));
    
    // Undo/Redo actions
    connect(circuitView, &CircuitDesignView::sceneChanged, 
            this, &MainWindow::updateUndoRedoActions);
    
    // Connect undo/redo toolbar to QUndoStack (assuming it has one)
    // This would depend on your UndoRedoToolBar implementation
    // connect(undoRedoToolBar, SIGNAL(undoTriggered()), undoStack, SLOT(undo()));
    // connect(undoRedoToolBar, SIGNAL(redoTriggered()), undoStack, SLOT(redo()));
}


void MainWindow::newFile()
{
    // Handle new file action
    circuitView->clearScene();
    qDebug() << "New file requested";
}

void MainWindow::openFile()
{
    JsonFileDialog* openDialog = new JsonFileDialog(this);
    openDialog->show();
    //delete openDialog;
}

void MainWindow::saveFile()
{
    SaveJsonFileDialog* saveDialog = new SaveJsonFileDialog(this);
    saveDialog->show();
    //delete saveDialog;
}

void MainWindow::addProjectDialog()
{
    AddProjectFileDialog* addProjectDialog = new AddProjectFileDialog(this);
    addProjectDialog->show();
    //delete addProjectDialog;
}

void MainWindow::zoomH(const QString &eventName)
{
    if(eventName == "zoomIn" ){
        circuitView->zoomIn();
    }else if("zoomOut"){
        circuitView->zoomOut();
    }else if("resetZoom"){
        circuitView->resetZoom();
    }
}
/*
void MainWindow::zoomIn()
{
}

void MainWindow::zoomOut()
{
}

void MainWindow::resetZoom()
{
}
*/
void MainWindow::addLogicGate(const QString &gateType)
{
    circuitView->addLogicGate(gateType);
}

void MainWindow::updateUndoRedoActions()
{
    // Update undo/redo actions based on changes to the scene
    // This would depend on your UndoRedoToolBar implementation
    // undoRedoToolBar->setUndoEnabled(undoStack->canUndo());
    // undoRedoToolBar->setRedoEnabled(undoStack->canRedo());
}


} // namespace gui