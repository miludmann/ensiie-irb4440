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

  flag = false;
  angle23 = 82 + 62;

  a = 0.6933703916;
  b = 0.122805578;
  c = 0.8161759675;
  old2 = 82;
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

void IVLoader::move_base_mobile(int angle)
{
    base_mobile_transform->rotation.setValue(SbVec3f(0, 0, 1), (angle-165)*M_PI/180);
}

void IVLoader::move_avant_bras(int angle)
{
    avant_bras_transform->rotation.setValue(SbVec3f(1, 0, 0), (angle-200)*M_PI/180);
}

void IVLoader::move_poignet_1(int angle)
{
    poignet_1_transform->rotation.setValue(SbVec3f(0, 1, 0), (angle-120)*M_PI/180);
}

void IVLoader::move_poignet_2(int angle)
{
    poignet_2_transform->rotation.setValue(SbVec3f(1, 0, 0), (angle-400)*M_PI/180);
}

void IVLoader::move_parallelogramme(int angle)
{
    float angle3 = interface->horizontalSlider_3->value();
    float ang2, c2;


    if ( (angle3 == 0 && angle > old2)
        || (angle3 == 125 && angle < old2) )
    {
        interface->horizontalSlider_2->setValue(old2);
    }
    else
    {
        if ( angle-old2 > angle3 )
        {
            interface->horizontalSlider_2->setValue(old2+angle3);
        }
        else
        {
            if ( old2-angle + angle3 > 125 )
            {
                interface->horizontalSlider_2->setValue(old2-(125-angle3));
            }
            else
            {
                if ( angle3 >= 0 && angle3 <= 125)
                {
                    c2 = sqrt(a*a+b*b+2*a*b*cos((((float) 180)+angle-82)/180*M_PI));
                    ang2 = acos((c2*c2+a*a-b*b)/(2*a*c2))*180/M_PI*(angle-82)/abs(angle-82);
                    old2 = angle;

                    flag = true;
                    parallelogramme_avant_transform->rotation.setValue(SbVec3f(0, 1, 0), (angle-82)*M_PI/180);
                    interface->horizontalSlider_3->setValue(angle23-angle);
                    //move_coude(angle3+82-angle);

                    cylindre_base_transform->rotation.setValue(SbVec3f(0, 1, 0), ang2*M_PI/180);
                    sortie_cylindre_transform->rotation.setValue(SbVec3f(0, 1, 0), (ang2+(82-angle))*M_PI/180);
                }
            }
        }
    }
}

void IVLoader::move_coude(int angle)
{
    float angle2 = interface->horizontalSlider_2->value();

    if ( angle+angle2 >= 62+82-20 )
    {
        coude_transform->rotation.setValue(SbVec3f(0, 1, 0), (angle-62)*M_PI/180);
        bitoniot_arriere_transform->rotation.setValue(SbVec3f(0, 1, 0), (angle-62)*M_PI/180);
        parallelogramme_arriere_transform->rotation.setValue(SbVec3f(0, 1, 0), -(angle-62)*M_PI/180);

        if(!flag)
        {
            angle23 = angle + interface->horizontalSlider_2->value();
        } else {
            flag = false;
        }
    }
    else
    {
        interface->horizontalSlider_3->setValue(62+82-20-angle2);
    }
}


