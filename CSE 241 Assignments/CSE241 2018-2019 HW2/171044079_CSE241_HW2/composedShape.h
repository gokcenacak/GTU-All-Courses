#include <fstream>
#include <vector>
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"

using namespace std;

#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_
class ComposedShape{
	public:
		//Initializes the composed shape object to have a rectangle container and a rectangle inner shape.
		ComposedShape(Rectangle rect_container, Rectangle rect_inner);

		//Initializes the composed shape object to have a rectangle container and a triangle inner shape.
		ComposedShape(Rectangle rect_container, Triangle tri_inner);

		//Initializes the composed shape object to have a rectangle container and a circle inner shape.
		ComposedShape(Rectangle rect_container, Circle cir_inner);

		//Initializes the composed shape object to have a triangle container and a rectangle inner shape.
		ComposedShape(Triangle tri_container, Rectangle rect_inner);

		//Initializes the composed shape object to have a triangle container and a triangle inner shape.
		ComposedShape(Triangle tri_container, Triangle tri_inner);

		//Initializes the composed shape object to have a triangle container and a circle inner shape.
		ComposedShape(Triangle tri_container, Circle cir_inner);

		//Initializes the composed shape object to have a circle container and a rectangle inner shape.
		ComposedShape(Circle cir_container, Rectangle rect_inner);

		//Initializes the composed shape object to have a circle container and a triangle inner shape.
		ComposedShape(Circle cir_container, Triangle tri_inner);

		//Initializes the composed shape object to have a circle container and a circle inner shape.
		ComposedShape(Circle cir_container, Circle cir_inner);

		//Constructor for no parameter.
		ComposedShape();

		//To determine what inner shape and what container shape characters are used.
		char getInnerShape() const;
		char getContainerShape() const;

		Rectangle getInnerShapeRect() const;
		Rectangle getContainerShapeRect() const;

		Triangle getInnerShapeTri() const;
		Triangle getContainerShapeTri() const;

		Circle getInnerShapeCir() const;
		Circle getContainerShapeCir() const;
	
		//Setting inner shapes 
		void setInnerShapeRect(Rectangle rect_inner);
		void setContainerShapeRect(Rectangle rect_container);

		void setInnerShapeTri(Triangle tri_inner);
		void setContainerShapeTri(Triangle tri_container);

		void setInnerShapeCir(Circle cir_inner);
		void setContainerShapeCir(Circle cir_container);
		
		//This function tries to fit the most inner shapes in the container shape
		void optimalFit();
		//Draws the composed shape
		void draw(ofstream& file) const;
		
	private:
		//Defining what inner shape and what container shape are with characters.
		char innerShapeDef;
		char containerShapeDef;

		//Vector and inner and container shape variables for different class types.
		Rectangle innerRect;
		Rectangle containerRect;
		vector<Rectangle> rectVector;

		Triangle innerTri;
		Triangle containerTri;
		vector<Triangle> triVector;

		Circle innerCir;
		Circle containerCir;
		vector<Circle> cirVector;		
};
#endif
