#include "mainWidget.h"
#include "projet.h"

#include <qvariant.h>
#include <math.h>
#include <Inventor/SbBasic.h>

#define SQUARE(x) ((x)*(x))
#define A2 0.200
#define A3 0.890
#define A4 0.150
#define R1 0.680
#define R4 0.880
#define R6 0.140

#define M_PI 3.14159265358979323846

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

    flag = false;
    angle23 = 82 + 62;

    a = 0.6933703916;
    b = 0.122805578;
    c = 0.8161759675;
    old2 = 82;

    left3D[0] = true;
    left3D[1] = false;
    left3D[2] = false;
    right3D[0] = false;
    right3D[1] = true;
    right3D[2] = true;

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
    slider_base_mobile->setValue(165);
    slider_parallelogramme->setValue(82);
    slider_coude->setValue(62);
    slider_avant_bras->setValue(200);
    slider_poignet_1->setValue(120);
    slider_poignet_2->setValue(400);
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
        iv->viewer->setAnaglyphStereoColorMasks(left3D, right3D);
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

void Interface::on_repeat_button_clicked()
{
    repeat_control_mgd();
}

void Interface::repeat(float angle1, float angle2, float angle3, float angle4, float angle5, float angle6, int nb_iter)
{
    for (double i=0; i<=nb_iter; i++) {
        slider_base_mobile->setValue(165-i*(165-angle1)/nb_iter);
        slider_base_mobile->repaint();
        slider_parallelogramme->setValue(82-i*(82-angle2)/nb_iter);
        slider_parallelogramme->repaint();
        slider_coude->setValue(62-i*(62-angle3)/nb_iter);
        slider_coude->repaint();
        slider_avant_bras->setValue(200-i*(200-angle4)/nb_iter);
        slider_avant_bras->repaint();
        slider_poignet_1->setValue(120-i*(120-angle5)/nb_iter);
        slider_poignet_1->repaint();
        slider_poignet_2->setValue(400-i*(400-angle6)/nb_iter);
        slider_poignet_2->repaint();
        iv->viewer->render();
        millisleep(20);
    }
}

void Interface::repeat_from_current(float angle1, float angle2, float angle3, float angle4, float angle5, float angle6, int nb_iter)
{
    double angle1_current = slider_base_mobile->value();
    double angle2_current = slider_parallelogramme->value();
    double angle3_current = slider_coude->value();
    double angle4_current = slider_avant_bras->value();
    double angle5_current = slider_poignet_1->value();
    double angle6_current = slider_poignet_2->value();

    for (double i=0; i<=nb_iter; i++) {
        slider_base_mobile->setValue(angle1_current-i*(angle1_current-angle1)/nb_iter);
        slider_base_mobile->repaint();
        slider_parallelogramme->setValue(angle2_current-i*(angle2_current-angle2)/nb_iter);
        slider_parallelogramme->repaint();
        slider_coude->setValue(angle3_current-i*(angle3_current-angle3)/nb_iter);
        slider_coude->repaint();
        slider_avant_bras->setValue(angle4_current-i*(angle4_current-angle4)/nb_iter);
        slider_avant_bras->repaint();
        slider_poignet_1->setValue(angle5_current-i*(angle5_current-angle5)/nb_iter);
        slider_poignet_1->repaint();
        slider_poignet_2->setValue(angle6_current-i*(angle6_current-angle6)/nb_iter);
        slider_poignet_2->repaint();
        iv->viewer->render();
        millisleep(20);
    }
}

void Interface::repeat_control_mgd()
{
    float angle1 = slider_base_mobile->value();
    float angle2 = slider_parallelogramme->value();
    float angle3 = slider_coude->value();
    float angle4 = slider_avant_bras->value();
    float angle5 = slider_poignet_1->value();
    float angle6 = slider_poignet_2->value();

    repeat(angle1, angle2, angle3, angle4, angle5, angle6, 50);
}


QVector<double> Interface::mgi(double px, double py, double pz, double zx_nnorme, double zy_nnorme, double zz_nnorme)
{
    //On norme le vecteur Z
    double zNorm = sqrt(SQUARE(zx_nnorme) + SQUARE(zy_nnorme) + SQUARE(zz_nnorme));
    double zx = zx_nnorme/zNorm;
    double zy = zy_nnorme/zNorm;
    double zz = zz_nnorme/zNorm;

    pz = pz - R1;

    //Vecteur X
    double xx = -zy;
    double xy = zx;
    double xz = 0;

    //Vecteur Y
    double yx = -zx * zz;
    double yy = -zy * zz;
    double yz = SQUARE(zx) + SQUARE(zy);

    double theta1, theta2, theta3, theta4, theta5, theta6;

    /*
    //Theta1
    double theta1 = atan2(py - zy * R6, px - zx * R6);
    double c1 = cos(theta1);
    double s1 = sin(theta1);

    //Theta2 et Theta3
    double alpha = (px - zx * R6)/c1 - A2;
    double beta = (py - zy * R6)/s1 - A2;
    double gamma = pz - zz * R6;

    double delta = 1/(2 * alpha)*(SQUARE(A3) - SQUARE(A4) - SQUARE(R4) - SQUARE(gamma) - SQUARE(alpha));
    double c23 = (-R4 * delta + A4 * sqrt(SQUARE(A4) + SQUARE(R4) - SQUARE(delta))) / (SQUARE(A4) + SQUARE(R4));
    double s23 = (A4 * delta + R4 * sqrt(SQUARE(A4) + SQUARE(R4) - SQUARE(delta))) / (SQUARE(A4) + SQUARE(R4));

    double c2 = (gamma - R4 * s23 - A4 * c23) * 1/A3;
    double s2 = (R4 * c23 - A4 * s23 - alpha) * 1/A3;
    double theta2 = atan2(s2, c2);

    double c3 = c23 * c2 + s23 * s2;
    double s3 = s23 * c2 - c23 * s2;
    double theta3 = atan2(s3, c3);

    //Theta4
    double lambda1 = xz * c1 / (yy * xz - yz * xy);
    double lambda2 = xz * s1 / (yx * zx - yz * xx);
    double lambda = lambda1 - lambda2;

    double mu1 = (xz * s1 * s23 + c23) / (yy * xz - yz * xy);
    double mu2 = (xz * c1 * s23 + c23) / (yx * xz - yz * xx);
    double mu = mu1 - mu2;

    double theta4 = atan(- lambda / mu);
    double c4 = cos(theta4);
    double s4 = sin(theta4);

    //Theta5
    double c5 = (s23 * zz + c23 * c4 * sqrt(SQUARE(c23) * SQUARE(c4) + SQUARE(s23) - SQUARE(zz))) / (SQUARE(c23) + SQUARE(c4));
    double s5 = (c23 * c4 * zz + s23 * sqrt(SQUARE(c23) * SQUARE(c4) + SQUARE(s23) - SQUARE(zz))) / (SQUARE(c23) + SQUARE(c4));
    double theta5 = atan2(s5, c5);

    //Theta6
    double c6 = (-yz * c23 * s4 + xz * sqrt(SQUARE(xz) + SQUARE(yz) - SQUARE(c23) * SQUARE(s4))) / (SQUARE(xz) + SQUARE(yz));
    double s6 = (-xz * c23 * s4 + yz * sqrt(SQUARE(xz) + SQUARE(yz) - SQUARE(c23) * SQUARE(s4))) / (SQUARE(xz) + SQUARE(yz));
    double theta6 = atan2(s6, c6);

*/

    //theta1
    double pwx = px - R6 * zx;
    double pwy = py - R6 * zy;
    double pwz = pz - R6 * zz;
    theta1 = atan2(pwy, pwx);

    //theta3
    double pwx1_tmp = sqrt(SQUARE(pwx) + SQUARE(pwy)) - A2;
    double pwz1_tmp = pwz;
    double b4 = sqrt(A4*A4 + R4*R4);
    double s3_tmp = (SQUARE(pwx1_tmp) + SQUARE(pwz1_tmp) - A3*A3 - SQUARE(b4)) / (2 * A3 * b4);
    double c3_tmp = sqrt(1 - SQUARE(s3_tmp));
    double theta3_tmp = atan2(s3_tmp, c3_tmp);
    theta3 = theta3_tmp - atan2(A4, R4);

    //theta2
    double c2 = ((A3 + b4 * s3_tmp) * pwz1_tmp + b4 * c3_tmp * pwx1_tmp) / (A3*A3 + SQUARE(b4) + 2 * A3 * b4 * s3_tmp);
    double s2 = (-(A3 + b4 * s3_tmp) * pwx1_tmp + b4 * c3_tmp * pwz1_tmp) / (A3 * A3 + SQUARE(b4) + 2 * A3 * b4 * s3_tmp);
    theta2 = atan2(s2, c2);

    //theta4, theta5 et theta6
    double c1 = cos(theta1);
    double s1 = sin(theta1);
    double c23 = cos(theta2 + theta3);
    double s23 = sin(theta2 + theta3);
    double r13 = -c1 * s23 * zx - s1 * s23 * zy + c23 * zz;

    double r33 = s1 * zx - c1 * zy;
    double r21 = -c1 * c23 * xx - s1 * c23 * xy - s23 * xz;
    double r22 = -c1 * c23 * yx - s1 * c23 * yy - s23 * yz;
    double r23 = -c1 * c23 * zx - s1 * c23 * zy - s23 * zz;

    theta4 = atan2(r33, r13);
    theta5 = atan2(sqrt(SQUARE(r13) + SQUARE(r33)), -r23);
    theta6 = atan2(-r22, r21);

    theta1 = theta1 * 180 / M_PI + 165;
    theta2 = -theta2 * 180 / M_PI + 82;
    theta3 = -theta3 * 180 / M_PI + 62;
    theta4 = theta4 * 180 / M_PI + 200;
    theta5 = -theta5 * 180 / M_PI + 120;
    theta6 = theta6 * 180 / M_PI + 400;

    char buffer[7777];

    if (isnan(theta1) || isnan(theta2) || isnan(theta3) || isnan(theta4) || isnan(theta5) || isnan(theta6))
    {
        sprintf(buffer,"Robot stoppe car (%f,%f,%f) est hors d'atteinte.\nt1=%f, t2=%f, t3=%f, t4=%f, t5=%f, t6=%f", px_wanted, py_wanted, pz_wanted, theta1, theta2, theta3, theta4, theta5, theta6);
        displayResult->setText(QString(buffer));
    } else {
        sprintf(buffer,"q1=%f, q2=%f,\nq3=%f, q4=%f,\nq5=%f, q6=%f", theta1, theta2, theta3, theta4, theta5, theta6);
        displayResult->setText(QString(buffer));
    }

    //Vecteur des angles résultats
    QVector<double> thetas(6);

    thetas[0] = theta1;
    thetas[1] = theta2;
    thetas[2] = theta3;
    thetas[3] = theta4;
    thetas[4] = theta5;
    thetas[5] = theta6;

    return thetas;
}

void Interface::on_default_mgi_clicked()
{
    spinX->setValue(1.22);
    spinY->setValue(0.00);
    spinZ->setValue(1.75);
    spinZx->setValue(1.00);
    spinZy->setValue(0.00);
    spinZz->setValue(0.00);
}

void Interface::on_lancer_commande_clicked()
{
    px_wanted = spinX->value();
    py_wanted = spinY->value();
    pz_wanted = spinZ->value();
    zx_wanted = spinZx->value();
    zy_wanted = spinZy->value();
    zz_wanted = spinZz->value();

    QVector<double> thetas = mgi(px_wanted, py_wanted, pz_wanted, zx_wanted, zy_wanted, zz_wanted);

    if(radioButton_11->isChecked())
    {
        repeat(thetas[0], thetas[1], thetas[2], thetas[3], thetas[4], thetas[5], 50);

    } else {
        if(radioButton_21->isChecked())
        {
            repeat_from_current(thetas[0], thetas[1], thetas[2], thetas[3], thetas[4], thetas[5], 50);
        } else {
            slider_base_mobile->setValue(thetas[0]);
            slider_parallelogramme->setValue(thetas[1]);
            slider_coude->setValue(thetas[2]);
            slider_avant_bras->setValue(thetas[3]);
            slider_poignet_1->setValue(thetas[4]);
            slider_poignet_2->setValue(thetas[5]);
        }
    }
}

void Interface::on_sliderX_valueChanged(int value)
{
    double X = ((double) value)/1000;
    spinX->setValue(X);
    on_lancer_commande_clicked();
}

void Interface::on_sliderY_valueChanged(int value)
{
    double Y = ((double) value)/1000;
    spinY->setValue(Y);
    on_lancer_commande_clicked();
}

void Interface::on_sliderZ_valueChanged(int value)
{
    double Z = ((double) value)/1000;
    spinZ->setValue(Z);
    on_lancer_commande_clicked();
}

void Interface::on_sliderZx_valueChanged(int value)
{
    double Zx = ((double) value);
    spinZx->setValue(Zx);
    on_lancer_commande_clicked();
}

void Interface::on_sliderZy_valueChanged(int value)
{
    double Zy = ((double) value);
    spinZy->setValue(Zy);
    on_lancer_commande_clicked();
}

void Interface::on_sliderZz_valueChanged(int value)
{
    double Zz = ((double) value);
    spinZz->setValue(Zz);
    on_lancer_commande_clicked();
}

QVector<double> Interface::mgd(double q1_, double q2_, double q3_, double q4_, double q5_, double q6_)
{
    //Application du modèle géométrique direct

    double q1 = (q1_-165) * M_PI / 180;
    double q2 = -(q2_-82) * M_PI / 180;
    double q3 = -(q3_-62) * M_PI / 180;
    double q4 = (q4_-200) * M_PI / 180;
    double q5 = -(q5_-120) * M_PI / 180;
    double q6 = (q6_-400) * M_PI / 180;

    double s1 = sin(q1);
    double c1 = cos(q1);
    double s2 = sin(q2);
    double c2 = cos(q2);
    //double s3 = sin(q3);
    //double c3 = cos(q3);
    double s4 = sin(q4);
    double c4 = cos(q4);
    double s5 = sin(q5);
    double c5 = cos(q5);
    double s6 = sin(q6);
    double c6 = cos(q6);

    double s23 = sin(q2 + q3);
    double c23 = cos(q2 + q3);

    double Xx = ((s1 * s4 - c1 * s23 * c4) * c5 - c1 *c23 * s5) * c6 + (c1 * s23 * s4 + s1 * c4) * s6;
    double Xy = ((-c1 * s4 - s1 * s23 * c4) * c5 - s1 *c23 * s5) * c6 + (s1 * s23 * s4 - c1 * c4) * s6;
    double Xz = (c23 * c4 * c5 - s23 * s5) * c6 - c23 * s4 * s6;

    double Yx = ((-s1 * s4 + c1 * c23 * c4) * c5 + c1 *c23 * s5) * s6 + (c1 * s23 * s4 + s1 * c4) * c6;
    double Yy = ((c1 * s4 + s1 * s23 * c4) * c5 + s1 *c23 * s5) * s6 + (s1 * s23 * s4 - c1 * c4) * c6;
    double Yz = (c23 * c4 * c5 - s23 * s5) * c6 - c23 * s4 * s6;

    double Zx = (-c1 * s23 * c4 + s1 * s4) * s5 + c1 * c23 * c5;
    double Zy = (-s1 * s23 * c4 - c1 * s4) * s5 + s1 * c23 * c5;
    double Zz = c23 * c4 * s5 + s23 * c5;

    double px = Zx * R6 + R4 * c1 * c23 - A4 * c1 * s23 - A3 * c1 * s2 + A2 * c1;
    double py = Zy * R6 + R4 * s1 * c23 - A4 * s1 * s23 - A3 * s1 * s2 + A2 * s1;
    double pz = Zz * R6 + R4 * s23 + A4 * c23 + A3 *c2 + R1;


    //Mise en forme des résultats retournés par la fonction mgd()
    QVector<double> MGD(12);

    MGD[0] = Xx;
    MGD[1] = Xy;
    MGD[2] = Xz;
    MGD[3] = Yx;
    MGD[4] = Yy;
    MGD[5] = Yz;
    MGD[6] = Zx;
    MGD[7] = Zy;
    MGD[8] = Zz;
    MGD[9] = px;
    MGD[10] = py;
    MGD[11] = pz;

    char buffer[7777];
    sprintf(buffer,"px=%f, py=%f, pz=%f, Xx=%f, Xy=%f, Xz=%f, Yx=%f, Yy=%f, Yz=%f, Zx=%f, Zy=%f, Zz=%f", px, py, pz, Xx, Xy, Xz, Yx, Yy, Yz, Zx, Zy, Zz);
    display_mgd->setText(QString(buffer));

    return MGD;
}

void Interface::mgd_sliders()
{
    double q1 = slider_base_mobile->value();
    double q2 = slider_parallelogramme->value();
    double q3 = slider_coude->value();
    double q4 = slider_avant_bras->value();
    double q5 = slider_poignet_1->value();
    double q6 = slider_poignet_2->value();

    mgd(q1, q2, q3, q4, q5, q6);
}

void Interface::on_slider_base_mobile_valueChanged(int angle)
{
    iv->base_mobile_transform->rotation.setValue(SbVec3f(0, 0, 1), (angle-165)*M_PI/180);
    mgd_sliders();
}

void Interface::on_slider_parallelogramme_valueChanged(int angle)
{
    float angle3 = slider_coude->value();
    float ang2, c2;

    if ( (angle3 == 0 && angle > old2)
        || (angle3 == 125 && angle < old2) )
    {
        slider_parallelogramme->setValue(old2);
    }
    else
    {
        if ( angle-old2 > angle3 )
        {
            slider_parallelogramme->setValue(old2+angle3);
        }
        else
        {
            if ( old2-angle + angle3 > 125 )
            {
                slider_parallelogramme->setValue(old2-(125-angle3));
            }
            else
            {
                if ( angle3 >= 0 && angle3 <= 125)
                {
                    c2 = sqrt(a*a+b*b+2*a*b*cos((((float) 180)+angle-82)/180*M_PI));
                    ang2 = acos((c2*c2+a*a-b*b)/(2*a*c2))*180/M_PI*(angle-82)/abs(angle-82);
                    old2 = angle;

                    flag = true;
                    iv->parallelogramme_avant_transform->rotation.setValue(SbVec3f(0, 1, 0), (angle-82)*M_PI/180);
                    slider_coude->setValue(angle23-angle);
                    //move_coude(angle3+82-angle);

                    iv->cylindre_base_transform->rotation.setValue(SbVec3f(0, 1, 0), ang2*M_PI/180);
                    iv->sortie_cylindre_transform->rotation.setValue(SbVec3f(0, 1, 0), (ang2+(82-angle))*M_PI/180);
                }
            }
        }
    }
    mgd_sliders();
}

void Interface::on_slider_coude_valueChanged(int angle)
{
    float angle2 = slider_parallelogramme->value();

    if ( angle+angle2 >= 62+82-20 )
    {
        iv->coude_transform->rotation.setValue(SbVec3f(0, 1, 0), (angle-62)*M_PI/180);
        iv->bitoniot_arriere_transform->rotation.setValue(SbVec3f(0, 1, 0), (angle-62)*M_PI/180);
        iv->parallelogramme_arriere_transform->rotation.setValue(SbVec3f(0, 1, 0), -(angle-62)*M_PI/180);

        if(!flag)
        {
            angle23 = angle + slider_parallelogramme->value();
        } else {
            flag = false;
        }
    }
    else
    {
        slider_coude->setValue(62+82-20-angle2);
    }
    mgd_sliders();
}

void Interface::on_slider_avant_bras_valueChanged(int angle)
{
    iv->avant_bras_transform->rotation.setValue(SbVec3f(1, 0, 0), (angle-200)*M_PI/180);
    mgd_sliders();
}

void Interface::on_slider_poignet_1_valueChanged(int angle)
{
    iv->poignet_1_transform->rotation.setValue(SbVec3f(0, 1, 0), (angle-120)*M_PI/180);
    mgd_sliders();
}

void Interface::on_slider_poignet_2_valueChanged(int angle)
{
    iv->poignet_2_transform->rotation.setValue(SbVec3f(1, 0, 0), (angle-400)*M_PI/180);
    mgd_sliders();
}
