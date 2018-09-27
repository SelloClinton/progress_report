#include "Bullet.h"

Bullet::Bullet(shared_ptr<Mover> attribute):
		attribute_(attribute)
{
}
		
shared_ptr<Mover> Bullet::attribute(){
        return attribute_;
}

void Bullet::moveUp(){
        if(auto y_position = get<1>(attribute()->position()->getPosition()); y_position > Constants::BULLET_HEIGHT_)
            attribute()->move(Direction::UP);
        else
            attribute()->destroy();
}

