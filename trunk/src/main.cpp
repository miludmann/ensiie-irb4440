#include "projet.h"
#include "interface2.h"

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



IRB4400 *root;
Interface *interface;

int main(int argc, char** argv)
{
  // Cration d'une application Qt
  QApplication app(argc,argv);

  Q3MainWindow* myWidget= new Q3MainWindow();
  IRB4400 robot(myWidget);
  root = &robot;

  root->matiere = new SoMaterial;

  root->socle = new SoSeparator;
/*
  root->objet_base = new SoSeparator;
  root->objet_translation = new SoTranslation;
  root->objet = new SoSeparator;
*/
  root->grille_base = new SoSeparator;
  root->grille_translation = new SoTranslation;
  root->grille = new SoSeparator;

  root->base_mobile = new SoSeparator;
  root->base_mobile_translation = new SoTranslation;
  root->base_mobile_base = new SoSeparator;
  root->base_mobile_repere = new SoSeparator;
  root->base_mobile_rotor = new SoRotation;

  root->parallelogramme_avant = new SoSeparator;
  root->parallelogramme_avant_translation = new SoTranslation;
  root->parallelogramme_avant_base = new SoSeparator;
  root->parallelogramme_avant_repere = new SoSeparator;
  root->parallelogramme_avant_repere_translation = new SoTranslation;
  root->parallelogramme_avant_rotor = new SoRotation;

  root->bitoniot_arriere = new SoSeparator;
  root->bitoniot_arriere_translation = new SoTranslation;
  root->bitoniot_arriere_base = new SoSeparator;
  root->bitoniot_arriere_rotor = new SoRotation;

  root->cylindre_base = new SoSeparator;
  root->cylindre_base_translation = new SoTranslation;
  root->cylindre_base_base = new SoSeparator;
  root->cylindre_base_rotor = new SoRotation;

  root->sortie_cylindre = new SoSeparator;
  root->sortie_cylindre_translation = new SoTranslation;
  root->sortie_cylindre_base = new SoSeparator;
  root->sortie_cylindre_rotor = new SoRotation;

  root->parallelogramme_arriere = new SoSeparator;
  root->parallelogramme_arriere_translation = new SoTranslation;
  root->parallelogramme_arriere_base = new SoSeparator;
  root->parallelogramme_arriere_rotor = new SoRotation;

  root->coude = new SoSeparator;
  root->coude_translation = new SoTranslation;
  root->coude_base = new SoSeparator;
  root->coude_repere = new SoSeparator;
  root->coude_rotor = new SoRotation;

  root->avant_bras = new SoSeparator;
  root->avant_bras_translation = new SoTranslation;
  root->avant_bras_base = new SoSeparator;
  root->avant_bras_repere = new SoSeparator;
  root->avant_bras_rotor = new SoRotation;

  root->poignet_1 = new SoSeparator;
  root->poignet_1_translation = new SoTranslation;
  root->poignet_1_base = new SoSeparator;
  root->poignet_1_repere = new SoSeparator;
  root->poignet_1_rotor = new SoRotation;

  root->poignet_2 = new SoSeparator;
  root->poignet_2_translation = new SoTranslation;
  root->poignet_2_base = new SoSeparator;
  root->poignet_2_repere = new SoSeparator;
  root->poignet_2_rotor = new SoRotation;


  if (argc > 1) {
    root->openFile(QString(argv[1]));
  }
  else {
    //camera
    //SoPerspectiveCamera *myCamera = new SoPerspectiveCamera;
    //root->separator->addChild(myCamera);
    //lighting
    root->separator->addChild(new SoDirectionalLight);
    //matiere
    root->matiere->diffuseColor.setValue(0.5, 0.7, 0.1);
    root->separator->addChild(root->matiere);

    //grille
    root->grille_base->ref();
    root->separator->addChild(root->grille_base);
    root->grille_translation->translation = SbVec3f(0, 0, 0);
    root->grille_base->addChild(root->grille_translation);
    root->openMember("vrml/grille.wrl", root->grille, root->grille_base);

    //socle
    root->openMember("vrml/socle.wrl", root->socle, root->separator);
    //base mobile
    root->base_mobile_base->ref();
    root->separator->addChild(root->base_mobile_base);
    root->base_mobile_translation->translation = SbVec3f(0, 0, 0);
    root->base_mobile_base->addChild(root->base_mobile_translation);
    root->openMember("vrml/repere.wrl", root->base_mobile_repere, root->base_mobile_base);
    root->openMember("vrml/base_mobile.wrl", root->base_mobile, root->base_mobile_base);
    //parallelogramme avant
    root->parallelogramme_avant_base->ref();
    root->base_mobile_base->addChild(root->parallelogramme_avant_base);
    root->parallelogramme_avant_translation->translation = SbVec3f(0, 0, 0);
    root->parallelogramme_avant_base->addChild(root->parallelogramme_avant_translation);

    root->parallelogramme_avant_repere_translation->translation = SbVec3f(2, 0, 0);
    root->parallelogramme_avant_repere->addChild(root->parallelogramme_avant_repere_translation);

    root->openMember("vrml/repere.wrl", root->parallelogramme_avant_repere, root->parallelogramme_avant_base);
    root->openMember("vrml/parallelogramme_avant.wrl", root->parallelogramme_avant, root->parallelogramme_avant_base);


    //bitoniot arriere
    root->bitoniot_arriere_base->ref();
    root->parallelogramme_arriere_base->addChild(root->bitoniot_arriere_base);
    root->bitoniot_arriere_translation->translation = SbVec3f(0, 0, 0);
    root->bitoniot_arriere_base->addChild(root->bitoniot_arriere_translation);
    root->openMember("vrml/bitoniot_arriere.wrl", root->bitoniot_arriere, root->bitoniot_arriere_base);
    //cylindre base
    root->cylindre_base_base->ref();
    root->base_mobile_base->addChild(root->cylindre_base_base);
    root->cylindre_base_translation->translation = SbVec3f(0, 0, 0);
    root->cylindre_base_base->addChild(root->cylindre_base_translation);
    root->openMember("vrml/cylindre_base.wrl", root->cylindre_base, root->cylindre_base_base);
    //sortie cylindre
    root->sortie_cylindre_base->ref();
    root->cylindre_base->addChild(root->sortie_cylindre_base);
    root->sortie_cylindre_translation->translation = SbVec3f(0, 0, 0);
    root->sortie_cylindre_base->addChild(root->sortie_cylindre_translation);
    root->openMember("vrml/sortie_cylindre.wrl", root->sortie_cylindre, root->sortie_cylindre_base);
    //parallelogramme arriere
    root->parallelogramme_arriere_base->ref();
    root->base_mobile_base->addChild(root->parallelogramme_arriere_base);
    root->parallelogramme_arriere_translation->translation = SbVec3f(0, 0, 0);
    root->parallelogramme_arriere_base->addChild(root->parallelogramme_arriere_translation);
    root->openMember("vrml/parallelogramme_arriere.wrl", root->parallelogramme_arriere, root->parallelogramme_arriere_base);
    //coude
    root->coude_base->ref();
    root->parallelogramme_avant_base->addChild(root->coude_base);
    root->coude_translation->translation = SbVec3f(0, 0, 0);
    root->coude_base->addChild(root->coude_translation);
    root->openMember("vrml/coude.wrl", root->coude, root->coude_base);
    //avant_bras
    root->avant_bras_base->ref();
    root->coude_base->addChild(root->avant_bras_base);
    root->avant_bras_translation->translation = SbVec3f(0, 0, 0);
    root->avant_bras_base->addChild(root->avant_bras_translation);
    root->openMember("vrml/avant_bras.wrl", root->avant_bras, root->avant_bras_base);
    //poignet_1
    root->poignet_1_base->ref();
    root->avant_bras_base->addChild(root->poignet_1_base);
    root->poignet_1_translation->translation = SbVec3f(0, 0, 0);
    root->poignet_1_base->addChild(root->poignet_1_translation);
    root->openMember("vrml/poignet_1.wrl", root->poignet_1, root->poignet_1_base);
    //poignet_2
    root->poignet_2_base->ref();
    root->poignet_1_base->addChild(root->poignet_2_base);
    root->poignet_2_translation->translation = SbVec3f(0, 0, 0);
    root->poignet_2_base->addChild(root->poignet_2_translation);
    root->openMember("vrml/poignet_2.wrl", root->poignet_2, root->poignet_2_base);
}

  interface = new Interface();
  interface->show();
  interface->move(QPoint(1050,100));

  app.setMainWidget(myWidget);
  myWidget->resize(1024,800);
  myWidget->move(QPoint(0,0));
  myWidget->show();

  root->mode = 0;
  root->x_wanted = 0;
  root->y_wanted = -0.9;
  root->z_wanted = 0;
  //root->move();

  root->center_scene();

  //interface->connect( interface->pushButton1, SIGNAL( clicked() ), root, SLOT( move() ) );
  interface->connect( interface->checkBox_2, SIGNAL( stateChanged(int) ), root, SLOT( toggle_fil_de_fer(int) ) );
  interface->connect( interface->pushButton, SIGNAL( clicked() ), root, SLOT( center_scene() ) );
  interface->connect( interface->checkBox, SIGNAL( stateChanged(int) ), root, SLOT(toggle_headlight(int) ) );
  //interface->connect( interface->lineEdit1, SIGNAL( textChanged(const QString&) ), root, SLOT(x_changed(const QString&) ));
  //interface->connect( interface->lineEdit2, SIGNAL( textChanged(const QString&) ), root, SLOT(y_changed(const QString&) ));
  //interface->connect( interface->lineEdit3, SIGNAL( textChanged(const QString&) ), root, SLOT(z_changed(const QString&) ));
  //interface->connect( interface->radioButton4, SIGNAL( stateChanged(int) ), root, SLOT( toggle_moving_mode(int) ));
  //interface->connect( interface->radioButton3, SIGNAL( stateChanged(int) ), root, SLOT( toggle_moving_mode2(int) ));
  interface->connect( interface->verticalSlider, SIGNAL( sliderMoved(int) ), root, SLOT( move_grille(int) ));
  interface->connect( interface->pushButton_2, SIGNAL( clicked() ), root, SLOT( reset_grille() ));
  //interface->connect( interface->pushButton4, SIGNAL( clicked() ), root, SLOT( lauch_simulation() ));

  interface->connect( interface->checkBox_3, SIGNAL( stateChanged(int) ), root, SLOT( toggle_rep0(int) ) );
  //interface->connect( interface->checkBox_5, SIGNAL( stateChanged(int) ), root, SLOT( toggle_rep2(int) ) );


  SoQt::mainLoop();
  //delete(&robot.getViewer());
  return 0;
}
