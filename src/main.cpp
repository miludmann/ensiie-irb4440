#include "projet.h"
#include "mainWidget.h"

#include <Inventor/Qt/SoQt.h>

#include <qapplication.h>
#include <q3mainwindow.h>
#include <qvariant.h>

#include <Inventor/nodes/SoEventCallback.h>
#include <Inventor/events/SoKeyboardEvent.h>
#include <Inventor/events/SoMouseButtonEvent.h>
#include <Inventor/events/SoLocation2Event.h>
#include <Inventor/events/SoEvent.h>

#include <math.h>
#define M_PI 3.14159265358979323846

IVLoader *iv;
Interface *interface;

int axis;
int oldValue;

void KeyboardCBFunction(void *userData, SoEventCallback *eventCB);
void uncolorAll();
void recolor(int angle);

int main(int argc, char** argv)
{
  // Création d'une application Qt
  QApplication app(argc,argv);

  Q3MainWindow* myWidget= new Q3MainWindow();
  IVLoader robot(myWidget);
  iv = &robot;

  iv->matiere = new SoMaterial;

  iv->socle = new SoSeparator;


  //hanoi
  iv->hanoi1_base = new SoSeparator;
  iv->hanoi1_transform = new SoTransform;
  iv->hanoi1 = new SoSeparator;

  iv->hanoi2_base = new SoSeparator;
  iv->hanoi2_transform = new SoTransform;
  iv->hanoi2 = new SoSeparator;

  iv->hanoi3_base = new SoSeparator;
  iv->hanoi3_transform = new SoTransform;
  iv->hanoi3 = new SoSeparator;

  iv->palette1_base = new SoSeparator;
  iv->palette1_transform = new SoTransform;
  iv->palette1 = new SoSeparator;

  iv->palette2_base = new SoSeparator;
  iv->palette2_transform = new SoTransform;
  iv->palette2 = new SoSeparator;

  iv->palette3_base = new SoSeparator;
  iv->palette3_transform = new SoTransform;
  iv->palette3 = new SoSeparator;

  iv->grille_base = new SoSeparator;
  iv->grille_translation = new SoTranslation;
  iv->grille = new SoSeparator;

  iv->base_mobile = new SoSeparator;
  iv->base_mobile_transform = new SoTransform;
  iv->base_mobile_base = new SoSeparator;
  iv->base_mobile_mat = new SoMaterial;

  iv->parallelogramme_avant = new SoSeparator;
  iv->parallelogramme_avant_transform = new SoTransform;
  iv->parallelogramme_avant_base = new SoSeparator;
  iv->parallelogramme_avant_mat = new SoMaterial;

  iv->bitoniot_arriere = new SoSeparator;
  iv->bitoniot_arriere_transform = new SoTransform;
  iv->bitoniot_arriere_base = new SoSeparator;
  iv->bitoniot_arriere_mat = new SoMaterial;

  iv->cylindre_base = new SoSeparator;
  iv->cylindre_base_transform = new SoTransform;
  iv->cylindre_base_base = new SoSeparator;
  iv->cylindre_base_mat = new SoMaterial;

  iv->sortie_cylindre = new SoSeparator;
  iv->sortie_cylindre_transform = new SoTransform;
  iv->sortie_cylindre_base = new SoSeparator;
  iv->sortie_cylindre_mat = new SoMaterial;

  iv->parallelogramme_arriere = new SoSeparator;
  iv->parallelogramme_arriere_transform = new SoTransform;
  iv->parallelogramme_arriere_base = new SoSeparator;
  iv->parallelogramme_arriere_mat = new SoMaterial;

  iv->coude = new SoSeparator;
  iv->coude_transform = new SoTransform;
  iv->coude_base = new SoSeparator;
  iv->coude_mat = new SoMaterial;

  iv->avant_bras = new SoSeparator;
  iv->avant_bras_transform = new SoTransform;
  iv->avant_bras_base = new SoSeparator;
  iv->avant_bras_mat = new SoMaterial;

  iv->poignet_1 = new SoSeparator;
  iv->poignet_1_base = new SoSeparator;
  iv->poignet_1_transform = new SoTransform;
  iv->poignet_1_mat = new SoMaterial;

  iv->poignet_2 = new SoSeparator;
  iv->poignet_2_transform = new SoTransform;
  iv->poignet_2_base = new SoSeparator;
  iv->poignet_2_mat = new SoMaterial;

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

  //Gestion des events
  iv->eventCBNode = new SoEventCallback;

  if (argc > 1) {
    iv->openFile(QString(argv[1]));
  }
  else {
    // register specific keyboard and mouse callbacks
    iv->eventCBNode->addEventCallback(SoKeyboardEvent::getClassTypeId(),
                  KeyboardCBFunction, NULL);
    //Events
    iv->separator->addChild(iv->eventCBNode);

    //Eclairage
    iv->separator->addChild(new SoDirectionalLight);
    //matiere
    iv->matiere->diffuseColor.setValue(0.890196, 0.411765, 0.125490 );
    iv->separator->addChild(iv->matiere);


    //hanoi
    iv->hanoi1_base->ref();
    iv->separator->addChild(iv->hanoi1_base);
    iv->hanoi1_transform->translation.setValue(SbVec3f(1, 0, 0.05));
    iv->hanoi1_transform->rotation.setValue(SbVec3f(1, 0, 0), M_PI/2);
    iv->hanoi1_base->addChild(iv->hanoi1_transform);
    iv->openMember("vrml/hanoi1.wrl", iv->hanoi1, iv->hanoi1_base);

    iv->hanoi2_base->ref();
    iv->separator->addChild(iv->hanoi2_base);
    iv->hanoi2_transform->translation.setValue(SbVec3f(1, 0, 0.15));
    iv->hanoi2_transform->rotation.setValue(SbVec3f(1, 0, 0), M_PI/2);
    iv->hanoi2_base->addChild(iv->hanoi2_transform);
    iv->openMember("vrml/hanoi2.wrl", iv->hanoi2, iv->hanoi2_base);

    iv->hanoi3_base->ref();
    iv->separator->addChild(iv->hanoi3_base);
    iv->hanoi3_transform->translation.setValue(SbVec3f(1, 0, 0.25));
    iv->hanoi3_transform->rotation.setValue(SbVec3f(1, 0, 0), M_PI/2);
    iv->hanoi3_base->addChild(iv->hanoi3_transform);
    iv->openMember("vrml/hanoi3.wrl", iv->hanoi3, iv->hanoi3_base);

    iv->palette1_base->ref();
    iv->separator->addChild(iv->palette1_base);
    iv->palette1_transform->translation.setValue(SbVec3f(1, 0, -0.005));
    iv->palette1_base->addChild(iv->palette1_transform);
    iv->openMember("vrml/palette.wrl", iv->palette1, iv->palette1_base);

    iv->palette2_base->ref();
    iv->separator->addChild(iv->palette2_base);
    iv->palette2_transform->translation.setValue(SbVec3f(1, 0.8, -0.005));
    iv->palette2_base->addChild(iv->palette2_transform);
    iv->openMember("vrml/palette.wrl", iv->palette2, iv->palette2_base);

    iv->palette3_base->ref();
    iv->separator->addChild(iv->palette3_base);
    iv->palette3_transform->translation.setValue(SbVec3f(1, -0.8, -0.005));
    iv->palette3_base->addChild(iv->palette3_transform);
    iv->openMember("vrml/palette.wrl", iv->palette3, iv->palette3_base);

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
    iv->base_mobile_mat->emissiveColor.setValue(0.890196, 0.411765, 0.125490);
    iv->base_mobile_base->addChild(iv->base_mobile_mat);
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
    iv->parallelogramme_avant_mat->emissiveColor.setValue(0.890196, 0.411765, 0.125490);
    iv->parallelogramme_avant_base->addChild(iv->parallelogramme_avant_mat);
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
    iv->bitoniot_arriere_mat->emissiveColor.setValue(0.890196, 0.411765, 0.125490);
    iv->bitoniot_arriere_base->addChild(iv->bitoniot_arriere_mat);
    iv->openMember("vrml/bitoniot_arriere.wrl", iv->bitoniot_arriere, iv->bitoniot_arriere_base);
    //parallelogramme arriere
    iv->parallelogramme_arriere_base->ref();
    iv->bitoniot_arriere_base->addChild(iv->parallelogramme_arriere_base);
    iv->parallelogramme_arriere_transform->translation = SbVec3f(0, 0, 0);
    iv->parallelogramme_arriere_transform->recenter(SbVec3f(-0.1, 0, 0.68));
    iv->parallelogramme_arriere_base->addChild(iv->parallelogramme_arriere_transform);
    iv->parallelogramme_arriere_mat->emissiveColor.setValue(0.890196, 0.411765, 0.125490);
    iv->parallelogramme_arriere_base->addChild(iv->parallelogramme_arriere_mat);
    iv->openMember("vrml/parallelogramme_arriere.wrl", iv->parallelogramme_arriere, iv->parallelogramme_arriere_base);
    //cylindre base
    iv->cylindre_base_base->ref();
    iv->base_mobile_base->addChild(iv->cylindre_base_base);
    iv->cylindre_base_transform->translation = SbVec3f(0, 0, 0);
    iv->cylindre_base_transform->recenter(SbVec3f(-0.4775, 0, 0.5325));
    iv->cylindre_base_base->addChild(iv->cylindre_base_transform);
    iv->cylindre_base_mat->emissiveColor.setValue(0.890196, 0.411765, 0.125490);
    iv->cylindre_base_base->addChild(iv->cylindre_base_mat);
    iv->openMember("vrml/cylindre_base.wrl", iv->cylindre_base, iv->cylindre_base_base);
    //sortie cylindre
    iv->sortie_cylindre_base->ref();
    iv->parallelogramme_avant_base->addChild(iv->sortie_cylindre_base);
    iv->sortie_cylindre_transform->translation = SbVec3f(0, 0, 0);
    iv->sortie_cylindre_transform->recenter(SbVec3f(0.32, 0, 0.7061));
    iv->sortie_cylindre_base->addChild(iv->sortie_cylindre_transform);
    iv->sortie_cylindre_mat->emissiveColor.setValue(0.890196, 0.411765, 0.125490);
    iv->sortie_cylindre_base->addChild(iv->sortie_cylindre_mat);
    iv->openMember("vrml/sortie_cylindre.wrl", iv->sortie_cylindre, iv->sortie_cylindre_base);
    //coude
    iv->coude_base->ref();
    iv->parallelogramme_avant_base->addChild(iv->coude_base);
    iv->coude_transform->translation = SbVec3f(0, 0, 0);
    iv->coude_transform->recenter(SbVec3f(0.2, 0, 1.57));
    iv->coude_base->addChild(iv->coude_transform);
    iv->coude_mat->emissiveColor.setValue(0.890196, 0.411765, 0.125490);
    iv->coude_base->addChild(iv->coude_mat);
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
    iv->avant_bras_mat->emissiveColor.setValue(0.890196, 0.411765, 0.125490);
    iv->avant_bras_base->addChild(iv->avant_bras_mat);
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
    iv->poignet_1_mat->emissiveColor.setValue(0.890196, 0.411765, 0.125490);
    iv->poignet_1_base->addChild(iv->poignet_1_mat);
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
    iv->poignet_2_mat->emissiveColor.setValue(0.890196, 0.411765, 0.125490);
    iv->poignet_2_base->addChild(iv->poignet_2_mat);
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

  //C est ici qu on decide de faire rentrer l interface dans la fenetre principale ou non
  interface = new Interface();
  interface->show();
  interface->move(QPoint(1040,0));

  app.setMainWidget(myWidget);
  myWidget->resize(1024,800);
  myWidget->move(QPoint(0,0));
  myWidget->show();

  //iv->viewer->setViewing(false);
  iv->viewer->viewAll();;
  iv->viewer->setHeadlight(true);
  //Couleur de fond
  iv->viewer->setBackgroundColor(SbColor(0, 0, 0));

  SoQt::mainLoop();
  //delete(&robot.getViewer());
  delete iv->viewer;

  return 0;
}

void KeyboardCBFunction(void *userData, SoEventCallback *eventCB)
{
 //printf("in Keyboard CB function...");

 const SoEvent *event = eventCB->getEvent();
 float tmp;

 if (SO_KEY_PRESS_EVENT(event, SPACE))
 {
     uncolorAll();
     interface->keyboard_mode->setChecked(false);
 }

 if (SO_KEY_PRESS_EVENT(event, A))
 {
     tmp = interface->sliderX->value();
     interface->sliderX->setValue(tmp+20);
     interface->on_sliderX_valueChanged(tmp+20);
 }
 if (SO_KEY_PRESS_EVENT(event, Z))
 {
     tmp = interface->sliderX->value();
     interface->sliderX->setValue(tmp-20);
     interface->on_sliderX_valueChanged(tmp-20);
 }

 if (SO_KEY_PRESS_EVENT(event, E))
 {
     tmp = interface->sliderY->value();
     interface->sliderY->setValue(tmp+20);
     interface->on_sliderY_valueChanged(tmp+20);
}
 if (SO_KEY_PRESS_EVENT(event, R))
 {
     tmp = interface->sliderY->value();
     interface->sliderY->setValue(tmp-20);
     interface->on_sliderY_valueChanged(tmp-20);
 }

 if (SO_KEY_PRESS_EVENT(event, T))
 {
     tmp = interface->sliderZ->value();
     interface->sliderZ->setValue(tmp+20);
     interface->on_sliderZ_valueChanged(tmp+20);
 }
 if (SO_KEY_PRESS_EVENT(event, Y))
 {
     tmp = interface->sliderZ->value();
     interface->sliderZ->setValue(tmp-20);
     interface->on_sliderZ_valueChanged(tmp-20);
 }

 if (SO_KEY_PRESS_EVENT(event, Q))
 {
     tmp = interface->sliderZx->value();
     interface->sliderZx->setValue(tmp+5);
     interface->on_sliderZx_valueChanged(tmp+5);
 }
 if (SO_KEY_PRESS_EVENT(event, S))
 {
     tmp = interface->sliderZx->value();
     interface->sliderZx->setValue(tmp-5);
     interface->on_sliderZx_valueChanged(tmp-5);
 }

 if (SO_KEY_PRESS_EVENT(event, D))
 {
     tmp = interface->sliderZy->value();
     interface->sliderZy->setValue(tmp+5);
     interface->on_sliderZy_valueChanged(tmp+5);
 }
 if (SO_KEY_PRESS_EVENT(event, F))
 {
     tmp = interface->sliderZy->value();
     interface->sliderZy->setValue(tmp-5);
     interface->on_sliderZy_valueChanged(tmp-5);
 }
 if (SO_KEY_PRESS_EVENT(event, G))
 {
     tmp = interface->sliderZz->value();
     interface->sliderZz->setValue(tmp+5);
     interface->on_sliderZz_valueChanged(tmp+5);
 }
 if (SO_KEY_PRESS_EVENT(event, H))
 {
     tmp = interface->sliderZz->value();
     interface->sliderZz->setValue(tmp-5);
     interface->on_sliderZz_valueChanged(tmp-5);
 }

 if (SO_KEY_PRESS_EVENT(event, O))
 {
     interface->move_grid->setValue(0);
     iv->grille_translation->translation= SbVec3f(0, 0, 0);
 }





 if (SO_KEY_PRESS_EVENT(event, PAD_1)) {
   //fprintf(stderr, "pressed 'PAD_1' key ");

    if ( axis == 1 )
    {
        axis = 0;
        uncolorAll();
    }
    else
    {
        axis = 1;
        uncolorAll();
        iv->base_mobile_mat->emissiveColor.setValue(0, 0, 1);
        iv->parallelogramme_avant_mat->emissiveColor.setValue(0, 0, 1);
        iv->bitoniot_arriere_mat->emissiveColor.setValue(0, 0, 1);
        iv->cylindre_base_mat->emissiveColor.setValue(0, 0, 1);
        iv->sortie_cylindre_mat->emissiveColor.setValue(0, 0, 1);
        iv->parallelogramme_arriere_mat->emissiveColor.setValue(0, 0, 1);
        iv->coude_mat->emissiveColor.setValue(0, 0, 1);
        iv->avant_bras_mat->emissiveColor.setValue(0, 0, 1);
        iv->poignet_1_mat->emissiveColor.setValue(0, 0, 1);
        iv->poignet_2_mat->emissiveColor.setValue(0, 0, 1);
    }
 }

 if (SO_KEY_PRESS_EVENT(event, PAD_2)) {

     if ( axis == 2 )
    {
        axis = 0;
        uncolorAll();
    }
    else
    {
        axis = 2;
        uncolorAll();
        iv->parallelogramme_avant_mat->emissiveColor.setValue(0, 0, 1);
        iv->cylindre_base_mat->emissiveColor.setValue(0, 0, 1);
        iv->sortie_cylindre_mat->emissiveColor.setValue(0, 0, 1);
        iv->parallelogramme_arriere_mat->emissiveColor.setValue(0, 0, 1);
        iv->coude_mat->emissiveColor.setValue(0, 0, 1);
        iv->avant_bras_mat->emissiveColor.setValue(0, 0, 1);
        iv->poignet_1_mat->emissiveColor.setValue(0, 0, 1);
        iv->poignet_2_mat->emissiveColor.setValue(0, 0, 1);
    }
 }

 if (SO_KEY_PRESS_EVENT(event, PAD_3)) {

     if ( axis == 3 )
    {
        axis = 0;
        uncolorAll();
    }
    else
    {
        axis = 3;
        uncolorAll();
        iv->bitoniot_arriere_mat->emissiveColor.setValue(0, 0, 1);
        iv->parallelogramme_arriere_mat->emissiveColor.setValue(0, 0, 1);
        iv->coude_mat->emissiveColor.setValue(0, 0, 1);
        iv->avant_bras_mat->emissiveColor.setValue(0, 0, 1);
        iv->poignet_1_mat->emissiveColor.setValue(0, 0, 1);
        iv->poignet_2_mat->emissiveColor.setValue(0, 0, 1);
    }
 }

 if (SO_KEY_PRESS_EVENT(event, PAD_4)) {

     if ( axis == 4 )
    {
        axis = 0;
        uncolorAll();
    }
    else
    {
        axis = 4;
        uncolorAll();
        iv->avant_bras_mat->emissiveColor.setValue(0, 0, 1);
        iv->poignet_1_mat->emissiveColor.setValue(0, 0, 1);
        iv->poignet_2_mat->emissiveColor.setValue(0, 0, 1);
    }
 }

 if (SO_KEY_PRESS_EVENT(event, PAD_5)) {

     if ( axis == 5 )
    {
        axis = 0;
        uncolorAll();
    }
    else
    {
        axis = 5;
        uncolorAll();
        iv->poignet_1_mat->emissiveColor.setValue(0, 0, 1);
        iv->poignet_2_mat->emissiveColor.setValue(0, 0, 1);
    }
 }

 if (SO_KEY_PRESS_EVENT(event, PAD_6)) {

     if ( axis == 6 )
    {
        axis = 0;
        uncolorAll();
    }
    else
    {
        axis = 6;
        uncolorAll();
        iv->poignet_2_mat->emissiveColor.setValue(0, 0, 1);
    }
 }

 if (SO_KEY_PRESS_EVENT(event, PAD_7)) {

     axis = 0;
     uncolorAll();
}

 if (SO_KEY_PRESS_EVENT(event, PAD_8)) {

     if (event->wasShiftDown())
     {
         tmp = interface->move_grid->value();
         if ( tmp > -290 )
         {
             interface->move_grid->setValue(tmp-10);
             iv->grille_translation->translation= SbVec3f(0, 0, (tmp-10)/1000);
         }
     }
     else
     {
        if ( axis > 0 )
        {
            axis--;
        }

        uncolorAll();
        recolor(axis);
    }
}


 if (SO_KEY_PRESS_EVENT(event, PAD_9)) {

     if (event->wasShiftDown())
     {
         tmp = interface->move_grid->value();
         if ( tmp < 2140 )
         {
             interface->move_grid->setValue(tmp+10);
             iv->grille_translation->translation= SbVec3f(0, 0, (tmp+10)/1000);
         }
     }
     else
     {
        if ( axis < 6 )
        {
            axis++;
        }

        uncolorAll();
        recolor(axis);
    }
  }

 if (SO_KEY_PRESS_EVENT(event, N)) {

     interface->slider_base_mobile->setValue(165);
     interface->slider_parallelogramme->setValue(82);
     interface->slider_coude->setValue(62);
     interface->slider_avant_bras->setValue(200);
     interface->slider_poignet_1->setValue(120);
     interface->slider_poignet_2->setValue(400);

     interface->sliderX->setValue(1220);
     interface->sliderY->setValue(0);
     interface->sliderZ->setValue(1720);
     interface->sliderZx->setValue(1);
     interface->sliderZy->setValue(0);
     interface->sliderZz->setValue(0);
}


 if (SO_KEY_PRESS_EVENT(event, W)) {
   printf("pressed 'RIGHT_ARROW' key\n");
   switch(axis)
   {
   case 1 : oldValue = interface->slider_base_mobile->value();
            interface->slider_base_mobile->setValue(oldValue+1);
            interface->on_slider_base_mobile_valueChanged(oldValue+1);
            break;
   case 2 : oldValue = interface->slider_parallelogramme->value();
            interface->slider_parallelogramme->setValue(oldValue+1);
            interface->on_slider_parallelogramme_valueChanged(oldValue+1);
            break;
   case 3 : oldValue = interface->slider_coude->value();
            interface->slider_coude->setValue(oldValue+1);
            interface->on_slider_coude_valueChanged(oldValue+1);
            break;
   case 4 : oldValue = interface->slider_avant_bras->value();
            interface->slider_avant_bras->setValue(oldValue+1);
            interface->on_slider_avant_bras_valueChanged(oldValue+1);
            break;
   case 5 : oldValue = interface->slider_poignet_1->value();
            interface->slider_poignet_1->setValue(oldValue+1);
            interface->on_slider_poignet_1_valueChanged(oldValue+1);
            break;
   case 6 : oldValue = interface->slider_poignet_2->value();
            interface->slider_poignet_2->setValue(oldValue+1);
            interface->on_slider_poignet_2_valueChanged(oldValue+1);
            break;
   }
 }
 else if (SO_KEY_PRESS_EVENT(event, X)) {
   printf("pressed 'RIGHT_ARROW' key\n");
   switch(axis)
   {
   case 1 : oldValue = interface->slider_base_mobile->value();
            interface->slider_base_mobile->setValue(oldValue-1);
            interface->on_slider_base_mobile_valueChanged(oldValue-1);
            break;
   case 2 : oldValue = interface->slider_parallelogramme->value();
            interface->slider_parallelogramme->setValue(oldValue-1);
            interface->on_slider_parallelogramme_valueChanged(oldValue-1);
            break;
   case 3 : oldValue = interface->slider_coude->value();
            interface->slider_coude->setValue(oldValue-1);
            interface->on_slider_coude_valueChanged(oldValue-1);
            break;
   case 4 : oldValue = interface->slider_avant_bras->value();
            interface->slider_avant_bras->setValue(oldValue-1);
            interface->on_slider_avant_bras_valueChanged(oldValue-1);
            break;
   case 5 : oldValue = interface->slider_poignet_1->value();
            interface->slider_poignet_1->setValue(oldValue-1);
            interface->on_slider_poignet_1_valueChanged(oldValue-1);
            break;
   case 6 : oldValue = interface->slider_poignet_2->value();
            interface->slider_poignet_2->setValue(oldValue-1);
            interface->on_slider_poignet_2_valueChanged(oldValue-1);
            break;
   }
 }
}

void uncolorAll()
{
    iv->base_mobile_mat->emissiveColor.setValue(0.890196, 0.411765, 0.125490);
    iv->parallelogramme_avant_mat->emissiveColor.setValue(0.890196, 0.411765, 0.125490);
    iv->bitoniot_arriere_mat->emissiveColor.setValue(0.890196, 0.411765, 0.125490);
    iv->cylindre_base_mat->emissiveColor.setValue(0.890196, 0.411765, 0.125490);
    iv->sortie_cylindre_mat->emissiveColor.setValue(0.890196, 0.411765, 0.125490);
    iv->parallelogramme_arriere_mat->emissiveColor.setValue(0.890196, 0.411765, 0.125490);
    iv->coude_mat->emissiveColor.setValue(0.890196, 0.411765, 0.125490);
    iv->avant_bras_mat->emissiveColor.setValue(0.890196, 0.411765, 0.125490);
    iv->poignet_1_mat->emissiveColor.setValue(0.890196, 0.411765, 0.125490);
    iv->poignet_2_mat->emissiveColor.setValue(0.890196, 0.411765, 0.125490);
}

void recolor(int angle)
{

    switch(angle)
    {
    case 1 :
        iv->base_mobile_mat->emissiveColor.setValue(0, 0, 1);
        iv->parallelogramme_avant_mat->emissiveColor.setValue(0, 0, 1);
        iv->bitoniot_arriere_mat->emissiveColor.setValue(0, 0, 1);
        iv->cylindre_base_mat->emissiveColor.setValue(0, 0, 1);
        iv->sortie_cylindre_mat->emissiveColor.setValue(0, 0, 1);
        iv->parallelogramme_arriere_mat->emissiveColor.setValue(0, 0, 1);
        iv->coude_mat->emissiveColor.setValue(0, 0, 1);
        iv->avant_bras_mat->emissiveColor.setValue(0, 0, 1);
        iv->poignet_1_mat->emissiveColor.setValue(0, 0, 1);
        iv->poignet_2_mat->emissiveColor.setValue(0, 0, 1);
    break;
    case 2 :
        iv->parallelogramme_avant_mat->emissiveColor.setValue(0, 0, 1);
        iv->cylindre_base_mat->emissiveColor.setValue(0, 0, 1);
        iv->sortie_cylindre_mat->emissiveColor.setValue(0, 0, 1);
        iv->parallelogramme_arriere_mat->emissiveColor.setValue(0, 0, 1);
        iv->coude_mat->emissiveColor.setValue(0, 0, 1);
        iv->avant_bras_mat->emissiveColor.setValue(0, 0, 1);
        iv->poignet_1_mat->emissiveColor.setValue(0, 0, 1);
        iv->poignet_2_mat->emissiveColor.setValue(0, 0, 1);
    break;
    case 3 :
        iv->bitoniot_arriere_mat->emissiveColor.setValue(0, 0, 1);
        iv->parallelogramme_arriere_mat->emissiveColor.setValue(0, 0, 1);
        iv->coude_mat->emissiveColor.setValue(0, 0, 1);
        iv->avant_bras_mat->emissiveColor.setValue(0, 0, 1);
        iv->poignet_1_mat->emissiveColor.setValue(0, 0, 1);
        iv->poignet_2_mat->emissiveColor.setValue(0, 0, 1);
    break;
    case 4 :
        iv->avant_bras_mat->emissiveColor.setValue(0, 0, 1);
        iv->poignet_1_mat->emissiveColor.setValue(0, 0, 1);
        iv->poignet_2_mat->emissiveColor.setValue(0, 0, 1);
    break;
    case 5 :
        iv->poignet_1_mat->emissiveColor.setValue(0, 0, 1);
        iv->poignet_2_mat->emissiveColor.setValue(0, 0, 1);
    break;
    case 6 :
        iv->poignet_2_mat->emissiveColor.setValue(0, 0, 1);
    break;
    }
}
