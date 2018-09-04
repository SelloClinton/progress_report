#ifndef BULLET_H
#define BULLET_H

#include "Mover.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;



class Bullet{
	
public:
		Bullet(shared_ptr<Mover> attribute);
		shared_ptr<Mover> getAttribute();
		bool isShot()const;
		void shoot();
		void destroyBullet();
		void updateBullet();
private:
		shared_ptr<Mover> attribute_;
		bool shot_;
};

#endif