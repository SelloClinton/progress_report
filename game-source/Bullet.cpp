#include "Bullet.h"

Bullet::Bullet(shared_ptr<Mover> attribute):
		attribute_(attribute)
{
	attribute_->destroy();
}
		
shared_ptr<Mover> Bullet::attribute(){
        return attribute_;
}

