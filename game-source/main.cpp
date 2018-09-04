#include <iostream>
#include "GameEngine.h"
#include "Player.h"
#include "position.h"
//#include "Movement.h"
#include "Mover.h"
#include "Player.h"

#include <memory>


using namespace std;


int main(){
	
		GameEngine centipede;
		centipede.playGame();

//        Position position(10,20);
//        Mover mover(position);
//        
//        mover.getPosition().setPosition(100,200);
//        cout << mover.getPosition().getXPosition() << endl;
        
        
        
		return 0;
}