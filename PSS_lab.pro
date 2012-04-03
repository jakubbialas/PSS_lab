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
    modeldata.cpp \
    objectdata.cpp \
    yamlconfigparser.cpp \
    simulation.cpp \
    nonstationarydiscreteobject.cpp \
    controller.cpp \
    controllerp.cpp \
    source/trianglesource.cpp \
    source/stepsource.cpp \
    source/squaresource.cpp \
    source/source.cpp \
    source/sinussource.cpp \
    source/noisesource.cpp \
    source/multisource.cpp \
    source/impulssource.cpp

HEADERS  += mainwindow.h \
    discreteobject.h \
    objectsiso.h \
    liveplot.h \
    modeldata.h \
    objectdata.h \
    yamlconfigparser.h \
    simulation.h \
    nonstationarydiscreteobject.h \
    controller.h \
    controllerp.h \
    source/trianglesource.h \
    source/stepsource.h \
    source/squaresource.h \
    source/source.h \
    source/sinussource.h \
    source/noisesource.h \
    source/multisource.h \
    source/impulssource.h

FORMS    += mainwindow.ui


unix: LIBS += -L$$PWD/../../../../usr/local/qwt-6.0.2-svn/lib/ -lqwt

INCLUDEPATH += $$PWD/../../../../usr/local/qwt-6.0.2-svn/include
DEPENDPATH += $$PWD/../../../../usr/local/qwt-6.0.2-svn/include

unix:!macx:!symbian: LIBS += -L$$PWD/../../../../usr/local/lib/ -lyaml-cpp

INCLUDEPATH += $$PWD/../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../usr/local/include

unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/../../../../usr/local/lib/libyaml-cpp.a
