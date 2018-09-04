#ifndef POSITION_H
#define POSITION_H

#include <tuple>
using std::tuple;


class Position{
public:
	Position(int x_position = 0, int y_position = 0); 
	tuple<int,int>getPosition()const;
	void setPosition(int x, int y);
	int getXPosition()const;
	int getYPosition()const;
	void setXPosition(int x_position);
	void setYPosition(int y_position);
	
private:
	int x_position_;
	int y_position_;
	
};
#endif // POSITION_H