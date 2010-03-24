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
  root->base_mobile_transform = new SoTransform;
  root->base_mobile_base = new SoSeparator;

  root->parallelogramme_avant = new SoSeparator;
  root->parallelogramme_avant_transform = new SoTransform;
  root->parallelogramme_avant_base = new SoSeparator;

  root->bitoniot_arriere = new SoSeparator;
  root->bitoniot_arriere_transform = new SoTransform;
  root->bitoniot_arriere_base = new SoSeparator;

  root->cylindre_base = new SoSeparator;
  root->cylindre_base_transform = new SoTransform;
  root->cylindre_base_base = new SoSeparator;

  root->sortie_cylindre = new SoSeparator;
  root->sortie_cylindre_transform = new SoTransform;
  root->sortie_cylindre_base = new SoSeparator;

  root->parallelogramme_arriere = new SoSeparator;
  root->parallelogramme_arriere_transform = new SoTransform;
  root->parallelogramme_arriere_base = new SoSeparator;

  root->coude = new SoSeparator;
  root->coude_transform = new SoTransform;
  root->coude_base = new SoSeparator;

  root->avant_bras = new SoSeparator;
  root->avant_bras_transform = new SoTransform;
  root->avant_bras_base = new SoSeparator;

  root->poignet_1 = new SoSeparator;
  root->poignet_1_base = new SoSeparator;
  root->poignet_1_transform = new SoTransform;

  root->poignet_2 = new SoSeparator;
  root->poignet_2_transform = new SoTransform;
  root->poignet_2_base = new SoSeparator;

  root->repere_r0_base = new SoSeparator;
  root->repere_r0 = new SoSeparator;

  root->repere_r1_translation = new SoTranslation;
  root->repere_r1_base = new SoSeparator;
  root->repere_r1_rotor = new SoRotation;
  root->repere_r1_rotor2 = new SoRotation;
  root->repere_r1 = new SoSeparator;

  root->repere_r2_translation = new SoTranslation;
  root->repere_r2_base = new SoSeparator;
  root->repere_r2_rotor = new SoRotation;
  root->repere_r2_rotor2 = new SoRotation;
  root->repere_r2 = new SoSeparator;

  root->repere_r3_translation = new SoTranslation;
  root->repere_r3_base = new SoSeparator;
  root->repere_r3_rotor = new SoRotation;
  root->repere_r3_rotor2 = new SoRotation;
  root->repere_r3 = new SoSeparator;

  root->repere_r4_translation = new SoTranslation;
  root->repere_r4_base = new SoSeparator;
  root->repere_r4_rotor = new SoRotation;
  root->repere_r4_rotor2 = new SoRotation;
  root->repere_r4 = new SoSeparator;

  root->repere_r5_translation = new SoTranslation;
  root->repere_r5_base = new SoSeparator;
  root->repere_r5_rotor = new SoRotation;
  root->repere_r5_rotor2 = new SoRotation;
  root->repere_r5 = new SoSeparator;

  root->repere_r6_translation = new SoTranslation;
  root->repere_r6_base = new SoSeparator;
  root->repere_r6_rotor = new SoRotation;
  root->repere_r6_rotor2 = new SoRotation;
  root->repere_r6 = new SoSeparator;

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
    //repere_r0
    root->repere_r0_base->ref();
    root->separator->addChild(root->repere_r0_base);
    root->openMember("vrml/repere.wrl", root->repere_r0, root->repere_r0_base);
    //base mobile
    root->base_mobile_base->ref();
    root->separator->addChild(root->base_mobile_base);
    root->base_mobile_transform->translation = SbVec3f(0, 0, 0);
    root->base_mobile_transform->rotation.setValue(SbVec3f(0, 0, 1), 0);
    root->base_mobile_base->addChild(root->base_mobile_transform);
    root->openMember("vrml/base_mobile.wrl", root->base_mobile, root->base_mobile_base);
    //repere_r1
    root->repere_r1_base->ref();
    root->base_mobile_base->addChild(root->repere_r1_base);
    root->repere_r1_translation->translation = SbVec3f(0, 0, 0.68);
    root->repere_r1_base->addChild(root->repere_r1_translation);
    root->openMember("vrml/repere.wrl", root->repere_r1, root->repere_r1_base);
    //parallelogramme avant
    root->parallelogramme_avant_base->ref();
    root->base_mobile_base->addChild(root->parallelogramme_avant_base);
    root->parallelogramme_avant_transform->translation = SbVec3f(0, 0, 0);
    root->parallelogramme_avant_transform->recenter(SbVec3f(0.2, 0, 0.68));
    root->parallelogramme_avant_base->addChild(root->parallelogramme_avant_transform);
    root->openMember("vrml/parallelogramme_avant.wrl", root->parallelogramme_avant, root->parallelogramme_avant_base);
    //repere_r2
    root->repere_r2_base->ref();
    root->parallelogramme_avant_base->addChild(root->repere_r2_base);
    root->repere_r2_translation->translation = SbVec3f(0.2, 0, 0.68);
    root->repere_r2_base->addChild(root->repere_r2_translation);
    root->repere_r2_rotor->rotation.setValue(SbVec3f(1, 0, 0), M_PI/2);
    root->repere_r2_base->addChild(root->repere_r2_rotor);
    root->repere_r2_rotor2->rotation.setValue(SbVec3f(0, 0, 1), M_PI/2);
    root->repere_r2_base->addChild(root->repere_r2_rotor2);
    root->openMember("vrml/repere.wrl", root->repere_r2, root->repere_r2_base);
    //bitoniot arriere
    root->bitoniot_arriere_base->ref();
    root->parallelogramme_avant_base->addChild(root->bitoniot_arriere_base);
    root->bitoniot_arriere_transform->translation = SbVec3f(0, 0, 0);
    root->bitoniot_arriere_transform->recenter(SbVec3f(0.2, 0, 0.68));
    root->bitoniot_arriere_base->addChild(root->bitoniot_arriere_transform);
    root->openMember("vrml/bitoniot_arriere.wrl", root->bitoniot_arriere, root->bitoniot_arriere_base);
    //parallelogramme arriere
    root->parallelogramme_arriere_base->ref();
    root->bitoniot_arriere_base->addChild(root->parallelogramme_arriere_base);
    root->parallelogramme_arriere_transform->translation = SbVec3f(0, 0, 0);
    root->parallelogramme_arriere_transform->recenter(SbVec3f(-0.1, 0, 0.68));
    root->parallelogramme_arriere_base->addChild(root->parallelogramme_arriere_transform);
    root->openMember("vrml/parallelogramme_arriere.wrl", root->parallelogramme_arriere, root->parallelogramme_arriere_base);
    //cylindre base
    root->cylindre_base_base->ref();
    root->base_mobile_base->addChild(root->cylindre_base_base);
    root->cylindre_base_transform->translation = SbVec3f(0, 0, 0);
    root->cylindre_base_transform->recenter(SbVec3f(-0.4775, 0, 0.5325));
    root->cylindre_base_base->addChild(root->cylindre_base_transform);
    root->openMember("vrml/cylindre_base.wrl", root->cylindre_base, root->cylindre_base_base);
    //sortie cylindre
    root->sortie_cylindre_base->ref();
    root->parallelogramme_avant_base->addChild(root->sortie_cylindre_base);
    root->sortie_cylindre_transform->translation = SbVec3f(0, 0, 0);
    root->sortie_cylindre_transform->recenter(SbVec3f(0.32, 0, 0.7061));
    root->sortie_cylindre_base->addChild(root->sortie_cylindre_transform);
    root->openMember("vrml/sortie_cylindre.wrl", root->sortie_cylindre, root->sortie_cylindre_base);
    //coude
    root->coude_base->ref();
    root->parallelogramme_avant_base->addChild(root->coude_base);
    root->coude_transform->translation = SbVec3f(0, 0, 0);
    root->coude_transform->recenter(SbVec3f(0.2, 0, 1.57));
    root->coude_base->addChild(root->coude_transform);
    root->openMember("vrml/coude.wrl", root->coude, root->coude_base);
    //repere_r3
    root->repere_r3_base->ref();
    root->coude_base->addChild(root->repere_r3_base);
    root->repere_r3_translation->translation = SbVec3f(0.2, 0, 1.57);
    root->repere_r3_base->addChild(root->repere_r3_translation);
    root->repere_r3_rotor->rotation.setValue(SbVec3f(1, 0, 0), M_PI/2);
    root->repere_r3_base->addChild(root->repere_r3_rotor);
    root->repere_r3_rotor2->rotation.setValue(SbVec3f(0, 0, 1), M_PI/2);
    root->repere_r3_base->addChild(root->repere_r3_rotor2);
    root->openMember("vrml/repere.wrl", root->repere_r3, root->repere_r3_base);
    //avant_bras
    root->avant_bras_base->ref();
    root->coude_base->addChild(root->avant_bras_base);
    root->avant_bras_transform->translation = SbVec3f(0, 0, 0);
    root->avant_bras_transform->recenter(SbVec3f(1.08, 0, 1.720));
    root->avant_bras_base->addChild(root->avant_bras_transform);
    root->openMember("vrml/avant_bras.wrl", root->avant_bras, root->avant_bras_base);
    //repere_r4
    root->repere_r4_base->ref();
    root->avant_bras_base->addChild(root->repere_r4_base);
    root->repere_r4_translation->translation = SbVec3f(1.08, 0, 1.720);
    root->repere_r4_base->addChild(root->repere_r4_translation);
    root->repere_r4_rotor->rotation.setValue(SbVec3f(0, 1, 0), M_PI/2);
    root->repere_r4_base->addChild(root->repere_r4_rotor);
    root->repere_r4_rotor2->rotation.setValue(SbVec3f(0, 0, 1), M_PI);
    root->repere_r4_base->addChild(root->repere_r4_rotor2);
    root->openMember("vrml/repere.wrl", root->repere_r4, root->repere_r4_base);
    //poignet_1
    root->poignet_1_base->ref();
    root->avant_bras_base->addChild(root->poignet_1_base);
    root->poignet_1_transform->translation = SbVec3f(0, 0, 0);
    root->poignet_1_transform->recenter(SbVec3f(1.08, 0, 1.720));
    root->poignet_1_base->addChild(root->poignet_1_transform);
    root->openMember("vrml/poignet_1.wrl", root->poignet_1, root->poignet_1_base);
    //repere_r5
    root->repere_r5_base->ref();
    root->poignet_1_base->addChild(root->repere_r5_base);
    root->repere_r5_translation->translation = SbVec3f(1.08, 0, 1.720);
    root->repere_r5_base->addChild(root->repere_r5_translation);
    root->repere_r5_rotor->rotation.setValue(SbVec3f(1, 0, 0), M_PI/2);
    root->repere_r5_base->addChild(root->repere_r5_rotor);
    root->repere_r5_rotor2->rotation.setValue(SbVec3f(0, 0, 1), M_PI/2);
    root->repere_r5_base->addChild(root->repere_r5_rotor2);
    root->openMember("vrml/repere.wrl", root->repere_r5, root->repere_r5_base);
    //poignet_2
    root->poignet_2_base->ref();
    root->poignet_1_base->addChild(root->poignet_2_base);
    root->poignet_2_transform->translation = SbVec3f(0, 0, 0);
    root->poignet_2_transform->recenter(SbVec3f(1.08, 0, 1.720));
    root->poignet_2_base->addChild(root->poignet_2_transform);
    root->openMember("vrml/poignet_2.wrl", root->poignet_2, root->poignet_2_base);
    //repere_r6
    root->repere_r6_base->ref();
    root->poignet_2_base->addChild(root->repere_r6_base);
    root->repere_r6_translation->translation = SbVec3f(1.08, 0, 1.720);
    root->repere_r6_base->addChild(root->repere_r6_translation);
    root->repere_r6_rotor->rotation.setValue(SbVec3f(0, 1, 0), M_PI/2);
    root->repere_r6_base->addChild(root->repere_r6_rotor);
    root->repere_r6_rotor2->rotation.setValue(SbVec3f(0, 0, 1), M_PI);
    root->repere_r6_base->addChild(root->repere_r6_rotor2);
    root->openMember("vrml/repere.wrl", root->repere_r6, root->repere_r6_base);
}

  interface = new Interface();
  interface->show();
  interface->move(QPoint(1050,0));

  app.setMainWidget(myWidget);
  myWidget->resize(800,600);
  myWidget->move(QPoint(0,0));
  myWidget->show();

  root->mode = 0;
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
  interface->connect( interface->checkBox_4, SIGNAL( stateChanged(int) ), root, SLOT( toggle_rep1(int) ) );
  interface->connect( interface->checkBox_5, SIGNAL( stateChanged(int) ), root, SLOT( toggle_rep2(int) ) );
  interface->connect( interface->checkBox_6, SIGNAL( stateChanged(int) ), root, SLOT( toggle_rep4(int) ) );
  interface->connect( interface->checkBox_7, SIGNAL( stateChanged(int) ), root, SLOT( toggle_rep5(int) ) );
  interface->connect( interface->checkBox_8, SIGNAL( stateChanged(int) ), root, SLOT( toggle_rep3(int) ) );
  interface->connect( interface->checkBox_9, SIGNAL( stateChanged(int) ), root, SLOT( toggle_rep6(int) ) );

  interface->connect( interface->pushButton_10, SIGNAL( clicked() ), root, SLOT( toggle_toutCocher() ) );

  interface->connect( interface->horizontalSlider, SIGNAL (valueChanged(int)), root, SLOT(move_base_mobile(int)));
  interface->connect( interface->horizontalSlider_2, SIGNAL (valueChanged(int)), root, SLOT(move_parallelogramme(int)));
  interface->connect( interface->horizontalSlider_3, SIGNAL (valueChanged(int)), root, SLOT(move_coude(int)));
  interface->connect( interface->horizontalSlider_4, SIGNAL (valueChanged(int)), root, SLOT(move_avant_bras(int)));
  interface->connect( interface->horizontalSlider_5, SIGNAL (valueChanged(int)), root, SLOT(move_poignet_1(int)));
  interface->connect( interface->horizontalSlider_6, SIGNAL (valueChanged(int)), root, SLOT(move_poignet_2(int)));
  interface->connect( interface->pushButton_7, SIGNAL( clicked()), root, SLOT(repeat_control_mgd()));
  //interface->connect( interface->pushButton_8, SIGNAL( clicked()), root, SLOT(reset_sliders()));

  interface->connect( interface->pushButton_6, SIGNAL( clicked()), root, SLOT(on_lancer_commande()));
  interface->connect( interface->pushButton_9, SIGNAL( clicked()), root, SLOT(default_mgi()));


  SoQt::mainLoop();
  //delete(&robot.getViewer());
  return 0;
}
