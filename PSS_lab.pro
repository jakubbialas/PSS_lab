#-------------------------------------------------
#
# Project created by QtCreator 2012-03-21T18:04:03
#
#-------------------------------------------------

QT       += core gui

TARGET = PSS_lab
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    discreteobject.cpp \
    objectsiso.cpp \
    liveplot.cpp \
    coerce.cpp \
    modeldata.cpp \
    objectdata.cpp \
    yamlconfigparser.cpp

HEADERS  += mainwindow.h \
    discreteobject.h \
    objectsiso.h \
    liveplot.h \
    coerce.h \
    modeldata.h \
    objectdata.h \
    yamlconfigparser.h

FORMS    += mainwindow.ui


unix: LIBS += -L$$PWD/../../../../usr/local/qwt-6.0.2-svn/lib/ -lqwt

INCLUDEPATH += $$PWD/../../../../usr/local/qwt-6.0.2-svn/include
DEPENDPATH += $$PWD/../../../../usr/local/qwt-6.0.2-svn/include

unix:!macx:!symbian: LIBS += -L$$PWD/../../../../usr/local/lib/ -lyaml-cpp

INCLUDEPATH += $$PWD/../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../usr/local/include

unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/../../../../usr/local/lib/libyaml-cpp.a
