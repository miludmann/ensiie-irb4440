#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "ui_mainWidgetform.h"
#include <Inventor/Qt/viewers/SoQtExaminerViewer.h>

class Interface : public QTabWidget, public Ui::MainWidget
{
    Q_OBJECT

public:
    Interface(QWidget* parent = 0, const char* name = 0, Qt::WindowFlags fl = 0);
    ~Interface();
    SoQtExaminerViewer *viewer;
    SoNode *repere_r0Tmp;
    SoNode *repere_r1Tmp;
    SoNode *repere_r2Tmp;
    SoNode *repere_r3Tmp;
    SoNode *repere_r4Tmp;
    SoNode *repere_r5Tmp;
    SoNode *repere_r6Tmp;

    double px_wanted;
    double py_wanted;
    double pz_wanted;
    double zx_wanted;
    double zy_wanted;
    double zz_wanted;
    double last_good_px;
    double last_good_py;
    double last_good_pz;

    int angle23;
    bool flag;
    float a, b, c;
    float old2;

    SbBool left3D[3];
    SbBool right3D[3];

protected slots:
    virtual void languageChange();

public slots:
    void on_keyboard_mode_toggled(bool checked);
    void on_default_val_hanoi_clicked();
    void on_hanoi3_slider_valueChanged(int value);
    void on_hanoi2_slider_valueChanged(int value);
    void on_hanoi1_slider_valueChanged(int value);
    void on_slider_poignet_2_valueChanged(int value);
    void on_slider_poignet_1_valueChanged(int value);
    void on_slider_coude_valueChanged(int value);
    void on_slider_avant_bras_valueChanged(int value);
    void on_slider_parallelogramme_valueChanged(int value);
    void on_slider_base_mobile_valueChanged(int value);
    void on_sliderZz_valueChanged(int value);
    void on_sliderZy_valueChanged(int value);
    void on_sliderZx_valueChanged(int value);
    void on_sliderZ_valueChanged(int value);
    void on_sliderY_valueChanged(int value);
    void on_repeat_button_clicked();
    void on_lancer_commande_clicked();
    void on_default_mgi_clicked();
    void on_sliderX_valueChanged(int value);
    void on_display_mode_activated(int index);
    void on_set3D_toggled(bool checked);
    void on_headlight_toggled(bool checked);
    void on_center_scene_clicked();
    void on_move_grid_sliderMoved(int position);
    void on_repere0_toggled(bool checked);
    void on_repere1_toggled(bool checked);
    void on_repere2_toggled(bool checked);
    void on_repere3_toggled(bool checked);
    void on_repere4_toggled(bool checked);
    void on_repere5_toggled(bool checked);
    void on_repere6_toggled(bool checked);
    void on_reinit_grille_clicked();
    void on_toutCocher_clicked();
    void on_reset_sliders_clicked();
    void repeat(float angle1, float angle2, float angle3, float angle4, float angle5, float angle6, int nb_iter);
    void repeat_from_current(float angle1, float angle2, float angle3, float angle4, float angle5, float angle6, int nb_iter);
    void repeat_control_mgd();
    QVector<double> mgi(double x, double y, double z, double a, double b, double c);
    QVector<double> mgd(double q1, double q2, double q3, double q4, double q5, double q6);
    void mgd_sliders();
    void adjust_hanoi();
    void move_hanoi(int piece, int from, int to);
    void solve_hanoi();

private slots:
    void on_start_demo_clicked();
    void on_keyboard_mode_clicked();
    void on_keyboard_mode_stateChanged(int );
    void on_hanoi_button_clicked();
};

#endif // MAINWIDGET_H
