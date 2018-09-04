#include "Segment.h"

Segment::Segment(shared_ptr<Mover> attribute):
		attribute_(attribute)
		{}
		
shared_ptr<Mover> Segment::getAttribute(){
        return attribute_;
}
