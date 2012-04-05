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
    simulation/simulation.cpp \
    simulation/configuration.cpp \
    simulation/object/discreteobject.cpp \
    simulation/object/objectsiso.cpp \
    simulation/object/modeldata.cpp \
    simulation/object/objectdata.cpp \
    simulation/object/nonstationarydiscreteobject.cpp \
    simulation/controller/controller.cpp \
    simulation/controller/controllerp.cpp \
    simulation/source/trianglesource.cpp \
    simulation/source/stepsource.cpp \
    simulation/source/squaresource.cpp \
    simulation/source/source.cpp \
    simulation/source/sinussource.cpp \
    simulation/source/noisesource.cpp \
    simulation/source/multisource.cpp \
    simulation/source/impulssource.cpp

HEADERS  += gui/mainwindow.h \
    gui/liveplot.h \
    simulation/simulation.h \
    simulation/configuration.h \
    simulation/object/discreteobject.h \
    simulation/object/objectsiso.h \
    simulation/object/modeldata.h \
    simulation/object/objectdata.h \
    simulation/object/nonstationarydiscreteobject.h \
    simulation/controller/controller.h \
    simulation/controller/controllerp.h \
    simulation/source/trianglesource.h \
    simulation/source/stepsource.h \
    simulation/source/squaresource.h \
    simulation/source/source.h \
    simulation/source/sinussource.h \
    simulation/source/noisesource.h \
    simulation/source/multisource.h \
    simulation/source/impulssource.h \
    simulation/object/tool.h

FORMS    += gui/mainwindow.ui


unix: LIBS += -L$$PWD/../../../../usr/local/qwt-6.0.2-svn/lib/ -lqwt

INCLUDEPATH += $$PWD/../../../../usr/local/qwt-6.0.2-svn/include
DEPENDPATH += $$PWD/../../../../usr/local/qwt-6.0.2-svn/include

unix:!macx:!symbian: LIBS += -L$$PWD/../../../../usr/local/lib/ -lyaml-cpp

INCLUDEPATH += $$PWD/../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../usr/local/include

unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/../../../../usr/local/lib/libyaml-cpp.a
