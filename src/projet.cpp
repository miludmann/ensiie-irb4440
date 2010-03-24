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

#define SQUARE(x) ((x)*(x))
#define A2 0.200
#define A3 0.890
#define A4 0.150
#define R1 0.680
#define R4 0.880
#define R6 0.140

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

void IVLoader::repeat(float angle1, float angle2, float angle3, float angle4, float angle5, float angle6, int nb_iter)
{
    for (double i=0; i<=nb_iter; i++) {
        interface->horizontalSlider->setValue(165-i*(165-angle1)/nb_iter);
        interface->horizontalSlider->repaint();
        interface->horizontalSlider_2->setValue(82-i*(82-angle2)/nb_iter);
        interface->horizontalSlider_2->repaint();
        interface->horizontalSlider_3->setValue(62-i*(62-angle3)/nb_iter);
        interface->horizontalSlider_3->repaint();
        interface->horizontalSlider_4->setValue(200-i*(200-angle4)/nb_iter);
        interface->horizontalSlider_4->repaint();
        interface->horizontalSlider_5->setValue(120-i*(120-angle5)/nb_iter);
        interface->horizontalSlider_5->repaint();
        interface->horizontalSlider_6->setValue(400-i*(400-angle6)/nb_iter);
        interface->horizontalSlider_6->repaint();
        viewer->render();
        millisleep(20);
    }
}

void IVLoader::repeat_from_current(float angle1, float angle2, float angle3, float angle4, float angle5, float angle6, int nb_iter)
{
    double angle1_current = interface->horizontalSlider->value();
    double angle2_current = interface->horizontalSlider_2->value();
    double angle3_current = interface->horizontalSlider_3->value();
    double angle4_current = interface->horizontalSlider_4->value();
    double angle5_current = interface->horizontalSlider_5->value();
    double angle6_current = interface->horizontalSlider_6->value();

    for (double i=0; i<=nb_iter; i++) {
        interface->horizontalSlider->setValue(angle1_current-i*(angle1_current-angle1)/nb_iter);
        interface->horizontalSlider->repaint();
        interface->horizontalSlider_2->setValue(angle2_current-i*(angle2_current-angle2)/nb_iter);
        interface->horizontalSlider_2->repaint();
        interface->horizontalSlider_3->setValue(angle3_current-i*(angle3_current-angle3)/nb_iter);
        interface->horizontalSlider_3->repaint();
        interface->horizontalSlider_4->setValue(angle4_current-i*(angle4_current-angle4)/nb_iter);
        interface->horizontalSlider_4->repaint();
        interface->horizontalSlider_5->setValue(angle5_current-i*(angle5_current-angle5)/nb_iter);
        interface->horizontalSlider_5->repaint();
        interface->horizontalSlider_6->setValue(angle6_current-i*(angle6_current-angle6)/nb_iter);
        interface->horizontalSlider_6->repaint();
        viewer->render();
        millisleep(20);
    }
}

void IVLoader::repeat_control_mgd()
{
    float angle1 = interface->horizontalSlider->value();
    float angle2 = interface->horizontalSlider_2->value();
    float angle3 = interface->horizontalSlider_3->value();
    float angle4 = interface->horizontalSlider_4->value();
    float angle5 = interface->horizontalSlider_5->value();
    float angle6 = interface->horizontalSlider_6->value();

    repeat(angle1, angle2, angle3, angle4, angle5, angle6, 50);
}

QVector<double> IVLoader::mgi(double px, double py, double pz, double zx_nnorme, double zy_nnorme, double zz_nnorme)
{    
    //On norme le vecteur Z
    double zNorm = sqrt(SQUARE(zx_nnorme) + SQUARE(zy_nnorme) + SQUARE(zz_nnorme));
    double zx = zx_nnorme/zNorm;
    double zy = zy_nnorme/zNorm;
    double zz = zz_nnorme/zNorm;

    pz = pz - R1;

    //Vecteur X
    double xx = -zy;
    double xy = zx;
    double xz = 0;

    //Vecteur Y
    double yx = -zx * zz;
    double yy = -zy * zz;
    double yz = SQUARE(zx) + SQUARE(zy);

    double theta1, theta2, theta3, theta4, theta5, theta6;

    /*
    //Theta1
    double theta1 = atan2(py - zy * R6, px - zx * R6);
    double c1 = cos(theta1);
    double s1 = sin(theta1);

    //Theta2 et Theta3
    double alpha = (px - zx * R6)/c1 - A2;
    double beta = (py - zy * R6)/s1 - A2;
    double gamma = pz - zz * R6;

    double delta = 1/(2 * alpha)*(SQUARE(A3) - SQUARE(A4) - SQUARE(R4) - SQUARE(gamma) - SQUARE(alpha));
    double c23 = (-R4 * delta + A4 * sqrt(SQUARE(A4) + SQUARE(R4) - SQUARE(delta))) / (SQUARE(A4) + SQUARE(R4));
    double s23 = (A4 * delta + R4 * sqrt(SQUARE(A4) + SQUARE(R4) - SQUARE(delta))) / (SQUARE(A4) + SQUARE(R4));

    double c2 = (gamma - R4 * s23 - A4 * c23) * 1/A3;
    double s2 = (R4 * c23 - A4 * s23 - alpha) * 1/A3;
    double theta2 = atan2(s2, c2);

    double c3 = c23 * c2 + s23 * s2;
    double s3 = s23 * c2 - c23 * s2;
    double theta3 = atan2(s3, c3);

    //Theta4
    double lambda1 = xz * c1 / (yy * xz - yz * xy);
    double lambda2 = xz * s1 / (yx * zx - yz * xx);
    double lambda = lambda1 - lambda2;

    double mu1 = (xz * s1 * s23 + c23) / (yy * xz - yz * xy);
    double mu2 = (xz * c1 * s23 + c23) / (yx * xz - yz * xx);
    double mu = mu1 - mu2;

    double theta4 = atan(- lambda / mu);
    double c4 = cos(theta4);
    double s4 = sin(theta4);

    //Theta5
    double c5 = (s23 * zz + c23 * c4 * sqrt(SQUARE(c23) * SQUARE(c4) + SQUARE(s23) - SQUARE(zz))) / (SQUARE(c23) + SQUARE(c4));
    double s5 = (c23 * c4 * zz + s23 * sqrt(SQUARE(c23) * SQUARE(c4) + SQUARE(s23) - SQUARE(zz))) / (SQUARE(c23) + SQUARE(c4));
    double theta5 = atan2(s5, c5);

    //Theta6
    double c6 = (-yz * c23 * s4 + xz * sqrt(SQUARE(xz) + SQUARE(yz) - SQUARE(c23) * SQUARE(s4))) / (SQUARE(xz) + SQUARE(yz));
    double s6 = (-xz * c23 * s4 + yz * sqrt(SQUARE(xz) + SQUARE(yz) - SQUARE(c23) * SQUARE(s4))) / (SQUARE(xz) + SQUARE(yz));
    double theta6 = atan2(s6, c6);
*/

    //theta1
    double pwx = px - R6 * zx;
    double pwy = py - R6 * zy;
    double pwz = pz - R6 * zz;
    theta1 = atan2(pwy, pwx);

    //theta3
    double pwx1_tmp = sqrt(SQUARE(pwx) + SQUARE(pwy)) - A2;
    double pwz1_tmp = pwz;
    double b4 = sqrt(A4*A4 + R4*R4);
    double s3_tmp = (SQUARE(pwx1_tmp) + SQUARE(pwz1_tmp) - A3*A3 - SQUARE(b4)) / (2 * A3 * b4);
    double c3_tmp = sqrt(1 - SQUARE(s3_tmp));
    double theta3_tmp = atan2(s3_tmp, c3_tmp);
    theta3 = theta3_tmp - atan2(A4, R4);

    //theta2
    double c2 = ((A3 + b4 * s3_tmp) * pwz1_tmp + b4 * c3_tmp * pwx1_tmp) / (A3*A3 + SQUARE(b4) + 2 * A3 * b4 * s3_tmp);
    double s2 = (-(A3 + b4 * s3_tmp) * pwx1_tmp + b4 * c3_tmp * pwz1_tmp) / (A3 * A3 + SQUARE(b4) + 2 * A3 * b4 * s3_tmp);
    theta2 = atan2(s2, c2);

    //theta4, theta5 et theta6
    double c1 = cos(theta1);
    double s1 = sin(theta1);
    double c23 = cos(theta2 + theta3);
    double s23 = sin(theta2 + theta3);
    double r13 = -c1 * s23 * zx - s1 * s23 * zy + c23 * zz;

    double r33 = s1 * zx - c1 * zy;
    double r21 = -c1 * c23 * xx - s1 * c23 * xy - s23 * xz;
    double r22 = -c1 * c23 * yx - s1 * c23 * yy - s23 * yz;
    double r23 = -c1 * c23 * zx - s1 * c23 * zy - s23 * zz;

    theta4 = atan2(r33, r13);
    theta5 = atan2(sqrt(SQUARE(r13) + SQUARE(r33)), -r23);
    theta6 = atan2(-r22, r21);

    theta1 = theta1 * 180 / M_PI + 165;
    theta2 = -theta2 * 180 / M_PI + 82;
    theta3 = -theta3 * 180 / M_PI + 62;
    theta4 = theta4 * 180 / M_PI + 200;
    theta5 = -theta5 * 180 / M_PI + 120;
    theta6 = theta6 * 180 / M_PI + 400;

    if (isnan(theta1) || isnan(theta2) || isnan(theta3) || isnan(theta4) || isnan(theta5) || isnan(theta6))
    {
        char buffer[7777];
        sprintf(buffer,"Robot stoppe car (%f,%f,%f) est hors d'atteinte.\nt1=%f, t2=%f, t3=%f, t4=%f, t5=%f, t6=%f", px_wanted, py_wanted, pz_wanted, theta1, theta2, theta3, theta4, theta5, theta6);
        interface->textBrowser_2->setText(QString(buffer));
    }

    //Vecteur des angles résultats
    QVector<double> thetas(6);

    thetas[0] = theta1;
    thetas[1] = theta2;
    thetas[2] = theta3;
    thetas[3] = theta4;
    thetas[4] = theta5;
    thetas[5] = theta6;

    return thetas;
}

void IVLoader::on_lancer_commande()
{
    px_wanted = interface->spinX->value();
    py_wanted = interface->spinY->value();
    pz_wanted = interface->spinZ->value();
    zx_wanted = interface->spinZx->value();
    zy_wanted = interface->spinZy->value();
    zz_wanted = interface->spinZz->value();

    QVector<double> thetas = mgi(px_wanted, py_wanted, pz_wanted, zx_wanted, zy_wanted, zz_wanted);

    if(interface->radioButton_11->isChecked())
    {
        repeat(thetas[0], thetas[1], thetas[2], thetas[3], thetas[4], thetas[5], 50);

    } else {      
        if(interface->radioButton_21->isChecked())
        {
            repeat_from_current(thetas[0], thetas[1], thetas[2], thetas[3], thetas[4], thetas[5], 50);
        } else {
            interface->horizontalSlider->setValue(thetas[0]);
            interface->horizontalSlider_2->setValue(thetas[1]);
            interface->horizontalSlider_3->setValue(thetas[2]);
            interface->horizontalSlider_4->setValue(thetas[3]);
            interface->horizontalSlider_5->setValue(thetas[4]);
            interface->horizontalSlider_6->setValue(thetas[5]);
        }
    }
}

void IVLoader::default_mgi()
{
    interface->spinX->setValue(1.22);
    interface->spinY->setValue(0.00);
    interface->spinZ->setValue(1.75);
    interface->spinZx->setValue(1.00);
    interface->spinZy->setValue(0.00);
    interface->spinZz->setValue(0.00);
}

