#include "Player.h"

Player::Player(shared_ptr<Mover> attribute):
		attribute_(attribute)
		{}
		
shared_ptr<Mover> Player::getAttribute(){
        return attribute_;
}
//Position Player::getPosition()const{
//		return position_;
//}

