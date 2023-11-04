//
// Created by rohid on 16.10.2023.
//
#include <iostream>
#include "BattleGround.h"
#include <random>

using namespace std;

BattleGround::BattleGround(unsigned short size, unsigned short shipCount) {
    this->size = size;
    this->grid = new FieldState *[this->size];
    for (int i = 0; i < this->size; ++i) {
        this->grid[i] = new FieldState[this->size];
        for (int j = 0; j < this->size; ++j) {
            this->grid[i][j] = FieldState::EMPTY;
        }
    }
    this->shipCount = shipCount;

    if (shipCount > size * size) {
        shipCount = size * size;
        this->shipCount = shipCount;
    } else {
        this->shipCount = shipCount;
    }

    this->hitCount = 0;
    this->missCount = 0;
    initShips();
}

BattleGround::~BattleGround() {
    cout << "Dekonstruktor" << endl;
    for (int i = 0; i < this->size; ++i) {
        delete[] this->grid[i]; //ganzes arr löschen -> delete[] nur ein teil -> delete also ist es free()
    }
    delete[] this->grid;

}

void BattleGround::printGrid(bool showShips) {
    cout << "****************************************" << endl;

    cout << "  ";
    for (int i = 0; i < this->size; ++i) {
        cout << i << ' ';
    }
    for (int i = 0; i < this->size; ++i) {
        cout << "\n";
        cout << i;
        for (int j = 0; j < this->size; ++j) {
            if (showShips) {
                cout << " ";
                cout << this->grid[i][j];
            } else if (this->grid[i][j] == FieldState::SHIP) {
                cout << " ";
                cout << "-";
            } else {
                cout << " ";
                cout << this->grid[i][j];
            }
        }
    }

    cout << "\n----------------------------------------" << endl;
    cout << "Ships hit: ";

    string shipsHit="-----";

    cout<<shipsHit<<endl;
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if (this->grid[i][j] == FieldState::SHIP) {
                shipsHit[i] = 'h';
            }
        }
    }

    cout<<shipsHit<<endl;

    this->hitCount = 0;
    this->missCount = 0;

    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if (this->grid[i][j] == FieldState::HIT) {
                this->hitCount++;
            } else if (this->grid[i][j] == FieldState::MISS) {
                this->missCount++;
            }
        }
    }

    cout << "Hits: " << this->hitCount << endl;
    cout << "Misses: " << this->missCount << endl;
    cout << "Total tries: " << this->hitCount + this->missCount << endl;
    cout << "****************************************" << endl;

}

void BattleGround::initShips() {
    random_device rd;
    default_random_engine gen(rd());
    uniform_int_distribution<unsigned short>
            distribution(0, this->size - 1);

    for (int i = 0; i < this->shipCount; i++) {
        unsigned short row = distribution(gen);
        unsigned short col = distribution(gen);
        if (this->grid[row][col] == FieldState::SHIP) {
            --i;
            continue;
        } else {
            this->grid[row][col] = FieldState::SHIP;
        }
    }
}


void BattleGround::printOwnGrid() {
    printGrid(true);
}

void BattleGround::printEnemyGrid() {
    printGrid(false);
}

FieldState BattleGround::hitAt(unsigned short x, unsigned short y) {

    if (x >= this->size) {
        x = this->size - 1;
    } else if (y >= this->size) {
        y = this->size - 1;
    }

    this->size = size;
    this->grid = grid;

    switch (this->grid[x][y]) {
        case FieldState::SHIP:
            this->grid[x][y] = FieldState::HIT;
            cout << "Ship destroyed\n" << endl;
            break;
        case FieldState::MISS:
            this->grid[x][y] = FieldState::MISS;
            cout << "Ship missed\n" << endl;
            break;
        case FieldState::HIT:
            this->grid[x][y] = FieldState::HIT;
            cout << "Ship missed\n" << endl;
            break;
        case FieldState::EMPTY:
            this->grid[x][y] = FieldState::MISS;
            cout << "Ship missed\n" << endl;
            break;
        default:
            this->grid[x][y] = this->grid[x][y];
            cout << "Invalid coordinates!\n" << endl;
            break;
    }

}

unsigned short BattleGround::nrOfShipsLeft() {
    int nrShips = 0;
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if (this->grid[i][j] == FieldState::SHIP) {
                nrShips++;

            }
        }
    }
    return nrShips;
}

