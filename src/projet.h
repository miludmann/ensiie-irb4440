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
    SoSeparator *base_mobile_repere;
    SoRotation *base_mobile_rotor;
    SoSeparator *base_mobile;
    //parallelogramme_avant
    SoTranslation *parallelogramme_avant_translation;
    SoSeparator *parallelogramme_avant_base;
    SoSeparator *parallelogramme_avant_repere;
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
    SoSeparator *coude_repere;
    SoRotation *coude_rotor;
    SoSeparator *coude;
    //avant_bras
    SoTranslation *avant_bras_translation;
    SoSeparator *avant_bras_base;
    SoSeparator *avant_bras_repere;
    SoRotation *avant_bras_rotor;
    SoSeparator *avant_bras;
    //poignet_1
    SoTranslation *poignet_1_translation;
    SoSeparator *poignet_1_base;
    SoSeparator *poignet_1_repere;
    SoRotation *poignet_1_rotor;
    SoSeparator *poignet_1;
    //poignet_2
    SoTranslation *poignet_2_translation;
    SoSeparator *poignet_2_base;
    SoSeparator *poignet_2_repere;
    SoRotation *poignet_2_rotor;
    SoSeparator *poignet_2;



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
};

void move_progressif(double x_initial, double x_wanted, double y_initial, double y_wanted, double z_initial, double z_wanted, IRB4400 *ivv);
void move_progressif_objet(double x_initial, double x_wanted, double y_initial, double y_wanted, double z_initial, double z_wanted, IRB4400 *ivv);
void move_progressif_both(double x_initial, double x_wanted, double y_initial, double y_wanted, double z_initial, double z_wanted, IRB4400 *ivv);
void move_progressif_objet_only(double x_initial, double x_wanted, double y_initial, double y_wanted, double z_initial, double z_wanted, IRB4400 *ivv);

#endif //__PROJET_H__
