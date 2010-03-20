#ifndef __PROJET_H__
#define __PROJET_H__

#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoTranslation.h>
#include <Inventor/nodes/SoRotation.h>
#include <Inventor/nodes/SoMaterial.h>
#include <Inventor/nodes/SoDirectionalLight.h>
#include <Inventor/nodes/SoPerspectiveCamera.h>

#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>

#include <qobject.h>

void millisleep( unsigned int milliseconds );

class IRB4400 : public QObject
{
  Q_OBJECT
  public :
    IRB4400(QWidget* parent);
    ~IRB4400();
    void openFile(QString s);
    void openMember(QString s, SoSeparator *new_separator, SoSeparator *root);

    //matiere
    SoMaterial *matiere;
    //root
    SoSeparator *separator;

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
    SoTranslation *base_mobile_translation;
    SoSeparator *base_mobile_base;
    SoRotation *base_mobile_rotor;
    SoSeparator *base_mobile;
    //parallelogramme_avant
    SoTranslation *parallelogramme_avant_translation;
    SoSeparator *parallelogramme_avant_base;
    SoRotation *parallelogramme_avant_rotor;
    SoRotation *parallelogramme_avant_init_rotor;
    SoSeparator *parallelogramme_avant;
    //bitoniot_arriere
    SoTranslation *bitoniot_arriere_translation;
    SoSeparator *bitoniot_arriere_base;
    SoRotation *bitoniot_arriere_rotor;
    SoRotation *bitoniot_arriere_init_rotor;
    SoSeparator *bitoniot_arriere;
    //cylindre_base
    SoTranslation *cylindre_base_translation;
    SoSeparator *cylindre_base_base;
    SoRotation *cylindre_base_rotor;
    SoSeparator *cylindre_base;
    //sortie_cylindre
    SoTranslation *sortie_cylindre_translation;
    SoSeparator *sortie_cylindre_base;
    SoRotation *sortie_cylindre_rotor;
    SoSeparator *sortie_cylindre;
    //parallelogramme_arriere
    SoTranslation *parallelogramme_arriere_translation;
    SoSeparator *parallelogramme_arriere_base;
    SoRotation *parallelogramme_arriere_rotor;
    SoRotation *parallelogramme_arriere_init_rotor;
    SoSeparator *parallelogramme_arriere;
    //coude
    SoTranslation *coude_translation;
    SoSeparator *coude_base;
    SoRotation *coude_rotor;
    SoSeparator *coude;
    //avant_bras
    SoTranslation *avant_bras_translation;
    SoSeparator *avant_bras_base;
    SoRotation *avant_bras_rotor;
    SoSeparator *avant_bras;
    //poignet_1
    SoTranslation *poignet_1_translation;
    SoSeparator *poignet_1_base;
    SoRotation *poignet_1_rotor;
    SoSeparator *poignet_1;
    //poignet_2
    SoTranslation *poignet_2_translation;
    SoSeparator *poignet_2_base;
    SoRotation *poignet_2_rotor;
    SoSeparator *poignet_2;

    //repere_r0
    SoTranslation *repere_r0_translation;
    SoSeparator *repere_r0_base;
    SoRotation *repere_r0_rotor;
    SoRotation *repere_r0_rotor2;
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

    SoQtExaminerViewer* viewer;
    //SoQtRenderArea* viewer;


    double last_good_x;
    double last_good_y;
    double last_good_z;
    double x_wanted;
    double x_initial;
    double y_wanted;
    double y_initial;
    double z_wanted;
    double z_initial;

    int mode;
    int simulation_mode;
    bool gotoposition(double x, double y, double z);

    public slots:
      void openFileDialog();
      SoQtExaminerViewer getViewer();
      void x_changed(const QString& text);
      void y_changed(const QString& text);
      void z_changed(const QString& text);
      void move();
      void move_grille(int val);
      void reset_grille();
      void center_scene();
      void toggle_headlight(int state);
      void toggle_fil_de_fer(int state);
      void toggle_moving_mode(int state);
      void toggle_moving_mode2(int state);
      void toggle_rep0(int state);
      void toggle_rep1(int state);
      void toggle_rep2(int state);
      void toggle_rep3(int state);
      void toggle_rep4(int state);
      void toggle_rep5(int state);
      void toggle_rep6(int state);
};

void move_progressif(double x_initial, double x_wanted, double y_initial, double y_wanted, double z_initial, double z_wanted, IRB4400 *ivv);
void move_progressif_objet(double x_initial, double x_wanted, double y_initial, double y_wanted, double z_initial, double z_wanted, IRB4400 *ivv);
void move_progressif_both(double x_initial, double x_wanted, double y_initial, double y_wanted, double z_initial, double z_wanted, IRB4400 *ivv);
void move_progressif_objet_only(double x_initial, double x_wanted, double y_initial, double y_wanted, double z_initial, double z_wanted, IRB4400 *ivv);

#endif //__PROJET_H__
