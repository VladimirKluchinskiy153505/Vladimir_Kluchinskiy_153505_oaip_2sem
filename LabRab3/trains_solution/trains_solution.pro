QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_CXXFLAGS += /std:c++latest
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adding.cpp \
    deleting.cpp \
    editing.cpp \
    editingdialog.cpp \
    main.cpp \
    place.cpp \
    widget.cpp

HEADERS += \
    Node.h \
    Shar_Weak.h \
    adding.h \
    deleting.h \
    editing.h \
    editingdialog.h \
    my_deque.h \
    place.h \
    widget.h

FORMS += \
    adding.ui \
    deleting.ui \
    editing.ui \
    editingdialog.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
