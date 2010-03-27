TEMPLATE = app
HEADERS += projet.h \
    mainWidget.h
FORMS += mainWidgetform.ui
SOURCES += main.cpp \
    projet.cpp \
    mainWidget.cpp
OTHER_FILES += vrml/sortie_cylindre.wrl \
    vrml/socle.wrl \
    vrml/repere.wrl \
    vrml/poignet_2.wrl \
    vrml/poignet_1.wrl \
    vrml/grille.wrl \
    vrml/parallelogramme_avant.wrl \
    vrml/parallelogramme_arriere.wrl \
    vrml/logo_ABB_4.wrl \
    vrml/logo_ABB_3.wrl \
    vrml/logo_ABB_2.wrl \
    vrml/deco_2.wrl \
    vrml/deco_1.wrl \
    vrml/cylindre_base.wrl \
    vrml/coude.wrl \
    vrml/bitoniot_arriere.wrl \
    vrml/base_mobile.wrl \
    vrml/avant_bras.wrl \
    vrml/hanoi1.wrl \
    vrml/hanoi2.wrl \
    vrml/hanoi3.wrl

# The following line was changed from FORMS to FORMS3 by qt3to4
INCLUDEPATH += $$system(soqt-config --includedir)
LIBS += $$system(soqt-config --ldflags --libs)

# The following line was inserted by qt3to4
QT += qt3support



