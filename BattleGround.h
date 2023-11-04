//
// Created by rohid on 16.10.2023.
//

#ifndef SCHIFFEVERSENKEN_BATTLEGROUND_H
#define SCHIFFEVERSENKEN_BATTLEGROUND_H

enum FieldState : char {
    EMPTY = '-',
    SHIP = 'S',
    HIT = 'h',
    MISS = 'm',
};

class BattleGround {
private:
    unsigned short size;
    FieldState **grid;
    unsigned short shipCount;
    unsigned short hitCount;
    unsigned short missCount;

    void printGrid(bool showShips);

    void initShips();

public:
    BattleGround(unsigned short size, unsigned short shipCount);

    ~BattleGround();

    void printOwnGrid();

    void printEnemyGrid();

    FieldState hitAt(unsigned short x, unsigned short y);

    unsigned short nrOfShipsLeft();

};


#endif //SCHIFFEVERSENKEN_BATTLEGROUND_H
