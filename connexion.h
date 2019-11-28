#ifndef connexion_H
#define connexion_H
#include <QSqlDatabase>

class connexion
{
private:
    QSqlDatabase db;
public:
    connexion();
    bool ouvrirconnexion();
    void fermerconnexion();
};

#endif // connexion_H
