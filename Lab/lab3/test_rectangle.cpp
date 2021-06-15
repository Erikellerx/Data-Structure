#include "Rectangle.h"
#include "Point2D.h"
#include <iostream>


int main()
{
	
	Rectangle r1 = Rectangle(Point2D(4.0,3.0), Point2D(17.0,9.0));

	Point2D p1 = Point2D(9.0, 3.5);
	Point2D p2 = Point2D(8.0, 10.0);

	Rectangle r2 = Rectangle(Point2D(0,0), Point2D(10,10));

	Point2D p3 = Point2D(1,1);
	Point2D p4 = Point2D(20,20);

	Point2D p5 = Point2D(5,5);

	print_rectangle(r1);
	print_rectangle(r2);


	if (r1.add_point(p5))
	{
		std::cout<<"p5 added"<<std::endl;
	}
	else{
		std::cout<<"Cannot add p5"<<std::endl;
	}


	r1.add_point(p1);
	r1.add_point(p2);

	r2.add_point(p3);
	r2.add_point(p4);


	
	std::vector<Point2D> points;
	points = points_in_both(r1,r2);
	for (int i = 0; i < points.size(); ++i)
	{
		std::cout<<points[i].x()<<" "<<points[i].y()<<std::endl;
	}


	return 0;
}