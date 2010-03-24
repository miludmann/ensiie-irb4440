#include "mainWidget.h"
#include "projet.h"

#include <qvariant.h>

extern IVLoader *iv;

/*
 *  Constructs a Interface as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  true to construct a modal dialog.
 */

Interface::Interface(QWidget* parent, const char* name, Qt::WindowFlags fl)
    : QTabWidget(parent, name, fl)
{
    setupUi(this);

}

/*
 *  Destroys the object and frees any allocated resources
 */
Interface::~Interface()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Interface::languageChange()
{
    retranslateUi(this);
}

void Interface::on_reset_sliders_clicked()
{
    horizontalSlider->setValue(165);
    horizontalSlider_2->setValue(82);
    horizontalSlider_3->setValue(62);
    horizontalSlider_4->setValue(200);
    horizontalSlider_5->setValue(120);
    horizontalSlider_6->setValue(400);
}

void Interface::on_toutCocher_clicked()
{
    if(repere0->isChecked() ||
       repere1->isChecked() ||
       repere2->isChecked() ||
       repere3->isChecked() ||
       repere4->isChecked() ||
       repere5->isChecked() ||
       repere6->isChecked() )
    {
        repere0->setChecked(false);
        repere1->setChecked(false);
        repere2->setChecked(false);
        repere3->setChecked(false);
        repere4->setChecked(false);
        repere5->setChecked(false);
        repere6->setChecked(false);
    } else {
        repere0->setChecked(true);
        repere1->setChecked(true);
        repere2->setChecked(true);
        repere3->setChecked(true);
        repere4->setChecked(true);
        repere5->setChecked(true);
        repere6->setChecked(true);
    }
}

void Interface::on_reinit_grille_clicked()
{
    iv->grille_translation->translation= SbVec3f(0, 0, 0);;
    move_grid->setValue(0);
}

void Interface::on_repere0_toggled(bool checked)
{
    if (checked)
    {
      iv->repere_r0_base->insertChild(repere_r0Tmp, 0);
      iv->viewer->render();
    }else{
      //suppression du repère affiché ("0" correspond au premier enfant du noeud, i.e. le repère ici)
      repere_r0Tmp = iv->repere_r0_base->getChild(0);
      iv->repere_r0_base->removeChild(0);
      iv->viewer->render();
    }
}
void Interface::on_repere1_toggled(bool checked)
{
    if (checked)
    {
      iv->repere_r1_base->insertChild(repere_r1Tmp, 1);
      iv->viewer->render();
    }else{
      //suppression du repère affiché ("1" correspond au premier enfant du noeud, i.e. le repère ici)
      repere_r1Tmp = iv->repere_r1_base->getChild(1);
      iv->repere_r1_base->removeChild(1);
      iv->viewer->render();
    }
}
void Interface::on_repere2_toggled(bool checked)
{
    if (checked)
    {
      iv->repere_r2_base->insertChild(repere_r2Tmp, 3);
      iv->viewer->render();
    }else{
      //suppression du repère affiché ("3" correspond au premier enfant du noeud, i.e. le repère ici)
      repere_r2Tmp = iv->repere_r2_base->getChild(3);
      iv->repere_r2_base->removeChild(3);
      iv->viewer->render();
    }
}
void Interface::on_repere3_toggled(bool checked)
{
    if (checked)
    {
      iv->repere_r3_base->insertChild(repere_r3Tmp, 3);
      iv->viewer->render();
    }else{
      //suppression du repère affiché ("3" correspond au premier enfant du noeud, i.e. le repère ici)
      repere_r3Tmp = iv->repere_r3_base->getChild(3);
      iv->repere_r3_base->removeChild(3);
      iv->viewer->render();
    }
}
void Interface::on_repere4_toggled(bool checked)
{
    if (checked)
    {
      iv->repere_r4_base->insertChild(repere_r4Tmp, 3);
      iv->viewer->render();
    }else{
      //suppression du repère affiché ("3" correspond au premier enfant du noeud, i.e. le repère ici)
      repere_r4Tmp = iv->repere_r4_base->getChild(3);
      iv->repere_r4_base->removeChild(3);
      iv->viewer->render();
    }
}
void Interface::on_repere5_toggled(bool checked)
{
    if (checked)
    {
      iv->repere_r5_base->insertChild(repere_r5Tmp, 3);
      iv->viewer->render();
    }else{
      //suppression du repère affiché ("3" correspond au premier enfant du noeud, i.e. le repère ici)
      repere_r5Tmp = iv->repere_r5_base->getChild(3);
      iv->repere_r5_base->removeChild(3);
      iv->viewer->render();
    }
}
void Interface::on_repere6_toggled(bool checked)
{
    if (checked)
    {
      iv->repere_r6_base->insertChild(repere_r6Tmp, 3);
      iv->viewer->render();
    }else{
      //suppression du repère affiché ("3" correspond au premier enfant du noeud, i.e. le repère ici)
      repere_r6Tmp = iv->repere_r6_base->getChild(3);
      iv->repere_r6_base->removeChild(3);
      iv->viewer->render();
    }
}

void Interface::on_move_grid_sliderMoved(int position)
{
    double position2 = move_grid->value();
    position2 = position2 / 1000;
    iv->grille_translation->translation= SbVec3f(0, 0, position2);
}

void Interface::on_center_scene_clicked()
{
    iv->viewer->viewAll();
}

void Interface::on_headlight_toggled(bool checked)
{
    if (checked)
    {
      iv->viewer->setHeadlight(true);
    }else{
      iv->viewer->setHeadlight(false);
    }
}

void Interface::on_set3D_toggled(bool checked)
{
    if (checked)
    {
        iv->viewer->setStereoType(SoQtViewer::STEREO_ANAGLYPH);

    } else {
        iv->viewer->setStereoType(SoQtViewer::STEREO_NONE);
    }
}

void Interface::on_display_mode_activated(int index)
{
    switch (index)
    {
    case 0 :
        iv->viewer->setDrawStyle(SoQtViewer::INTERACTIVE, SoQtViewer::VIEW_AS_IS);
        iv->viewer->setDrawStyle(SoQtViewer::STILL, SoQtViewer::VIEW_AS_IS);
        break;
    case 1:
        iv->viewer->setDrawStyle(SoQtViewer::INTERACTIVE, SoQtViewer::VIEW_LINE);
        iv->viewer->setDrawStyle(SoQtViewer::STILL, SoQtViewer::VIEW_LINE);
        break;
    case 2:
        iv->viewer->setDrawStyle(SoQtViewer::INTERACTIVE, SoQtViewer::VIEW_POINT);
        iv->viewer->setDrawStyle(SoQtViewer::STILL, SoQtViewer::VIEW_POINT);
        break;
    case 3:
        iv->viewer->setDrawStyle(SoQtViewer::INTERACTIVE, SoQtViewer::VIEW_BBOX);
        iv->viewer->setDrawStyle(SoQtViewer::STILL, SoQtViewer::VIEW_BBOX);
        break;
    case 4:
        iv->viewer->setDrawStyle(SoQtViewer::STILL, SoQtViewer::VIEW_AS_IS);
        break;
    }
}

void Interface::on_sliderX_valueChanged(int value)
{
    float X = value/1000;
    spinX->setValue(X);
}
