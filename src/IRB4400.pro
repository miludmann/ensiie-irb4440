# define COIN_GLERROR_DEBUGGING=1
TEMPLATE = app
HEADERS += projet.h \
    interface2.h
SOURCES += main.cpp \
    projet.cpp \
    interface.cpp
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
    vrml/avant_bras.wrl

# The following line was changed from FORMS to FORMS3 by qt3to4
# FORMS3   = form1.ui
INCLUDEPATH += $$system(soqt-config --includedir)
LIBS += $$system(soqt-config --ldflags --libs)

# The following line was inserted by qt3to4
QT += qt3support

# The following line was inserted by qt3to4
CONFIG += uic3
FORMS += interfaceUi.ui
