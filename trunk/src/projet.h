#ifndef __PROJET_H__
#define __PROJET_H__

#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoTranslation.h>
#include <Inventor/nodes/SoRotation.h>
#include <Inventor/nodes/SoMaterial.h>
#include <Inventor/nodes/SoTransform.h>
#include <Inventor/nodes/SoDirectionalLight.h>
#include <Inventor/nodes/SoPerspectiveCamera.h>

#include <Inventor/nodes/SoEventCallback.h>

#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>

#include <qobject.h>
#include <math.h>
#include <QVector>

#define M_PI 3.14159265358979323846

void millisleep( unsigned int milliseconds );

class IVLoader : public QObject
{
  Q_OBJECT
  public :
    IVLoader(QWidget* parent);
    ~IVLoader();
    void openFile(QString s);
    void openMember(QString s, SoSeparator *new_separator, SoSeparator *iv);

    //matiere
    SoMaterial *matiere;
    //iv
    SoSeparator *separator;

    //hanoi
      SoSeparator *hanoi1_base;
      SoTransform *hanoi1_transform;
      SoRotation *hanoi1_rotor;
      SoSeparator *hanoi1;

      SoSeparator *hanoi2_base;
      SoTransform *hanoi2_transform;
      SoRotation *hanoi2_rotor;
      SoSeparator *hanoi2;

      SoSeparator *hanoi3_base;
      SoTransform *hanoi3_transform;
      SoRotation *hanoi3_rotor;
      SoSeparator *hanoi3;


    //socle
    SoSeparator *socle;
    //objet
    SoSeparator *objet;
    SoTranslation *objet_translation;
    SoSeparator *objet_base;
    //grille
    SoSeparator *grille;
    SoTranslation *grille_translation;
    SoSeparator *grille_base;
    //base_mobile
    SoTransform *base_mobile_transform;
    SoSeparator *base_mobile_base;
    SoSeparator *base_mobile;
    SoMaterial  *base_mobile_mat;
    //parallelogramme_avant
    SoTransform *parallelogramme_avant_transform;
    SoSeparator *parallelogramme_avant_base;
    SoSeparator *parallelogramme_avant;
    //bitoniot_arriere
    SoTransform *bitoniot_arriere_transform;
    SoSeparator *bitoniot_arriere_base;
    SoSeparator *bitoniot_arriere;
    //cylindre_base
    SoTransform *cylindre_base_transform;
    SoSeparator *cylindre_base_base;
    SoSeparator *cylindre_base;
    //sortie_cylindre
    SoTransform *sortie_cylindre_transform;
    SoSeparator *sortie_cylindre_base;
    SoSeparator *sortie_cylindre;
    //parallelogramme_arriere
    SoTransform *parallelogramme_arriere_transform;
    SoSeparator *parallelogramme_arriere_base;
    SoSeparator *parallelogramme_arriere;
    //coude
    SoTransform *coude_transform;
    SoSeparator *coude_base;
    SoSeparator *coude;
    //avant_bras
    SoTransform *avant_bras_transform;
    SoSeparator *avant_bras_base;
    SoSeparator *avant_bras;
    //poignet_1
    SoSeparator *poignet_1_base;
    SoSeparator *poignet_1;
    SoTransform *poignet_1_transform;
    //poignet_2
    SoTransform *poignet_2_transform;
    SoSeparator *poignet_2_base;
    SoSeparator *poignet_2;

    //repere_r0
    SoSeparator *repere_r0_base;
    SoSeparator *repere_r0;
    //repere_r1
    SoTranslation *repere_r1_translation;
    SoSeparator *repere_r1_base;
    SoRotation *repere_r1_rotor;
    SoRotation *repere_r1_rotor2;
    SoSeparator *repere_r1;
    //repere_r2
    SoTranslation *repere_r2_translation;
    SoSeparator *repere_r2_base;
    SoRotation *repere_r2_rotor;
    SoRotation *repere_r2_rotor2;
    SoSeparator *repere_r2;
    //repere_r3
    SoTranslation *repere_r3_translation;
    SoSeparator *repere_r3_base;
    SoRotation *repere_r3_rotor;
    SoRotation *repere_r3_rotor2;
    SoSeparator *repere_r3;
    //repere_r4
    SoTranslation *repere_r4_translation;
    SoSeparator *repere_r4_base;
    SoRotation *repere_r4_rotor;
    SoRotation *repere_r4_rotor2;
    SoSeparator *repere_r4;
    //repere_r5
    SoTranslation *repere_r5_translation;
    SoSeparator *repere_r5_base;
    SoRotation *repere_r5_rotor;
    SoRotation *repere_r5_rotor2;
    SoSeparator *repere_r5;
    //repere_r6
    SoTranslation *repere_r6_translation;
    SoSeparator *repere_r6_base;
    SoRotation *repere_r6_rotor;
    SoRotation *repere_r6_rotor2;
    SoSeparator *repere_r6;

    SoEventCallback *eventCBNode;

    SoQtExaminerViewer* viewer;
    //SoQtRenderArea* viewer;

    int simulation_mode;
    bool gotoposition(double x, double y, double z);

    public slots:
      void openFileDialog();
      SoQtExaminerViewer getViewer();
};

#endif //__PROJET_H__
