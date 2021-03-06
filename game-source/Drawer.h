#ifndef DRAWER_H_INCLUDED
#define DRAWER_H_INCLUDED

#include "Player.h"
#include "Centipede.h"
#include "Segment.h"
#include "Position.h"
#include "Display.h"
#include "DataBank.h"
#include "Bullet.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


#include <memory>
using std::shared_ptr;
using std::make_shared;
using std::unique_ptr;
using std::make_unique;


class Drawer{
	
public:
		Drawer(shared_ptr<sf::RenderWindow> window);
        void drawPlayer(shared_ptr<Player> player);
//      void drawCentipede(shared_ptr<Centipede> centipede);
//		void drawBullet(shared_ptr<Bullet> bullet);

private:
//		unique_ptr<DataBank> data_;
		shared_ptr<sf::RenderWindow> window_;
//		Sprites object_sprites_;
		void drawSegment(shared_ptr<Segment> segment);  
		
};

#endif // DRAWER_H_INCLUDED