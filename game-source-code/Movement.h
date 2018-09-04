#ifndef MOVEMENT_H
#define MOVEMENT_H


//enum class Direction{
//		LEFT,
//		RIGHT,
//		UP,
//		DOWN
//	};
	
	
 class Movement{
public:
			Movement();
			int move(Direction direction,int point, int max_border);
private:
			int speed_;
			int getSpeed()const;
};
#endif // POSITION_H