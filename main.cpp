#include "crud.h"
#include <QMessageBox>
#include <QtDebug>
#include <QApplication>
#include "connexion.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connexion c;
        bool connected=c.ouvrirconnexion();
        if(connected)
        {
        CRUD w;
        w.show();
        return a.exec();
        }
    return 0;
}
