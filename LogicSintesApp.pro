QT += core gui widgets

TARGET = LogicSintesApp
TEMPLATE = app
CONFIG += c++17

# Define paths for better organization
INCLUDEPATH += Application/inc \
               Application/inc/GUI \
               Application/inc/GUI/Components \
               Application/inc/Dacumemnt \
               Application/inc/Menegment

# Source files
SOURCES += \
    Application/main.cpp \
    Application/src/application.cpp \
    Application/src/GUI/mainWindow.cpp \
    Application/src/GUI/Components/dockWidget.cpp \
    Application/src/GUI/Components/fileDialog.cpp \
    Application/src/GUI/Components/toolBar.cpp \
    Application/src/GUI/Components/menu.cpp

# Header files
HEADERS += \
    Application/inc/application.h\
    Application/inc/GUI/mainWindow.h \
    Application/inc/GUI/Components/dockWidget.h \
    Application/inc/GUI/Components/fileDialog.h \
    Application/inc/GUI/Components/toolBar.h \
    Application/inc/GUI/Components/menu.h

# Resources
RESOURCES += \
    Resources.qrc

# Default rules for deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target