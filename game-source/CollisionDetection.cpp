#include "CollisionDetection.h"

CollisionDetection::CollisionDetection(float xPositionA,float yPositionA,const EntityID& objectA, float xPositionB, float yPositionB, const EntityID& objectB):
			x_position_A_(xPositionA)
			,y_position_A_(yPositionA)
			,object_A_(objectA)
			,x_position_B_(xPositionB)
			,y_position_B_(yPositionB)
			,object_B_(objectB)
{
	createBoxes();
}
	
bool CollisionDetection::collided(){
	
		auto d1_x = min_x_B_ - max_x_A_;
		auto d1_y = min_y_B_ - max_y_A_;
		
		auto d2_x = min_x_A_ - max_x_B_;
		auto d2_y = min_y_A_ - max_y_B_;
		
		if ((d1_x > 0)||(d1_y < 0))
			return false;
		if ((d2_x > 0)||(d2_y < 0))
			return false;
		return true;
    
}

void CollisionDetection::createBoxes(){
    
    auto box_A = make_shared<Box>();

	auto[minXA,minYA,maxXA,maxYA] = box_A->getBox(x_position_A_,y_position_A_,object_A_);
	
    min_x_A_ =	minXA;		
    min_y_A_ = 	minYA;		
    max_x_A_= 	maxXA;			
	max_y_A_= 	maxYA;				
	
	
    auto box_B = make_shared<Box>();

	auto[minXB,minYB,maxXB,maxYB] = box_B->getBox(x_position_B_,y_position_B_,object_B_);
	
    min_x_B_ = minXB;					
    min_y_B_ = minYB;					
    max_x_B_ = maxXB;				
	max_y_B_= maxYB;						
}