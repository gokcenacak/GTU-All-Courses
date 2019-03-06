//source1.cpp created by Gökçe Nur Erer 
//CSE 241 Object Oriented Programming HW #1
//This file includes the function implementations of the functions that are usedin 171044079_main.cpp 

#include <iostream>
#include <fstream> 
#include <cmath>
#include "source1.h"
using namespace std;


//main_frame: Opens the svg file and draws a blank background
void main_frame(double con_main_width, double con_main_height,ofstream& outputStream){
	outputStream.open("output.svg");
	outputStream << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << con_main_width << "\" height=\"" << con_main_height << "\">";
}
//main_container: Takes a shape value and draws the main container to the svg file
void main_container (Shape s, double con_main_height, double con_main_width, double con_main_radius, double con_main_tri_side,ofstream& outputStream){
	if(s==Shape::Rectangle){
		outputStream  << "<rect width=\"100%\" height=\"100%\" fill=\"red\"/>";
	}
	else if(s==Shape::Circle){
		outputStream  << "<circle cx=\"" << con_main_width/2 << "\" cy=\""<< con_main_height/2 <<"\" r=\"" << con_main_radius << "\" fill=\"red\"/>";

	}
	else if(s==Shape::Triangle){
		outputStream << "<polygon points=\"" << con_main_width/2 << ",0 " << con_main_width << "," << con_main_height << " 0," << con_main_height << "\" fill=\"red\"/>";
	}
	
}
//get_attribute: Gets a shape and decides the values of both main frame's and main container's widths and heights
void get_attribute(Shape s,double& width, double& height , double& tri_side, double& radius){
	if(s==Shape::Rectangle){
		cout << "Please enter width:";
		cin >> width;
		
		cout << "Please enter height:";
		cin >> height;

		radius=0;
		tri_side=0;
	}
	else if(s==Shape::Circle){
		cout << "Please enter the radius for the circle:";
		cin >> radius;
		width=radius*2;
		height=radius*2;
		tri_side=0;
		
	}
	
	else if(s==Shape::Triangle){
		cout <<"Please enter a side of the triangle:";
		cin >> tri_side;
		width=tri_side;
		height=((tri_side)/2)*sqrt(3);
		radius=0;
	}
}
//shape_selection: Decides the shape and returns it by the character entered in
Shape shape_selection(char c){
	Shape s;
		if(c=='R' || c=='r'){
			s=Shape::Rectangle;
		}
		else if(c=='C' || c=='c'){
			s=Shape::Circle;
		}
		else if(c=='T' || c=='t'){
			s=Shape::Triangle;
		}	
	return s;	
}
//circleInRectangle: Calculates the amount of circles that can be fitted in a rectangle
void circleInRectangle(double main_c_width,double main_c_height,double small_shape_radius,ofstream& outputStream){
	int x_circle_count,y_circle_count,total_circle_count;
	double area;

	x_circle_count=(int)(main_c_width/(2*small_shape_radius));
	y_circle_count=(int)(main_c_height/(2*small_shape_radius));
	total_circle_count=x_circle_count*y_circle_count;
	
	
	for(int i=small_shape_radius;i<=main_c_height-small_shape_radius;i+=2*small_shape_radius){
		for(int j=small_shape_radius;j<=main_c_width-small_shape_radius;j+=2*small_shape_radius){
			outputStream  << "<circle cx=\"" << j << "\" cy=\""<< i <<"\" r=\"" << small_shape_radius << "\" fill=\"pink\" stroke=\"black\" stroke-width=\"0.5\"/>";
		}
	}
	area=(main_c_height*main_c_width)-(total_circle_count*pow(small_shape_radius,2)*M_PI);
	cout << "I can fit at most " << total_circle_count << " small shapes into the main container. The empty area (red) in container is " << area << "."<< endl;
}
//triangleInRectangle: Calculates the amount of triangles that can be fitted in a rectangle
void triangleInRectangle(double main_c_width,double main_c_height,double small_shape_triside,ofstream& outputStream){
	int x_tri_count,y_tri_count,total_tri_count;
	double area,small_shape_height;

	double x1,y1,x2,y2,x3,y3;
	small_shape_height=(small_shape_triside/2)*sqrt(3);

	x_tri_count=((main_c_width/small_shape_triside)*2)-1;
	y_tri_count=(main_c_height/(small_shape_height));
	
	total_tri_count=x_tri_count*y_tri_count;
	area=(main_c_width*main_c_height)-(total_tri_count*(((pow(small_shape_triside,2))*sqrt(3))/4));
	cout << "I can fit at most " << total_tri_count << " small shapes into the main container. The empty area (red) in container is " << area << "."<< endl;

	for(int i=0;i<y_tri_count;++i){
		for(int j=0;j<x_tri_count;++j){
			
			x1=(small_shape_triside/2)+(j*small_shape_triside/2);
			x2=(small_shape_triside/2)*j;
			x3=(small_shape_triside)+j*(small_shape_triside/2);

				if((j%2==0 && i%2==0) || (j%2!=0 && i%2!=0)){
					y1=(small_shape_height)*i;
					y2=(small_shape_height)+(small_shape_height)*i;
					y3=y2;
				}
				else{
					y1=(small_shape_height)*i+small_shape_height;
					y2=(small_shape_height)*i;
					y3=y2;
				}
				outputStream << "<polygon points=\"" << x1 << "," << y1 << " " << x2 << "," << y2 << " " << x3 << "," << y3 << "\" fill=\"pink\" stroke=\"black\" stroke-width=\"0.5\" /> \n";

		}
	}
	
}
//rectangleInRectangle: Calculates the rectangles that can be fitted in a rectangle
void rectangleInRectangle(double main_c_width,double main_c_height,double small_shape_width,double small_shape_height,ofstream& outputStream){
	int x_rect_count,y_rect_count,total_rect_count,temp;
	double area;
	if(((main_c_width/small_shape_width)*(int)(main_c_height/small_shape_height))>((main_c_width/small_shape_height)*(int)(main_c_height/small_shape_width))){
		x_rect_count=(int)(main_c_width/small_shape_width);
		y_rect_count=(int)(main_c_height/small_shape_height);
	
	}
	else{
		x_rect_count=(int)(main_c_width/small_shape_height);
		y_rect_count=(int)(main_c_height/small_shape_width);
		temp=small_shape_height;
		small_shape_height=small_shape_width;
		small_shape_width=temp;
	}
	total_rect_count=x_rect_count*y_rect_count;
	area=(main_c_width*main_c_height)-(total_rect_count*(small_shape_height*small_shape_width));
	for(int i=0;i<small_shape_height*y_rect_count;i+=small_shape_height){
		for(int j=0;j<small_shape_width*x_rect_count;j+=small_shape_width){
			outputStream  << "<rect x=\"" << j << "\" y=\""<< i <<"\" width=\"" << small_shape_width << "\" height=\"" << small_shape_height << "\" fill=\"pink\" stroke-width=\"0.5\" stroke=\"black\"/>";
		}
	}
	cout << "I can fit at most " << total_rect_count << " small shapes into the main container. The empty area (red) in container is "<<  area << "." <<endl;
}

//rectangleInCircle: Calculates the rectangles that can be fitted in a circle. Used the idea to fill up the smoothest biggest shape (which is a square) in the circle with rectangles.
void rectangleInCircle(double main_c_radius, double small_shape_width, double small_shape_height, ofstream& outputStream){
	double s_x1,s_y1,x1,y1,area,temp;
	int rect_count=0;
	if(small_shape_height<small_shape_width){
		temp=small_shape_width;
		small_shape_width=small_shape_height;
		small_shape_height=temp;
	}
	s_x1=main_c_radius-main_c_radius/sqrt(2);
	s_y1=main_c_radius-main_c_radius/sqrt(2);

	for(int i=0; s_y1<main_c_radius+main_c_radius/sqrt(2)-small_shape_height ;++i){
		x1=s_x1;
		y1=s_y1;

		for(int j=0; x1<main_c_radius+main_c_radius/sqrt(2)-small_shape_width;++j){

			outputStream  << "<rect x=\"" << x1 << "\" y=\""<< y1 <<"\" width=\"" << small_shape_width << "\" height=\"" << small_shape_height << "\" fill=\"pink\" stroke-width=\"0.5\" stroke=\"black\"/>";
			rect_count++;
			x1+=small_shape_width;
			
		}
		
		s_y1+=small_shape_height;
	}
	area=pow(main_c_radius,2)*M_PI-rect_count*small_shape_width*small_shape_height;
	cout << "I can fit at most " << rect_count << " small shapes into the main container. The empty area (red) in container is "<<  area << "." <<endl;
}
//triangleInCircle: Calculates the triangles that can be fitted in a circle. Used the idea to fill in the biggest smooth shape (which is a square) in the circle with triangles.
void triangleInCircle(double main_c_radius, double small_shape_triside, ofstream &outputStream){
	double s_x1,s_x2,s_x3,area,small_shape_height,x1,x2,x3,y1,y2,y3;
	int tri_count=0,x_tri_count,y_tri_count;
	x_tri_count=((main_c_radius*sqrt(2))/small_shape_triside)*2-1;

	small_shape_height=small_shape_triside*sqrt(3)/2;
	y_tri_count=(main_c_radius*sqrt(2))/small_shape_height;
	s_x1=main_c_radius-main_c_radius/sqrt(2)+small_shape_triside/2;
	s_x2=main_c_radius-main_c_radius/sqrt(2);
	s_x3=main_c_radius-main_c_radius/sqrt(2)+small_shape_triside;


	for(int i = 0; i< y_tri_count ; ++i){
		x1=s_x1;
		x2=s_x2;
		x3=s_x3;	
		for(int j=0 ; j<x_tri_count;++j){
				
			if(((j%2==0) && (i%2==0)) || ((j%2!=0) && (i%2!=0))) {
				y1=main_c_radius-main_c_radius/sqrt(2)+(small_shape_height)*i;
				y2=main_c_radius-main_c_radius/sqrt(2)+(small_shape_height)+(small_shape_height)*i;
				y3=y2;
			}
			else{
				y1=main_c_radius-main_c_radius/sqrt(2)+(small_shape_height)*i+small_shape_height;
				y2=main_c_radius-main_c_radius/sqrt(2)+(small_shape_height)*i;
				y3=y2;
			}
			outputStream << "<polygon points=\"" << x1 << "," << y1 << " " << x2 << "," << y2 << " " << x3 << "," << y3 << "\" fill=\"pink\" stroke=\"black\" stroke-width=\"0.5\" /> \n";
			tri_count++;			
			x1+=small_shape_triside/2;
			x2+=small_shape_triside/2;
			x3+=small_shape_triside/2;
		}
		
	}
	area=pow(main_c_radius,2)*M_PI-tri_count*(pow(small_shape_triside,2)*sqrt(3)/4);
	cout << "I can fit at most " << tri_count << " small shapes into the main container. The empty area (red) in container is "<<  area << "." <<endl;
	
}

//Calculates the amount of circles that can be fitted in a circle. To fill the circular area, used the idea to fill the biggest smooth shape which is a square. 
void circleInCircle(double main_c_radius, double small_shape_radius, ofstream &outputStream){
	double s_x1,s_y1,x1,y1,area;
	int circle_count=0;

	s_x1=main_c_radius-main_c_radius/sqrt(2)+small_shape_radius;
	s_y1=main_c_radius-main_c_radius/sqrt(2)+small_shape_radius;

	for(int i=0; s_y1<main_c_radius+main_c_radius/sqrt(2)-small_shape_radius ;++i){
		x1=s_x1;
		y1=s_y1;

		for(int j=0; x1<main_c_radius+main_c_radius/sqrt(2)-small_shape_radius ;++j){

			outputStream  << "<circle cx=\"" << x1 << "\" cy=\""<< y1 <<"\" r=\"" << small_shape_radius << "\" fill=\"pink\" stroke=\"black\" stroke-width=\"0.5\"/> \n";
			circle_count++;	
			x1+=2*small_shape_radius;
			
		}
		s_y1+=2*small_shape_radius;
	}
	area=pow(main_c_radius,2)*M_PI-(pow(small_shape_radius,2)*M_PI)*circle_count;
	cout << "I can fit at most " << circle_count << " small shapes into the main container. The empty area (red) in container is "<<  area << "." <<endl;

}
//Calculates the amount of rectangles that can be fitted in a triangle. Works for few cases.
void rectangleInTriangle(double main_c_triside, double small_shape_width, double small_shape_height, ofstream &outputStream){
	double s_x1,s_y1,x1,y1,area,temp;
	int total_rect=0;
	if(small_shape_height<small_shape_width){
		temp=small_shape_width;
		small_shape_width=small_shape_height;
		small_shape_height=temp;
	}

	s_x1=main_c_triside/2-small_shape_width/2;
	s_y1=small_shape_height/3;

	for(int i=0;s_y1<((main_c_triside/2*sqrt(3))-small_shape_height)  ;++i){
		x1=s_x1;
		y1=s_y1;
		for(int j=0;x1<main_c_triside/2+small_shape_width/2*(2*i+1) && s_x1>=main_c_triside/2-small_shape_width/2*(2*i+1) ;++j){

			outputStream  << "<rect x=\"" << x1 << "\" y=\""<< y1 <<"\" width=\"" << small_shape_width << "\" height=\"" << small_shape_height << "\" fill=\"pink\" stroke-width=\"0.5\" stroke=\"black\"/> \n";
			total_rect++;
			x1+=small_shape_width;
		}
		s_x1-=small_shape_width;
		s_y1+=small_shape_height;
	}
	area=(pow(main_c_triside,2)*sqrt(3)/4)-total_rect*small_shape_width*small_shape_height;
	cout << "I can fit at most " << total_rect << " small shapes into the main container. The empty area (red) in container is "<<  area << "." <<endl;
}
//Calculates the amount of circles that can be fitted in a triangle.
void circleInTriangle(double main_c_triside,double small_shape_radius,ofstream& outputStream){
	double s_x1,s_y1,x1,y1,area;
	int total_circle=0,base_circle_count;

		s_x1=(main_c_triside/2);
		s_y1=2*small_shape_radius;

		for(int i=0;(s_y1<=main_c_triside/2*sqrt(3)-small_shape_radius);++i){	
			x1=s_x1;
			for(int j=0;j<i+1;++j){

				y1=s_y1;
				outputStream  << "<circle cx=\"" << x1 << "\" cy=\""<< y1 <<"\" r=\"" << small_shape_radius << "\" fill=\"pink\" stroke=\"black\" stroke-width=\"0.5\"/> \n";
				total_circle++;
				
				x1+=2*small_shape_radius;
			}
			s_x1-=small_shape_radius;
			s_y1+=sqrt(3)*(small_shape_radius);
		}
		area=(pow(main_c_triside,2)*sqrt(3)/4)-total_circle*pow(small_shape_radius,2)*M_PI;
		cout << "I can fit at most " << total_circle << " small shapes into the main container. The empty area (red) in container is "<<  area << "." <<endl;
}
//triangleInTriangle: Calculates the amount of triangles that can be fitted in a triangle.
void triangleInTriangle(double main_c_triside,double small_shape_triside,ofstream& outputStream){
	int total_tri_count,base_count;
	double x1,y1,x2,y2,x3,y3,s_x1,s_x2,s_x3,s_y1,s_y2,s_y3,area;

	base_count=(int)(main_c_triside/small_shape_triside);
	total_tri_count=0;

	s_x1=main_c_triside/2;
	s_y1=0;
	
	s_x2=main_c_triside/2-small_shape_triside/2;
	s_y2=small_shape_triside/2*sqrt(3);

	s_x3=main_c_triside/2+small_shape_triside/2;
	s_y3=s_y2;
	
	for(int i=0;i<base_count;++i){
		x1=s_x1;

		x2=s_x2;

		x3=s_x3;

			for(int j=0;j<2*i+1;++j){
				if(j%2==0){
					y1=i*small_shape_triside/2*sqrt(3);
					y2=(i*small_shape_triside/2*sqrt(3))+small_shape_triside/2*sqrt(3);
					y3=y2;
				}
				else{
					y1=(i*small_shape_triside/2*sqrt(3))+small_shape_triside/2*sqrt(3);
					y2=i*small_shape_triside/2*sqrt(3);
					y3=y2;
				}
				outputStream << "<polygon points=\"" << x1 << "," << y1 << " " << x2 << "," << y2 << " " << x3 << "," << y3 << "\" fill=\"pink\" stroke=\"black\" stroke-width=\"0.5\" /> \n";
				total_tri_count++;
				x1+=small_shape_triside/2;
				x2+=small_shape_triside/2;
				x3+=small_shape_triside/2;
				
				
			}
		s_x1-=small_shape_triside/2;
		s_x2-=small_shape_triside/2;
		s_x3-=small_shape_triside/2;
		
			
	}
	if((int)main_c_triside%(int)small_shape_triside==0){
		area=0;
	}
	else
		area=(pow(main_c_triside,2)/4*sqrt(3))-(total_tri_count*(pow(small_shape_triside,2)/4*sqrt(3)));
	
	cout << "I can fit at most " << total_tri_count << " small shapes into the main container. The empty area (red) in container is "<<  area << "." <<endl;
}
//calculate_fitting: Decides which calculation to proceed
void calculate_fitting(Shape con_shape, Shape smallShape, double main_c_width, double main_c_height, double main_c_radius, double main_c_triside, ofstream& outputStream,double small_shape_radius,double small_shape_width, double small_shape_height, double small_shape_triside){


	if(con_shape==Shape::Rectangle && smallShape==Shape::Rectangle){
		rectangleInRectangle(main_c_width,main_c_height,small_shape_width,small_shape_height,outputStream);
	}
	else if(con_shape==Shape::Rectangle && smallShape==Shape::Circle){
		circleInRectangle(main_c_width,main_c_height,small_shape_radius,outputStream);
	}
	else if(con_shape==Shape::Rectangle && smallShape==Shape::Triangle){
		triangleInRectangle(main_c_width,main_c_height,small_shape_triside,outputStream);
	}
	else if(con_shape==Shape::Circle && smallShape==Shape::Rectangle){
		rectangleInCircle(main_c_radius,small_shape_width,small_shape_height,outputStream);
	}
	else if(con_shape==Shape::Circle && smallShape==Shape::Circle){
		circleInCircle(main_c_radius,small_shape_radius,outputStream);
	}
	else if(con_shape==Shape::Circle && smallShape==Shape::Triangle){
		triangleInCircle(main_c_radius,small_shape_triside,outputStream);
	}
	else if(con_shape==Shape::Triangle && smallShape==Shape::Rectangle){
		rectangleInTriangle(main_c_triside,small_shape_width,small_shape_height,outputStream);
	}
	else if(con_shape==Shape::Triangle && smallShape==Shape::Circle){
		circleInTriangle(main_c_triside,small_shape_radius,outputStream);
	}
	else if(con_shape==Shape::Triangle && smallShape==Shape::Triangle){
		triangleInTriangle(main_c_triside,small_shape_triside,outputStream);
	}

}
//Closes the file and adds a </svg> tag to the end
void closeFile(ofstream& outputStream){
	outputStream << "</svg>";
	outputStream.close();
}
