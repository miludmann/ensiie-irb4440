/****************************************************************************
** Meta object code from reading C++ file 'projet.h'
**
** Created: Wed Mar 24 01:00:54 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "projet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'projet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IRB4400[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      45,    8,   26,    8, 0x0a,
      62,   57,    8,    8, 0x0a,
      81,   57,    8,    8, 0x0a,
     100,   57,    8,    8, 0x0a,
     119,    8,    8,    8, 0x0a,
     126,    8,    8,    8, 0x0a,
     140,    8,    8,    8, 0x0a,
     155,    8,    8,    8, 0x0a,
     171,    8,    8,    8, 0x0a,
     192,  186,    8,    8, 0x0a,
     214,  186,    8,    8, 0x0a,
     237,  186,    8,    8, 0x0a,
     254,  186,    8,    8, 0x0a,
     271,  186,    8,    8, 0x0a,
     288,  186,    8,    8, 0x0a,
     305,  186,    8,    8, 0x0a,
     322,  186,    8,    8, 0x0a,
     339,  186,    8,    8, 0x0a,
     362,  356,    8,    8, 0x0a,
     384,  356,    8,    8, 0x0a,
     410,  356,    8,    8, 0x0a,
     431,  356,    8,    8, 0x0a,
     451,  356,    8,    8, 0x0a,
     471,  356,    8,    8, 0x0a,
     537,  487,    8,    8, 0x0a,
     585,  487,    8,    8, 0x0a,
     646,    8,    8,    8, 0x0a,
     667,    8,    8,    8, 0x0a,
     715,  703,  687,    8, 0x0a,
     762,    8,    8,    8, 0x0a,
     783,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_IRB4400[] = {
    "IRB4400\0\0openFileDialog()\0SoQtExaminerViewer\0"
    "getViewer()\0text\0x_changed(QString)\0"
    "y_changed(QString)\0z_changed(QString)\0"
    "move()\0move_grille()\0reset_grille()\0"
    "reset_sliders()\0center_scene()\0state\0"
    "toggle_headlight(int)\0toggle_fil_de_fer(int)\0"
    "toggle_rep0(int)\0toggle_rep1(int)\0"
    "toggle_rep2(int)\0toggle_rep3(int)\0"
    "toggle_rep4(int)\0toggle_rep5(int)\0"
    "toggle_rep6(int)\0angle\0move_base_mobile(int)\0"
    "move_parallelogramme(int)\0"
    "move_avant_bras(int)\0move_poignet_1(int)\0"
    "move_poignet_2(int)\0move_coude(int)\0"
    "angle1,angle2,angle3,angle4,angle5,angle6,nb_iter\0"
    "repeat(float,float,float,float,float,float,int)\0"
    "repeat_from_current(float,float,float,float,float,float,int)\0"
    "repeat_control_mgd()\0toggle_toutCocher()\0"
    "QVector<double>\0x,y,z,a,b,c\0"
    "mgi(double,double,double,double,double,double)\0"
    "on_lancer_commande()\0default_mgi()\0"
};

const QMetaObject IRB4400::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_IRB4400,
      qt_meta_data_IRB4400, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &IRB4400::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *IRB4400::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *IRB4400::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IRB4400))
        return static_cast<void*>(const_cast< IRB4400*>(this));
    return QObject::qt_metacast(_clname);
}

int IRB4400::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: openFileDialog(); break;
        case 1: { SoQtExaminerViewer _r = getViewer();
            if (_a[0]) *reinterpret_cast< SoQtExaminerViewer*>(_a[0]) = _r; }  break;
        case 2: x_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: y_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: z_changed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: move(); break;
        case 6: move_grille(); break;
        case 7: reset_grille(); break;
        case 8: reset_sliders(); break;
        case 9: center_scene(); break;
        case 10: toggle_headlight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: toggle_fil_de_fer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: toggle_rep0((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: toggle_rep1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: toggle_rep2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: toggle_rep3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: toggle_rep4((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: toggle_rep5((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: toggle_rep6((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: move_base_mobile((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: move_parallelogramme((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: move_avant_bras((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: move_poignet_1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: move_poignet_2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: move_coude((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: repeat((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< float(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 26: repeat_from_current((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< float(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 27: repeat_control_mgd(); break;
        case 28: toggle_toutCocher(); break;
        case 29: { QVector<double> _r = mgi((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< QVector<double>*>(_a[0]) = _r; }  break;
        case 30: on_lancer_commande(); break;
        case 31: default_mgi(); break;
        default: ;
        }
        _id -= 32;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
