#ifndef ENTITY_H
#define ENTITY_H

#include <cmath>
#include <QObject>
#include <QString>
#include "c_spell.h"
#include "c_item.h"
#include "pq7_config.h"

class Entity : public QObject
{
    Q_OBJECT

public:
    explicit Entity(QObject *parent = 0);

    // traits (Voc=Vocation)
    QString Name, Race, Voc, Level;

    // stats
    QString STR, INT, WIS, DEX, CON, CHA, HPMax, MPMax;

    // experience
    QString XP;
    unsigned long long maxXP();


    // spells
    QList<c_Spell*> Spells;

    // equipment
    c_Item*         Weapon;
    c_Item*         Sheild;
    QList<c_Item*>  Armor;

    // used for buying new equipment
    c_Item*         Purchase;
    QString         purchType();
    void            setPurchNew(bool is_new);

    // inventory
    QList<c_Item*> Inventory;
    QList<int> Quantity;
    int Encumbrance();
    int maxEncumbrance();

    // Gold (ah, weightless gold)
    int Gold;

    // random methods - used in init
    QString nameRand();
    QString raceRand();
    QString vocRand();
    void incrLevel();

signals:
    void levelUp();

public slots:

    
private:

    // methods
    QString statRand(int basevalue, int offset);
    int fnFib(int value);
    bool isNewPurchase;

};

#endif // ENTITY_H
