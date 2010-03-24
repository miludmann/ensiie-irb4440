#include "mainWidget.h"

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
