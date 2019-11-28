#ifndef CRUD_H
#define CRUD_H

#include <QMainWindow>
#include "vool.h"
#include "smtp.h"
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class CRUD; }
QT_END_NAMESPACE

class CRUD : public QMainWindow
{
    Q_OBJECT

public:
    CRUD(QWidget *parent = nullptr);
    ~CRUD();

private slots:
    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_pushButton_2_clicked();

    void on_radioButton_clicked(bool checked);

    void on_radioButton_2_clicked(bool checked);

    void on_radioButton_3_clicked(bool checked);

    void on_radioButton_4_clicked(bool checked);

    void on_checkBox_clicked(bool checked);

    void sendMail();
        void mailSent(QString);


        void on_statbtn_clicked();

private:
    Ui::CRUD *ui;
    VOOL tmpvol;
    int etat;
};
#endif // CRUD_H
