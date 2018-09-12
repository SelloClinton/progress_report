#include "Bullet.h"

Bullet::Bullet(shared_ptr<Mover> attribute):
		attribute_(attribute)
{
	attribute_->destroy();
}
		
shared_ptr<Mover> Bullet::attribute(){
        return attribute_;
}

//bool Bullet::isShot()const{
//	
//		return shot_;
//}
//
//void Bullet::shoot(){
//		shot_ = true;
//}
//void Bullet::destroyBullet(){
//		shot_ = false;
//}
