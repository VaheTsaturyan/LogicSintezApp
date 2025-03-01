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

    
    // Connect signals from the file menu to slots in MainWindow
    connect(fileMenu,   &FileMenu::newFileRequested,            this, &MainWindow::newFile);
    connect(fileMenu,   &FileMenu::openFileRequested,           this, &MainWindow::openFile);
    connect(fileMenu,   &FileMenu::saveFileRequested,           this, &MainWindow::saveFile);
    connect(fileMenu,   &FileMenu::exitRequested,               this, &MainWindow::close);
    connect(addProject, &AddProjectToolBar::actionTriggered,    this, &MainWindow::addProjectDialog);
}

void MainWindow::initComponents()
{
    fileMenu = new FileMenu(this);
    dockWidget = new LogicGatesDockWidget(this);
    undoRedoToolBar = new UndoRedoToolBar(this);
    addProject = new AddProjectToolBar(this);
    zoom = new ZoomToolBar(this);
}


void MainWindow::addComponents()
{
    addDockWidget(Qt::RightDockWidgetArea, dockWidget);
    addToolBar(Qt::TopToolBarArea, undoRedoToolBar);
    addToolBar(Qt::TopToolBarArea, addProject);
    addToolBar(Qt::TopToolBarArea, zoom);
    menuBar()->addMenu(fileMenu);
}


void MainWindow::newFile()
{
    // Handle new file action
    qDebug() << "New file requested";
}

void MainWindow::openFile()
{
    JsonFileDialog* openDialog = new JsonFileDialog(this);
    openDialog->show();
}

void MainWindow::saveFile()
{
    SaveJsonFileDialog* savedialog = new SaveJsonFileDialog(this);
    savedialog->show();
}

void MainWindow::addProjectDialog()
{
    AddProjectFileDialog* addProjectDialog = new AddProjectFileDialog(this);
    addProjectDialog->show();
}

} // namespace gui