#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
notification::notification()
{
num=0;
}

void notification::notification_modifier(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/Iyed Zidi/Desktop/Image1.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","Un vol a été modifié !",QSystemTrayIcon::Information,15000);
}

void notification::notification_supprimer(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/Iyed Zidi/Desktop/Image1.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","Un vol a été suprimé !",QSystemTrayIcon::Information,15000);
//num++;
}


void notification::notification_Ouverture(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/Iyed Zidi/Desktop/Image1.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("Gestion d'agence de voyage","Nouvelle vol ajoute",QSystemTrayIcon::Information,15000);
//num++;
}
