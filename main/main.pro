QT += gui core charts widgets

TEMPLATE = app
CONFIG += c++11

HEADERS += \
    chartview.h \

SOURCES += \
    main.cpp


target.path = $$[QT_INSTALL_EXAMPLES]/charts/scatterchart
INSTALLS += target

SUBDIRS += \
    scatterchart.pro
