#include "interface2.h"

#include <qvariant.h>
/*
 *  Constructs a Interface as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  true to construct a modal dialog.
 */
TabWidget::TabWidget(QWidget* parent, const char* name, bool modal, Qt::WindowFlags fl)
    : QTabWidget(parent, name, fl)
{
    setupUi(this);

}

/*
 *  Destroys the object and frees any allocated resources
 */
TabWidget::~TabWidget()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void TabWidget::languageChange()
{
    retranslateUi(this);
}

