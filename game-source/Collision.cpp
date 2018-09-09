#include "Collision.h"

Collision::Collision(shared_ptr<Position>position_A, Object objectA, shared_ptr<Position>position_A, Object objectB):
            object_position_A_(position_A)
            ,object_A_(objectA)
           ,object_position_B_(position_B)
           ,object_B_(objectB)
           ,box_A(make_shared<Box>());
           ,box_B(make_shared<Box>())
//           ,min_x_A_(get<0>(box_A->getBox()))
{
    auto[x_position_A,y_position_A] = object_position_A->getPosition();
    min_x_A_ = get<0>(x_position_A,y_position_A,object_A_);
    min_y_A_ = get<1>(x_position_A,y_position_B,object_A_);
    max_x_A
    auto[min_x_A,min_y_A,max_x_A,max_y_A_] = createBoxes(x_position_A,y_position_A,object_A_); 
    auto[x_position_B,y_position_B] = position_B->getPosition();
    auto[min_x_B,min_y_B,max_x_B,max_y_B_] = createBoxes(x_position_B,y_position_B,objectB);
    
//    createBoxes();
}
            
bool Collision::collided(){

//    auto[x_position_A,y_position_A] = position_A->getPosition();
//    auto[min_x_A,min_y_A,max_x_A,max_y_A_] = createBoxes(x_position_A,y_position_A,objectA); 
//    auto[x_position_B,y_position_B] = position_B->getPosition();
//    auto[min_x_B,min_y_B,max_x_B,max_y_B_] = createBoxes(x_position_B,y_position_B,objectB);
    
}

void Collision::createBoxes(int x, int y, Object object){
    
    auto box = make_shared<Box>();
    auto[mix_x,min_y,max_x,max_y] = box->getBox(int x_position,int y_position,Object object);
}