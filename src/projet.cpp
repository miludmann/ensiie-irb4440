#include "projet.h"

#include <Inventor/Qt/SoQt.h>
#include <q3filedialog.h>
#include <qdir.h>
#include <qmessagebox.h>

#include "interface2.h"

#include <Inventor/Qt/viewers/SoQtViewer.h>

#include <math.h>
#include <stdlib.h>

#include <qlabel.h>
#include <qlineedit.h>
#include <qslider.h>
#include <qlcdnumber.h>

// pour la compatibilit MS/Linux de la fonction sleep....
# ifdef _MSC_VER       // si on a un compilateur MS
#include <Windows.h>
# else                 // sinon, Linux/MacOS/BSD
#include <time.h>
# endif
#include <ctime>
#include <iostream>


extern Interface *interface;

extern IRB4400 *root;

SoNode *repere_r0Tmp;
SoNode *repere_r1Tmp;
SoNode *repere_r2Tmp;
SoNode *repere_r3Tmp;
SoNode *repere_r4Tmp;
SoNode *repere_r5Tmp;
SoNode *repere_r6Tmp;

void millisleep( unsigned int milliseconds )
{
# ifdef _MSC_VER   // si MS
  ::Sleep( milliseconds);
#else  // sinon, sans doute linux/MacOS/BSD
  timespec ts;
  ts.tv_sec = milliseconds / 1000;
  ts.tv_nsec = (milliseconds - ts.tv_sec*1000) * 1000000;
  ::nanosleep(&ts, NULL);
# endif
}


IRB4400::IRB4400(QWidget* parent) : QObject(parent)
{
  SoQt::init(parent);
  viewer = new SoQtExaminerViewer(parent);
  separator = new SoSeparator;

  viewer->setSceneGraph(separator);
  //viewer->setDecoration(false);
  viewer->show();

}

IRB4400::~IRB4400()
{
  delete viewer;
}

void IRB4400::openFile(QString s)
{
  // Lecture du graphe de scene
  SoInput sceneInput;
  if ( !sceneInput.openFile(s.ascii()))
  {
    QMessageBox::information((QWidget*)parent(),
        "Erreur de lecture",
        "Le fichier selectionne n'a pas pu etre ouvert.");
    return;
  }
  separator = SoDB::readAll(&sceneInput);
  if ( separator == NULL)
  {
    QMessageBox::information((QWidget*)parent(),
        "Erreur de lecture",
        "Le fichier selectionne n'a pas pu etre decode.");
    return ;
  }
  sceneInput.closeFile();

  // Association du graphe de scene au viewer
  viewer->setSceneGraph(separator);
  viewer->render();
}


void IRB4400::openMember(QString s, SoSeparator *new_separator, SoSeparator *root)
{
  // Lecture du graphe de scne
  SoInput sceneInput;
  if ( !sceneInput.openFile(s.ascii()))
  {
    QMessageBox::information((QWidget*)parent(),
        "Erreur de lecture",
        "Le fichier selectionne n'a pas pu etre ouvert.");
    return;
  }

  new_separator = SoDB::readAll(&sceneInput);
  if ( new_separator == NULL)
  {
    QMessageBox::information((QWidget*)parent(),
        "Erreur de lecture",
        "Le fichier selectionne n'a pas pu etre decode.");
    return;
  }
  new_separator->ref();
  root->addChild(new_separator);
  sceneInput.closeFile();
  viewer->render();
}


void IRB4400::openFileDialog()
{
  // ouverture d'une boite de dialogue
  QString s = Q3FileDialog::getOpenFileName(
      QDir::currentDirPath(),
      "Inventor or VRML files (*.*)",
      (QWidget*)parent(),
      "open file dialog",
      "Choose a file to open" );

  // Si annulation alors arrter
  if (s.isEmpty())
    return ;

  openFile(s);
}

SoQtExaminerViewer IRB4400::getViewer()
{
    return *viewer;
}

void IRB4400::move_grille(int val)
{
  double position=interface->verticalSlider->value();
  position = position / 1000;
  grille_translation->translation= SbVec3f(0, 0, position);;
}

void IRB4400::reset_grille()
{
  grille_translation->translation= SbVec3f(0, 0, 0);;
  interface->verticalSlider->setValue(0);
}

void IRB4400::x_changed(const QString& text)
{
  x_wanted = strtod((char *)text.data(), (char**)NULL);
}

void IRB4400::y_changed(const QString& text)
{
  y_wanted = strtod((char *)text.data(), (char**)NULL);
}

void IRB4400::z_changed(const QString& text)
{
  z_wanted = strtod((char *)text.data(), (char**)NULL);
}


void IRB4400::center_scene()
{
  viewer->viewAll();
}

void IRB4400::toggle_moving_mode(int state)
{
  mode=1;
}

void IRB4400::toggle_moving_mode2(int state)
{
  mode=0;
}

void IRB4400::toggle_headlight(int state)
{
  if (state)
  {
    viewer->setHeadlight(true);
  }else{
    viewer->setHeadlight(false);
  }
}

void IRB4400::toggle_fil_de_fer(int state)
{
  if (state)
  {
    viewer->setDrawStyle(SoQtViewer::INTERACTIVE, SoQtViewer::VIEW_LINE);
    viewer->setDrawStyle(SoQtViewer::STILL, SoQtViewer::VIEW_LINE);
  }else{
    viewer->setDrawStyle(SoQtViewer::INTERACTIVE, SoQtViewer::VIEW_AS_IS);
    viewer->setDrawStyle(SoQtViewer::STILL, SoQtViewer::VIEW_AS_IS);
  }
}


void IRB4400::toggle_rep0(int state)
{
  if (state)
  {
    repere_r0_base->insertChild(repere_r0Tmp, 0);
    viewer->render();
  }else{
    //suppression du repère affiché ("3" correspond au premier enfant du noeud, i.e. le repère ici)
    repere_r0Tmp = repere_r0_base->getChild(0);
    repere_r0_base->removeChild(0);
    viewer->render();
  }
}

void IRB4400::toggle_rep1(int state)
{
  if (state)
  {
    repere_r1_base->insertChild(repere_r1Tmp, 1);
    viewer->render();
  }else{
    //suppression du repère affiché ("3" correspond au premier enfant du noeud, i.e. le repère ici)
    repere_r1Tmp = repere_r1_base->getChild(1);
    repere_r1_base->removeChild(1);
    viewer->render();
  }
}

void IRB4400::toggle_rep2(int state)
{
  if (state)
  {
    repere_r2_base->insertChild(repere_r2Tmp, 3);
    viewer->render();
  }else{
    //suppression du repère affiché ("3" correspond au premier enfant du noeud, i.e. le repère ici)
    repere_r2Tmp = repere_r2_base->getChild(3);
    repere_r2_base->removeChild(3);
    viewer->render();
  }
}

void IRB4400::toggle_rep3(int state)
{
  if (state)
  {
    repere_r3_base->insertChild(repere_r3Tmp, 3);
    viewer->render();
  }else{
    //suppression du repère affiché ("3" correspond au premier enfant du noeud, i.e. le repère ici)
    repere_r3Tmp = repere_r3_base->getChild(3);
    repere_r3_base->removeChild(3);
    viewer->render();
  }
}

void IRB4400::toggle_rep4(int state)
{
  if (state)
  {
    repere_r4_base->insertChild(repere_r4Tmp, 3);
    viewer->render();
  }else{
    //suppression du repère affiché ("3" correspond au premier enfant du noeud, i.e. le repère ici)
    repere_r4Tmp = repere_r4_base->getChild(3);
    repere_r4_base->removeChild(3);
    viewer->render();
  }
}

void IRB4400::toggle_rep5(int state)
{
  if (state)
  {
    repere_r5_base->insertChild(repere_r5Tmp, 3);
    viewer->render();
  }else{
    //suppression du repère affiché ("3" correspond au premier enfant du noeud, i.e. le repère ici)
    repere_r5Tmp = repere_r5_base->getChild(3);
    repere_r5_base->removeChild(3);
    viewer->render();
  }
}

void IRB4400::toggle_rep6(int state)
{
  if (state)
  {
    repere_r6_base->insertChild(repere_r6Tmp, 3);
    viewer->render();
  }else{
    //suppression du repère affiché ("3" correspond au premier enfant du noeud, i.e. le repère ici)
    repere_r6Tmp = repere_r6_base->getChild(3);
    repere_r6_base->removeChild(3);
    viewer->render();
  }
}

void IRB4400::move_base_mobile(int angle)
{
    base_mobile_transform->rotation.setValue(SbVec3f(0, 0, 1), (angle-165)*M_PI/180);
}

void IRB4400::move_avant_bras(int angle)
{
    avant_bras_transform->rotation.setValue(SbVec3f(1, 0, 0), (angle-200)*M_PI/180);
}

void IRB4400::move_poignet_1(int angle)
{
    poignet_1_transform->rotation.setValue(SbVec3f(0, 1, 0), (angle-120)*M_PI/180);
}

void IRB4400::move_poignet_2(int angle)
{
    poignet_2_transform->rotation.setValue(SbVec3f(1, 0, 0), (angle-400)*M_PI/180);
}

void IRB4400::move_parallelogramme(int angle)
{
    static float angle3 = interface->horizontalSlider_3->value();

    parallelogramme_avant_transform->rotation.setValue(SbVec3f(0, 1, 0), (angle-82)*M_PI/180);
    interface->horizontalSlider_3->setValue(angle3+82-angle);
    //move_coude(angle3+82-angle);
}

void IRB4400::move_coude(int angle)
{
    coude_transform->rotation.setValue(SbVec3f(0, 1, 0), (angle-62)*M_PI/180);
    bitoniot_arriere_transform->rotation.setValue(SbVec3f(0, 1, 0), (angle-62)*M_PI/180);
    parallelogramme_arriere_transform->rotation.setValue(SbVec3f(0, 1, 0), -(angle-62)*M_PI/180);
}

void IRB4400::reset_sliders()
{
    interface->horizontalSlider->setValue(165);
    interface->horizontalSlider_2->setValue(82);
    interface->horizontalSlider_3->setValue(62);
    interface->horizontalSlider_4->setValue(200);
    interface->horizontalSlider_5->setValue(120);
    interface->horizontalSlider_6->setValue(400);
}

void IRB4400::repeat_command()
{
    float angle1 = interface->horizontalSlider->value();
    float angle2 = interface->horizontalSlider_2->value();
    float angle3 = interface->horizontalSlider_3->value();
    float angle4 = interface->horizontalSlider_4->value();
    float angle5 = interface->horizontalSlider_5->value();
    float angle6 = interface->horizontalSlider_6->value();

    interface->horizontalSlider->setValue(165);
    interface->horizontalSlider_2->setValue(82);
    interface->horizontalSlider_3->setValue(62);
    interface->horizontalSlider_4->setValue(200);
    interface->horizontalSlider_5->setValue(120);
    interface->horizontalSlider_6->setValue(400);

    for (double i=0; i<50; i++) {
        move_base_mobile(165-i*(165-angle1)/50);
        interface->horizontalSlider->setValue(165-i*(165-angle1)/50);
        move_parallelogramme(82-i*(82-angle2)/50);
        interface->horizontalSlider_2->setValue(82-i*(82-angle2)/50);
        move_coude(62-i*(62-angle3)/50);
        interface->horizontalSlider_3->setValue(62-i*(62-angle3)/50);
        move_avant_bras(200-i*(200-angle4)/50);
        interface->horizontalSlider_4->setValue(200-i*(200-angle4)/50);
        move_poignet_1(140-i*(140-angle5)/50);
        interface->horizontalSlider_5->setValue(140-i*(140-angle5)/50);
        move_poignet_2(400-i*(400-angle6)/50);
        interface->horizontalSlider_6->setValue(400-i*(400-angle6)/50);
        viewer->render();
        millisleep(20);
    }
}

void IRB4400::move()
{/*
  if (mode == 0) {
    // on est en mode direct.
    if (gotoposition(x_wanted, y_wanted, z_wanted)) {
      x_initial = x_wanted;
      y_initial = y_wanted;
      z_initial = z_wanted;
    }
  } else {
    // on est en mode progressif
    move_progressif(x_initial, x_wanted, y_initial, y_wanted, z_initial, z_wanted, root);
  }
  */
}

