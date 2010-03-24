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

protected slots:
    virtual void languageChange();

public slots:
    //void reset_sliders();



private slots:
    void on_toutCocher_clicked();
    void on_reset_sliders_clicked();
};

#endif // MAINWIDGET_H
