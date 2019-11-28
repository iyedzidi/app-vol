#include "crud.h"
#include "ui_crud.h"
#include "vool.h"
#include <QMessageBox>
#include "notification.h"
#include "smtp.h"
#include "statistique.h"
CRUD::CRUD(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CRUD)
{
    ui->setupUi(this);
    ui->tabproduit_2->setModel(tmpvol.afficher());
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
}

CRUD::~CRUD()
{
    delete ui;
}


void CRUD::on_ajouter_clicked()
{
    int nbv = ui->nbv_e->text().toInt();
    QString date= ui->date_vol_e->text();
    QString destination= ui->destination_e->text();
    int reference= ui->reference_e->text().toInt();
  VOOL p(reference,date,destination,nbv);
  bool test=p.ajouter();
  if(test)
{ui->tabproduit_2->setModel(tmpvol.afficher());//refresh
      QString okd="";
           notification ok;
           ok.notification_Ouverture(okd);
QMessageBox::information(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Etudiant ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

  }}

void CRUD::on_supprimer_clicked()
{
    int reference_ch = ui->reference_sup_e->text().toInt();
    bool test=tmpvol.supprimer(reference_ch);
    if(test)
    {ui->tabproduit_2->setModel(tmpvol.afficher());//refresh
        QString okd="";
             notification ok;
             ok.notification_supprimer(okd);
        QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("PRODUIT supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void CRUD::on_pushButton_2_clicked()
{

         QString destination= ui->destination_e_2->text();
         //QString date_exp= ui->date_exp_m->text();
         QString date= ui->date_vol_e_2->text();
         int ref= ui->reference_e_3->text().toInt();
        // int qt_stock= ui->quantite_m->text().toInt();
         int nbv= ui->nbv_e_2->text().toInt();
      /*   int refrayon=0;
         int qt_rayon=0;
         float prix = ui->prix_m->text().toFloat();
         float solde = ui->solde_m->text().toFloat(); */
           VOOL p;
            if(p.rech(ref)){
                bool test = p.modifier(ref,destination,date,nbv);
                if(test){
                    QString okd="";
                         notification ok;
                         ok.notification_modifier(okd);
                    ui->tabproduit_2->setModel(tmpvol.afficher());
                    //ui->comboBox_m->setModel(tmpproduit.Modelrefproduit());
                    QMessageBox::information(nullptr,QObject::tr("Produit modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
                }
            }

}
void CRUD::on_checkBox_clicked(bool checked)
{
    if(checked){etat=1;}
    else if(checked!=1){
        etat=0;}
}
void CRUD::on_radioButton_clicked(bool checked)
{
    if(checked)
        ui->tabproduit_2->setModel(tmpvol.afficher());
}

void CRUD::on_radioButton_2_clicked(bool checked)
{

    if(checked && (etat==1)){
        ui->tabproduit_2->setModel(tmpvol.tri_ref_asc());}
    else if(checked && (etat==0)){ui->tabproduit_2->setModel(tmpvol.tri_ref());}
}

void CRUD::on_radioButton_3_clicked(bool checked)
{

    if(checked && (etat==1)){
        ui->tabproduit_2->setModel(tmpvol.tri_destination_asc());}
    else if(checked && (etat==0)){ui->tabproduit_2->setModel(tmpvol.tri_destination_asc());}
}

void CRUD::on_radioButton_4_clicked(bool checked)
{
    if(checked && (etat==1)){
        ui->tabproduit_2->setModel(tmpvol.tri_nb_voyageurs());}
    else if(checked && (etat==0)){ui->tabproduit_2->setModel(tmpvol.tri_nb_voyageurs_asc());}
}

void CRUD::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void CRUD::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}


void CRUD::on_statbtn_clicked()
{
    statistique *a= new statistique();
    a->show();
}
