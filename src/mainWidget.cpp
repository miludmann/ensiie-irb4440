#include "mainWidget.h"
#include "projet.h"

#include <qvariant.h>

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
    if(checkBox_3->isChecked() ||
       checkBox_4->isChecked() ||
       checkBox_5->isChecked() ||
       checkBox_6->isChecked() ||
       checkBox_7->isChecked() ||
       checkBox_8->isChecked() ||
       checkBox_9->isChecked() )
    {
        checkBox_3->setChecked(false);
        checkBox_4->setChecked(false);
        checkBox_5->setChecked(false);
        checkBox_6->setChecked(false);
        checkBox_7->setChecked(false);
        checkBox_8->setChecked(false);
        checkBox_9->setChecked(false);
    } else {
        checkBox_3->setChecked(true);
        checkBox_4->setChecked(true);
        checkBox_5->setChecked(true);
        checkBox_6->setChecked(true);
        checkBox_7->setChecked(true);
        checkBox_8->setChecked(true);
        checkBox_9->setChecked(true);
    }
}




