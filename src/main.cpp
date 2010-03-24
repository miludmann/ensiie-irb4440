#include "projet.h"
#include "mainWidget.h"

#include <Inventor/Qt/SoQt.h>

#include <qapplication.h>
#include <q3mainwindow.h>
#include <qmenubar.h>
#include <q3popupmenu.h>
#include <qvariant.h>
#include <qpoint.h>
#include <qdialog.h>
#include <qlcdnumber.h>
#include <qpushbutton.h>
#include <qradiobutton.h>
#include <qlineedit.h>
#include <qcheckbox.h>
#include <qslider.h>

#include <math.h>
#define M_PI 3.14159265358979323846

IVLoader *iv;
Interface *interface;

int main(int argc, char** argv)
{
  // Cration d'une application Qt
  QApplication app(argc,argv);

  Q3MainWindow* myWidget= new Q3MainWindow();
  IVLoader robot(myWidget);
  iv = &robot;

  iv->matiere = new SoMaterial;

  iv->socle = new SoSeparator;
/*
  iv->objet_base = new SoSeparator;
  iv->objet_translation = new SoTranslation;
  iv->objet = new SoSeparator;
*/
  iv->grille_base = new SoSeparator;
  iv->grille_translation = new SoTranslation;
  iv->grille = new SoSeparator;

  iv->base_mobile = new SoSeparator;
  iv->base_mobile_transform = new SoTransform;
  iv->base_mobile_base = new SoSeparator;

  iv->parallelogramme_avant = new SoSeparator;
  iv->parallelogramme_avant_transform = new SoTransform;
  iv->parallelogramme_avant_base = new SoSeparator;

  iv->bitoniot_arriere = new SoSeparator;
  iv->bitoniot_arriere_transform = new SoTransform;
  iv->bitoniot_arriere_base = new SoSeparator;

  iv->cylindre_base = new SoSeparator;
  iv->cylindre_base_transform = new SoTransform;
  iv->cylindre_base_base = new SoSeparator;

  iv->sortie_cylindre = new SoSeparator;
  iv->sortie_cylindre_transform = new SoTransform;
  iv->sortie_cylindre_base = new SoSeparator;

  iv->parallelogramme_arriere = new SoSeparator;
  iv->parallelogramme_arriere_transform = new SoTransform;
  iv->parallelogramme_arriere_base = new SoSeparator;

  iv->coude = new SoSeparator;
  iv->coude_transform = new SoTransform;
  iv->coude_base = new SoSeparator;

  iv->avant_bras = new SoSeparator;
  iv->avant_bras_transform = new SoTransform;
  iv->avant_bras_base = new SoSeparator;

  iv->poignet_1 = new SoSeparator;
  iv->poignet_1_base = new SoSeparator;
  iv->poignet_1_transform = new SoTransform;

  iv->poignet_2 = new SoSeparator;
  iv->poignet_2_transform = new SoTransform;
  iv->poignet_2_base = new SoSeparator;

  iv->repere_r0_base = new SoSeparator;
  iv->repere_r0 = new SoSeparator;

  iv->repere_r1_translation = new SoTranslation;
  iv->repere_r1_base = new SoSeparator;
  iv->repere_r1_rotor = new SoRotation;
  iv->repere_r1_rotor2 = new SoRotation;
  iv->repere_r1 = new SoSeparator;

  iv->repere_r2_translation = new SoTranslation;
  iv->repere_r2_base = new SoSeparator;
  iv->repere_r2_rotor = new SoRotation;
  iv->repere_r2_rotor2 = new SoRotation;
  iv->repere_r2 = new SoSeparator;

  iv->repere_r3_translation = new SoTranslation;
  iv->repere_r3_base = new SoSeparator;
  iv->repere_r3_rotor = new SoRotation;
  iv->repere_r3_rotor2 = new SoRotation;
  iv->repere_r3 = new SoSeparator;

  iv->repere_r4_translation = new SoTranslation;
  iv->repere_r4_base = new SoSeparator;
  iv->repere_r4_rotor = new SoRotation;
  iv->repere_r4_rotor2 = new SoRotation;
  iv->repere_r4 = new SoSeparator;

  iv->repere_r5_translation = new SoTranslation;
  iv->repere_r5_base = new SoSeparator;
  iv->repere_r5_rotor = new SoRotation;
  iv->repere_r5_rotor2 = new SoRotation;
  iv->repere_r5 = new SoSeparator;

  iv->repere_r6_translation = new SoTranslation;
  iv->repere_r6_base = new SoSeparator;
  iv->repere_r6_rotor = new SoRotation;
  iv->repere_r6_rotor2 = new SoRotation;
  iv->repere_r6 = new SoSeparator;

  if (argc > 1) {
    iv->openFile(QString(argv[1]));
  }
  else {
    //camera
    //SoPerspectiveCamera *myCamera = new SoPerspectiveCamera;
    //iv->separator->addChild(myCamera);
    //lighting
    iv->separator->addChild(new SoDirectionalLight);
    //matiere
    iv->matiere->diffuseColor.setValue(0.5, 0.7, 0.1);
    iv->separator->addChild(iv->matiere);

    //grille
    iv->grille_base->ref();
    iv->separator->addChild(iv->grille_base);
    iv->grille_translation->translation = SbVec3f(0, 0, 0);
    iv->grille_base->addChild(iv->grille_translation);
    iv->openMember("vrml/grille.wrl", iv->grille, iv->grille_base);

    //socle
    iv->openMember("vrml/socle.wrl", iv->socle, iv->separator);
    //repere_r0
    iv->repere_r0_base->ref();
    iv->separator->addChild(iv->repere_r0_base);
    iv->openMember("vrml/repere.wrl", iv->repere_r0, iv->repere_r0_base);
    //base mobile
    iv->base_mobile_base->ref();
    iv->separator->addChild(iv->base_mobile_base);
    iv->base_mobile_transform->translation = SbVec3f(0, 0, 0);
    iv->base_mobile_transform->rotation.setValue(SbVec3f(0, 0, 1), 0);
    iv->base_mobile_base->addChild(iv->base_mobile_transform);
    iv->openMember("vrml/base_mobile.wrl", iv->base_mobile, iv->base_mobile_base);
    //repere_r1
    iv->repere_r1_base->ref();
    iv->base_mobile_base->addChild(iv->repere_r1_base);
    iv->repere_r1_translation->translation = SbVec3f(0, 0, 0.68);
    iv->repere_r1_base->addChild(iv->repere_r1_translation);
    iv->openMember("vrml/repere.wrl", iv->repere_r1, iv->repere_r1_base);
    //parallelogramme avant
    iv->parallelogramme_avant_base->ref();
    iv->base_mobile_base->addChild(iv->parallelogramme_avant_base);
    iv->parallelogramme_avant_transform->translation = SbVec3f(0, 0, 0);
    iv->parallelogramme_avant_transform->recenter(SbVec3f(0.2, 0, 0.68));
    iv->parallelogramme_avant_base->addChild(iv->parallelogramme_avant_transform);
    iv->openMember("vrml/parallelogramme_avant.wrl", iv->parallelogramme_avant, iv->parallelogramme_avant_base);
    //repere_r2
    iv->repere_r2_base->ref();
    iv->parallelogramme_avant_base->addChild(iv->repere_r2_base);
    iv->repere_r2_translation->translation = SbVec3f(0.2, 0, 0.68);
    iv->repere_r2_base->addChild(iv->repere_r2_translation);
    iv->repere_r2_rotor->rotation.setValue(SbVec3f(1, 0, 0), M_PI/2);
    iv->repere_r2_base->addChild(iv->repere_r2_rotor);
    iv->repere_r2_rotor2->rotation.setValue(SbVec3f(0, 0, 1), M_PI/2);
    iv->repere_r2_base->addChild(iv->repere_r2_rotor2);
    iv->openMember("vrml/repere.wrl", iv->repere_r2, iv->repere_r2_base);
    //bitoniot arriere
    iv->bitoniot_arriere_base->ref();
    iv->parallelogramme_avant_base->addChild(iv->bitoniot_arriere_base);
    iv->bitoniot_arriere_transform->translation = SbVec3f(0, 0, 0);
    iv->bitoniot_arriere_transform->recenter(SbVec3f(0.2, 0, 0.68));
    iv->bitoniot_arriere_base->addChild(iv->bitoniot_arriere_transform);
    iv->openMember("vrml/bitoniot_arriere.wrl", iv->bitoniot_arriere, iv->bitoniot_arriere_base);
    //parallelogramme arriere
    iv->parallelogramme_arriere_base->ref();
    iv->bitoniot_arriere_base->addChild(iv->parallelogramme_arriere_base);
    iv->parallelogramme_arriere_transform->translation = SbVec3f(0, 0, 0);
    iv->parallelogramme_arriere_transform->recenter(SbVec3f(-0.1, 0, 0.68));
    iv->parallelogramme_arriere_base->addChild(iv->parallelogramme_arriere_transform);
    iv->openMember("vrml/parallelogramme_arriere.wrl", iv->parallelogramme_arriere, iv->parallelogramme_arriere_base);
    //cylindre base
    iv->cylindre_base_base->ref();
    iv->base_mobile_base->addChild(iv->cylindre_base_base);
    iv->cylindre_base_transform->translation = SbVec3f(0, 0, 0);
    iv->cylindre_base_transform->recenter(SbVec3f(-0.4775, 0, 0.5325));
    iv->cylindre_base_base->addChild(iv->cylindre_base_transform);
    iv->openMember("vrml/cylindre_base.wrl", iv->cylindre_base, iv->cylindre_base_base);
    //sortie cylindre
    iv->sortie_cylindre_base->ref();
    iv->parallelogramme_avant_base->addChild(iv->sortie_cylindre_base);
    iv->sortie_cylindre_transform->translation = SbVec3f(0, 0, 0);
    iv->sortie_cylindre_transform->recenter(SbVec3f(0.32, 0, 0.7061));
    iv->sortie_cylindre_base->addChild(iv->sortie_cylindre_transform);
    iv->openMember("vrml/sortie_cylindre.wrl", iv->sortie_cylindre, iv->sortie_cylindre_base);
    //coude
    iv->coude_base->ref();
    iv->parallelogramme_avant_base->addChild(iv->coude_base);
    iv->coude_transform->translation = SbVec3f(0, 0, 0);
    iv->coude_transform->recenter(SbVec3f(0.2, 0, 1.57));
    iv->coude_base->addChild(iv->coude_transform);
    iv->openMember("vrml/coude.wrl", iv->coude, iv->coude_base);
    //repere_r3
    iv->repere_r3_base->ref();
    iv->coude_base->addChild(iv->repere_r3_base);
    iv->repere_r3_translation->translation = SbVec3f(0.2, 0, 1.57);
    iv->repere_r3_base->addChild(iv->repere_r3_translation);
    iv->repere_r3_rotor->rotation.setValue(SbVec3f(1, 0, 0), M_PI/2);
    iv->repere_r3_base->addChild(iv->repere_r3_rotor);
    iv->repere_r3_rotor2->rotation.setValue(SbVec3f(0, 0, 1), M_PI/2);
    iv->repere_r3_base->addChild(iv->repere_r3_rotor2);
    iv->openMember("vrml/repere.wrl", iv->repere_r3, iv->repere_r3_base);
    //avant_bras
    iv->avant_bras_base->ref();
    iv->coude_base->addChild(iv->avant_bras_base);
    iv->avant_bras_transform->translation = SbVec3f(0, 0, 0);
    iv->avant_bras_transform->recenter(SbVec3f(1.08, 0, 1.720));
    iv->avant_bras_base->addChild(iv->avant_bras_transform);
    iv->openMember("vrml/avant_bras.wrl", iv->avant_bras, iv->avant_bras_base);
    //repere_r4
    iv->repere_r4_base->ref();
    iv->avant_bras_base->addChild(iv->repere_r4_base);
    iv->repere_r4_translation->translation = SbVec3f(1.08, 0, 1.720);
    iv->repere_r4_base->addChild(iv->repere_r4_translation);
    iv->repere_r4_rotor->rotation.setValue(SbVec3f(0, 1, 0), M_PI/2);
    iv->repere_r4_base->addChild(iv->repere_r4_rotor);
    iv->repere_r4_rotor2->rotation.setValue(SbVec3f(0, 0, 1), M_PI);
    iv->repere_r4_base->addChild(iv->repere_r4_rotor2);
    iv->openMember("vrml/repere.wrl", iv->repere_r4, iv->repere_r4_base);
    //poignet_1
    iv->poignet_1_base->ref();
    iv->avant_bras_base->addChild(iv->poignet_1_base);
    iv->poignet_1_transform->translation = SbVec3f(0, 0, 0);
    iv->poignet_1_transform->recenter(SbVec3f(1.08, 0, 1.720));
    iv->poignet_1_base->addChild(iv->poignet_1_transform);
    iv->openMember("vrml/poignet_1.wrl", iv->poignet_1, iv->poignet_1_base);
    //repere_r5
    iv->repere_r5_base->ref();
    iv->poignet_1_base->addChild(iv->repere_r5_base);
    iv->repere_r5_translation->translation = SbVec3f(1.08, 0, 1.720);
    iv->repere_r5_base->addChild(iv->repere_r5_translation);
    iv->repere_r5_rotor->rotation.setValue(SbVec3f(1, 0, 0), M_PI/2);
    iv->repere_r5_base->addChild(iv->repere_r5_rotor);
    iv->repere_r5_rotor2->rotation.setValue(SbVec3f(0, 0, 1), M_PI/2);
    iv->repere_r5_base->addChild(iv->repere_r5_rotor2);
    iv->openMember("vrml/repere.wrl", iv->repere_r5, iv->repere_r5_base);
    //poignet_2
    iv->poignet_2_base->ref();
    iv->poignet_1_base->addChild(iv->poignet_2_base);
    iv->poignet_2_transform->translation = SbVec3f(0, 0, 0);
    iv->poignet_2_transform->recenter(SbVec3f(1.08, 0, 1.720));
    iv->poignet_2_base->addChild(iv->poignet_2_transform);
    iv->openMember("vrml/poignet_2.wrl", iv->poignet_2, iv->poignet_2_base);
    //repere_r6
    iv->repere_r6_base->ref();
    iv->poignet_2_base->addChild(iv->repere_r6_base);
    iv->repere_r6_translation->translation = SbVec3f(1.08, 0, 1.720);
    iv->repere_r6_base->addChild(iv->repere_r6_translation);
    iv->repere_r6_rotor->rotation.setValue(SbVec3f(0, 1, 0), M_PI/2);
    iv->repere_r6_base->addChild(iv->repere_r6_rotor);
    iv->repere_r6_rotor2->rotation.setValue(SbVec3f(0, 0, 1), M_PI);
    iv->repere_r6_base->addChild(iv->repere_r6_rotor2);
    iv->openMember("vrml/repere.wrl", iv->repere_r6, iv->repere_r6_base);
}

  interface = new Interface();
  interface->show();
  interface->move(QPoint(1050,0));

  app.setMainWidget(myWidget);
  myWidget->resize(800,600);
  myWidget->move(QPoint(0,0));
  myWidget->show();

  iv->viewer->viewAll();;
  iv->viewer->setHeadlight(false);

  interface->connect( interface->horizontalSlider, SIGNAL (valueChanged(int)), iv, SLOT(move_base_mobile(int)));
  interface->connect( interface->horizontalSlider_2, SIGNAL (valueChanged(int)), iv, SLOT(move_parallelogramme(int)));
  interface->connect( interface->horizontalSlider_3, SIGNAL (valueChanged(int)), iv, SLOT(move_coude(int)));
  interface->connect( interface->horizontalSlider_4, SIGNAL (valueChanged(int)), iv, SLOT(move_avant_bras(int)));
  interface->connect( interface->horizontalSlider_5, SIGNAL (valueChanged(int)), iv, SLOT(move_poignet_1(int)));
  interface->connect( interface->horizontalSlider_6, SIGNAL (valueChanged(int)), iv, SLOT(move_poignet_2(int)));
  interface->connect( interface->pushButton_7, SIGNAL( clicked()), iv, SLOT(repeat_control_mgd()));

  interface->connect( interface->pushButton_6, SIGNAL( clicked()), iv, SLOT(on_lancer_commande()));
  interface->connect( interface->pushButton_9, SIGNAL( clicked()), iv, SLOT(default_mgi()));


  SoQt::mainLoop();
  //delete(&robot.getViewer());
  return 0;
}
