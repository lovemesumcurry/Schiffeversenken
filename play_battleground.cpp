#include <iostream>
#include "BattleGround.h"

using namespace std;

int main() {
    cout << "Play BattleGround" << std::endl;
    int x=0;
    int y=0;
    BattleGround game = BattleGround(5, 5);

   // game.printOwnGrid();
    game.printEnemyGrid();
    while(game.nrOfShipsLeft()>0){
        cout << "Geben Sie die Koardinaten fuers schiessen ein!\n";
        cin>>x >> y;

        game.hitAt(x,y);
        game.printEnemyGrid();

    }

    if(game.nrOfShipsLeft()==0){
        cout<<"Sie haben gewonnen!\n" <<endl;
    }

    return 0;
}
