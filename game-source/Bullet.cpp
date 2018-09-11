#include "Bullet.h"

Bullet::Bullet(shared_ptr<Mover> attribute):
		attribute_(attribute)
		,shot_(false)
		{}
		
shared_ptr<Mover> Bullet::attribute(){
        return attribute_;
}

bool Bullet::isShot(){
	
		return shot_;
}

void Bullet::shoot(){
		shot_ = true;
}
void Bullet::destroyBullet(){
		shot_ = false;
}

//void Bullet::updateBullet(){
//		if(attribute_->getPosition().getYPosition() > 0)
//			attribute_->move(Direction::UP);
//		else
//			destroyBullet();
//	
//}