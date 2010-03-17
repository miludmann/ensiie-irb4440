#ifndef INTERFACE_H
#define INTERFACE_H

#include <qvariant.h>


#include <Qt3Support/Q3MimeSourceFactory>
#include <Q3ButtonGroup>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

class Ui_Interface
{
public:
    QTabWidget *tabWidget2;
    QWidget *tab;
    QLabel *textLabel2;
    QLabel *textLabel1_3;
    QLabel *textLabel1_2;
    QLineEdit *lineEdit3;
    QLabel *textLabel1;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QPushButton *pushButton1;
    Q3ButtonGroup *buttonGroup1;
    QRadioButton *radioButton3;
    QRadioButton *radioButton4;
    QLabel *textLabel1_4;
    QWidget *tab1;
    QLabel *textLabel1_5;
    QFrame *line1_2;
    QFrame *line1;
    QSlider *slider1;
    QLCDNumber *lCDNumber1;
    QCheckBox *checkBox1_2_2;
    QCheckBox *checkBox1;
    QPushButton *pushButton2;
    QWidget *TabPage;
    QPushButton *pushButton4;
    QWidget *TabPage1;
    QLabel *textLabel3;

    void setupUi(QDialog *Interface)
    {
    if (Interface->objectName().isEmpty())
        Interface->setObjectName(QString::fromUtf8("Interface"));
    Interface->resize(640, 188);
    Interface->setMinimumSize(QSize(640, 188));
    Interface->setMaximumSize(QSize(640, 188));
    tabWidget2 = new QTabWidget(Interface);
    tabWidget2->setObjectName(QString::fromUtf8("tabWidget2"));
    tabWidget2->setGeometry(QRect(0, 0, 640, 190));
    QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(4), static_cast<QSizePolicy::Policy>(4));
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(tabWidget2->sizePolicy().hasHeightForWidth());
    tabWidget2->setSizePolicy(sizePolicy);
    tabWidget2->setTabShape(QTabWidget::Rounded);
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    textLabel2 = new QLabel(tab);
    textLabel2->setObjectName(QString::fromUtf8("textLabel2"));
    textLabel2->setGeometry(QRect(10, 10, 220, 20));
    textLabel2->setWordWrap(false);
    textLabel1_3 = new QLabel(tab);
    textLabel1_3->setObjectName(QString::fromUtf8("textLabel1_3"));
    textLabel1_3->setGeometry(QRect(82, 97, 16, 30));
    textLabel1_3->setWordWrap(false);
    textLabel1_2 = new QLabel(tab);
    textLabel1_2->setObjectName(QString::fromUtf8("textLabel1_2"));
    textLabel1_2->setGeometry(QRect(82, 67, 16, 30));
    textLabel1_2->setWordWrap(false);
    lineEdit3 = new QLineEdit(tab);
    lineEdit3->setObjectName(QString::fromUtf8("lineEdit3"));
    lineEdit3->setGeometry(QRect(110, 100, 123, 22));
    textLabel1 = new QLabel(tab);
    textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
    textLabel1->setGeometry(QRect(82, 37, 16, 30));
    textLabel1->setWordWrap(false);
    lineEdit1 = new QLineEdit(tab);
    lineEdit1->setObjectName(QString::fromUtf8("lineEdit1"));
    lineEdit1->setGeometry(QRect(110, 40, 123, 22));
    lineEdit2 = new QLineEdit(tab);
    lineEdit2->setObjectName(QString::fromUtf8("lineEdit2"));
    lineEdit2->setGeometry(QRect(110, 70, 123, 22));
    pushButton1 = new QPushButton(tab);
    pushButton1->setObjectName(QString::fromUtf8("pushButton1"));
    pushButton1->setGeometry(QRect(530, 60, 90, 24));
    buttonGroup1 = new Q3ButtonGroup(tab);
    buttonGroup1->setObjectName(QString::fromUtf8("buttonGroup1"));
    buttonGroup1->setGeometry(QRect(260, 10, 250, 110));
    radioButton3 = new QRadioButton(buttonGroup1);
    radioButton3->setObjectName(QString::fromUtf8("radioButton3"));
    radioButton3->setGeometry(QRect(20, 30, 210, 20));
    radioButton3->setChecked(true);
    radioButton4 = new QRadioButton(buttonGroup1);
    radioButton4->setObjectName(QString::fromUtf8("radioButton4"));
    radioButton4->setGeometry(QRect(20, 70, 210, 20));
    textLabel1_4 = new QLabel(tab);
    textLabel1_4->setObjectName(QString::fromUtf8("textLabel1_4"));
    textLabel1_4->setGeometry(QRect(20, 130, 600, 20));
    textLabel1_4->setWordWrap(false);
    tabWidget2->addTab(tab, QString());
    tab1 = new QWidget();
    tab1->setObjectName(QString::fromUtf8("tab1"));
    textLabel1_5 = new QLabel(tab1);
    textLabel1_5->setObjectName(QString::fromUtf8("textLabel1_5"));
    textLabel1_5->setGeometry(QRect(250, 10, 170, 20));
    textLabel1_5->setWordWrap(false);
    line1_2 = new QFrame(tab1);
    line1_2->setObjectName(QString::fromUtf8("line1_2"));
    line1_2->setGeometry(QRect(220, -20, 20, 210));
    line1_2->setFrameShape(QFrame::VLine);
    line1_2->setFrameShadow(QFrame::Sunken);
    line1 = new QFrame(tab1);
    line1->setObjectName(QString::fromUtf8("line1"));
    line1->setGeometry(QRect(430, -30, 20, 200));
    line1->setFrameShape(QFrame::VLine);
    line1->setFrameShadow(QFrame::Sunken);
    slider1 = new QSlider(tab1);
    slider1->setObjectName(QString::fromUtf8("slider1"));
    slider1->setGeometry(QRect(280, 40, 30, 100));
    slider1->setValue(00);
    slider1->setOrientation(Qt::Vertical);
    lCDNumber1 = new QLCDNumber(tab1);
    lCDNumber1->setObjectName(QString::fromUtf8("lCDNumber1"));
    lCDNumber1->setGeometry(QRect(340, 70, 50, 30));
    checkBox1_2_2 = new QCheckBox(tab1);
    checkBox1_2_2->setObjectName(QString::fromUtf8("checkBox1_2_2"));
    checkBox1_2_2->setGeometry(QRect(20, 90, 190, 20));
    checkBox1_2_2->setChecked(true);
    checkBox1 = new QCheckBox(tab1);
    checkBox1->setObjectName(QString::fromUtf8("checkBox1"));
    checkBox1->setGeometry(QRect(20, 50, 91, 20));
    pushButton2 = new QPushButton(tab1);
    pushButton2->setObjectName(QString::fromUtf8("pushButton2"));
    pushButton2->setGeometry(QRect(480, 70, 120, 24));
    tabWidget2->addTab(tab1, QString());
    TabPage = new QWidget();
    TabPage->setObjectName(QString::fromUtf8("TabPage"));
    pushButton4 = new QPushButton(TabPage);
    pushButton4->setObjectName(QString::fromUtf8("pushButton4"));
    pushButton4->setGeometry(QRect(190, 60, 250, 24));
    tabWidget2->addTab(TabPage, QString());
    TabPage1 = new QWidget();
    TabPage1->setObjectName(QString::fromUtf8("TabPage1"));
    textLabel3 = new QLabel(TabPage1);
    textLabel3->setObjectName(QString::fromUtf8("textLabel3"));
    textLabel3->setGeometry(QRect(30, 20, 270, 100));
    textLabel3->setWordWrap(false);
    tabWidget2->addTab(TabPage1, QString());

    retranslateUi(Interface);

    QMetaObject::connectSlotsByName(Interface);
    } // setupUi

    void retranslateUi(QDialog *Interface)
    {
    Interface->setWindowTitle(QApplication::translate("Interface", "Console de contr\303\264le", 0, QApplication::UnicodeUTF8));
    textLabel2->setText(QApplication::translate("Interface", "Coordonn\303\251es de la destination :", 0, QApplication::UnicodeUTF8));
    textLabel1_3->setText(QApplication::translate("Interface", "Z:", 0, QApplication::UnicodeUTF8));
    textLabel1_2->setText(QApplication::translate("Interface", "Y:", 0, QApplication::UnicodeUTF8));
    textLabel1->setText(QApplication::translate("Interface", "X:", 0, QApplication::UnicodeUTF8));
    pushButton1->setText(QApplication::translate("Interface", "Go !", 0, QApplication::UnicodeUTF8));
    buttonGroup1->setTitle(QApplication::translate("Interface", "Mode de d\303\251placement", 0, QApplication::UnicodeUTF8));
    radioButton3->setText(QApplication::translate("Interface", "D\303\251placement instantan\303\251", 0, QApplication::UnicodeUTF8));
    radioButton4->setText(QApplication::translate("Interface", "D\303\251placement progressif", 0, QApplication::UnicodeUTF8));
    textLabel1_4->setText(QString());
    tabWidget2->setTabText(tabWidget2->indexOf(tab), QApplication::translate("Interface", "Commande du robot", 0, QApplication::UnicodeUTF8));
    textLabel1_5->setText(QApplication::translate("Interface", "Hauteur de la grille :", 0, QApplication::UnicodeUTF8));
    checkBox1_2_2->setText(QApplication::translate("Interface", "Projecteur de lumi\303\250re", 0, QApplication::UnicodeUTF8));
    checkBox1->setText(QApplication::translate("Interface", "Fil de fer", 0, QApplication::UnicodeUTF8));
    pushButton2->setText(QApplication::translate("Interface", "Centrer la sc\303\250ne", 0, QApplication::UnicodeUTF8));
    tabWidget2->setTabText(tabWidget2->indexOf(tab1), QApplication::translate("Interface", "Graphisme", 0, QApplication::UnicodeUTF8));
    pushButton4->setText(QApplication::translate("Interface", "Faire appara\303\256tre un objet", 0, QApplication::UnicodeUTF8));
    tabWidget2->setTabText(tabWidget2->indexOf(TabPage), QApplication::translate("Interface", "Mode simulation", 0, QApplication::UnicodeUTF8));
    textLabel3->setText(QApplication::translate("Interface", "Projet de robotique de Michael Ludmann\n& Guillaume Depoyant.\n"
"\n"
"Mars 2010.\n"
"\n"
"", 0, QApplication::UnicodeUTF8));
    tabWidget2->setTabText(tabWidget2->indexOf(TabPage1), QApplication::translate("Interface", "A propos", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Interface);
    } // retranslateUi

};

namespace Ui {
    class Interface: public Ui_Interface {};
} // namespace Ui

class Interface : public QDialog, public Ui::Interface
{
    Q_OBJECT

public:
    Interface(QWidget* parent = 0, const char* name = 0, bool modal = false, Qt::WindowFlags fl = 0);
    ~Interface();

protected slots:
    virtual void languageChange();

};

#endif // INTERFACE_H
