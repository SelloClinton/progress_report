#include <iostream>
#include "GameEngine.h"
#include "Player.h"
#include "position.h"
#include "Constants.h"
#include "Mover.h"
#include "Player.h"

#include <memory>


using namespace std;


int main(){
	
		GameEngine centipede;
		centipede.playGame();
		
//	cout << Constants::DISPLAY_WIDTH << endl;
		
		return 0;
}