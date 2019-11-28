#ifndef VOOL_H
#define VOOL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class VOOL
{public:
    VOOL();
    VOOL(int,QString,QString,int);
    int get_reference();
    QString get_date();
    QString get_destination();
    int get_nb_voyageurs();
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * tri_ref();
     QSqlQueryModel * tri_destination();
      QSqlQueryModel * tri_nb_voyageurs();
      QSqlQueryModel * tri_ref_asc();
       QSqlQueryModel * tri_destination_asc();
        QSqlQueryModel * tri_nb_voyageurs_asc();
    bool supprimer(int);
    bool modifier(int,QString,QString,int);
   bool rech(int x);
private:
    QString date_vol,destination;
    int nb_voyageurs,refvol;
};


#endif // VOOL_H
