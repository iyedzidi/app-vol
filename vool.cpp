#include "VOOL.h"
VOOL::VOOL()
{
nb_voyageurs=0;
refvol=0;
destination="";
}
VOOL::VOOL(int refvol,QString date,QString destination,int nb_voyageurs)
{
  this->nb_voyageurs=nb_voyageurs;
  this->refvol=refvol;
  this->date_vol=date;
  this->destination=destination;
}
int VOOL::get_reference(){return  refvol;}
QString VOOL::get_date(){return date_vol;}
QString VOOL::get_destination(){return destination;}
int VOOL::get_nb_voyageurs(){return  nb_voyageurs;}

bool VOOL::ajouter()
{
QSqlQuery query;
QString res= QString::number(nb_voyageurs);
QString res1= QString::number(refvol);
query.prepare("INSERT INTO vool (reference, destination,date_vol,nb_voyageurs) "
                    "VALUES (:refvol,:destination,:date,:nb_voyageurs)");

query.bindValue(":refvol", res1);
query.bindValue(":destination", destination);
query.bindValue(":nb_voyageurs", res);
query.bindValue(":date", date_vol);
return    query.exec();
}

QSqlQueryModel * VOOL::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from VOOL");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("destination"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_vol"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("nb_voyageurs"));
    return model;
}
bool VOOL::supprimer(int refvol_ch)
{
QSqlQuery query;

query.prepare("Delete from VOOL where reference = :refvol ");
query.bindValue(":refvol", refvol_ch);
return    query.exec();
}
bool VOOL::rech(int x){
    QSqlQuery query;
    query.prepare("select * from VOOL where REFERENCE = :reference;");
    query.bindValue(":reference", x);
    return query.exec();
}
bool VOOL::modifier(int a,QString b,QString c,int d){
    QSqlQuery query;
    QString yep=QString::number(a);
    query.prepare("UPDATE VOOL set destination=:dest ,date_vol=:date,nb_voyageurs=:nbv  where reference ='"+yep+"'");
    query.bindValue(":reference",a);
    query.bindValue(":dest", b);
    query.bindValue(":date", c);
    query.bindValue(":nbv", d);
    return query.exec();
}
QSqlQueryModel * VOOL::tri_ref_asc()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from VOOL order by reference ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("destination"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_vol"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("nb_voyageurs"));
    return model;
}
QSqlQueryModel * VOOL::tri_destination_asc()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from VOOL order by destination asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("destination"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_vol"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("nb_voyageurs"));
    return model;
}
QSqlQueryModel * VOOL::tri_nb_voyageurs_asc()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from VOOL order by nb_voyageurs asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("destination"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_vol"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("nb_voyageurs"));
    return model;
}
QSqlQueryModel * VOOL::tri_ref()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from VOOL order by reference desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("destination"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_vol"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("nb_voyageurs"));
    return model;
}
QSqlQueryModel * VOOL::tri_destination()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from VOOL order by destination desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("destination"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_vol"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("nb_voyageurs"));
    return model;
}
QSqlQueryModel * VOOL::tri_nb_voyageurs()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from VOOL order by nb_voyageurs desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("destination"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_vol"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("nb_voyageurs"));
    return model;
}
