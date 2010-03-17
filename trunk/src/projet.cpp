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
  position = position / 100;
  position = (position)*4;
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
    base_mobile_repere->ref();
    viewer->render();
  }else{
    base_mobile_repere->unref();
    viewer->render();
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

