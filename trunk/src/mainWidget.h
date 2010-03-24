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

protected slots:
    virtual void languageChange();

public slots:
    //void reset_sliders();



private slots:
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
};

#endif // MAINWIDGET_H
