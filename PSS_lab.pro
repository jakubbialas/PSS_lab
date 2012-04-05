#-------------------------------------------------
#
# Project created by QtCreator 2012-03-21T18:04:03
#
#-------------------------------------------------

QT       += core gui

TARGET = PSS_lab
TEMPLATE = app


SOURCES += main.cpp\
    gui/mainwindow.cpp \
    gui/liveplot.cpp \
    object/discreteobject.cpp \
    object/objectsiso.cpp \
    object/modeldata.cpp \
    object/objectdata.cpp \
    object/nonstationarydiscreteobject.cpp \
    file/yamlconfigparser.cpp \
    simulation/simulation.cpp \
    controller/controller.cpp \
    controller/controllerp.cpp \
    source/trianglesource.cpp \
    source/stepsource.cpp \
    source/squaresource.cpp \
    source/source.cpp \
    source/sinussource.cpp \
    source/noisesource.cpp \
    source/multisource.cpp \
    source/impulssource.cpp

HEADERS  += gui/mainwindow.h \
    gui/liveplot.h \
    object/discreteobject.h \
    object/objectsiso.h \
    object/modeldata.h \
    object/objectdata.h \
    object/nonstationarydiscreteobject.h \
    file/yamlconfigparser.h \
    simulation/simulation.h \
    controller/controller.h \
    controller/controllerp.h \
    source/trianglesource.h \
    source/stepsource.h \
    source/squaresource.h \
    source/source.h \
    source/sinussource.h \
    source/noisesource.h \
    source/multisource.h \
    source/impulssource.h

FORMS    += gui/mainwindow.ui


unix: LIBS += -L$$PWD/../../../../usr/local/qwt-6.0.2-svn/lib/ -lqwt

INCLUDEPATH += $$PWD/../../../../usr/local/qwt-6.0.2-svn/include
DEPENDPATH += $$PWD/../../../../usr/local/qwt-6.0.2-svn/include

unix:!macx:!symbian: LIBS += -L$$PWD/../../../../usr/local/lib/ -lyaml-cpp

INCLUDEPATH += $$PWD/../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../usr/local/include

unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/../../../../usr/local/lib/libyaml-cpp.a
