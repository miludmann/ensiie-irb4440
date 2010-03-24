#include "projet.h"
#include "mainWidget.h"

#include <Inventor/Qt/SoQt.h>
#include <q3filedialog.h>
#include <qdir.h>
#include <qmessagebox.h>

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
extern IVLoader *iv;

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


IVLoader::IVLoader(QWidget* parent) : QObject(parent)
{
  SoQt::init(parent);
  viewer = new SoQtExaminerViewer(parent);
  separator = new SoSeparator;

  viewer->setSceneGraph(separator);
  //viewer->setDecoration(false);
  viewer->show();
}

IVLoader::~IVLoader()
{
  delete viewer;
}

void IVLoader::openFile(QString s)
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


void IVLoader::openMember(QString s, SoSeparator *new_separator, SoSeparator *iv)
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
  iv->addChild(new_separator);
  sceneInput.closeFile();
  viewer->render();
}


void IVLoader::openFileDialog()
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

SoQtExaminerViewer IVLoader::getViewer()
{
    return *viewer;
}


