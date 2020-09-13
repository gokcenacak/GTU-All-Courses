#include <fstream>
#include <vector>
#include <typeinfo>
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "shape.h"
#include "globalFunc.h"
using namespace std;
using namespace ShapeErer;
enum class ShapeType { Rectangle, Triangle, Circle, NoShape };
#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_
//ComposedShape is a concrete class derived from abstract class Shape to represent composed shapes.
class ComposedShape : public Shape{
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


		//Big Three
		//Defualt copy constructor and default assignment operator is okay.
		~ComposedShape();
		
		//To determine what inner shape and what container shape characters are used.
		ShapeType getContainerShape() const;
		ShapeType getInnerShapeDef() const;

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
		virtual void draw(ostream& file) const;

		//Getter for shape pointer vector
		vector <Shape *> getInnerShapeVec() const { return innerShapeVec; }
		//Overloads of [] for getting the object from shape vector within the given index
		Shape & operator [](int index);

		
		//Returns area
		virtual double area() const;
		//Returns perimeter
		virtual double perimeter() const;
		//Returns shape's name
		virtual string shapeName() const;

		//Pre and post ++/-- operator overloads 
		virtual ComposedShape & operator++();
		virtual ComposedShape & operator--();
		virtual ComposedShape & operator++(int ignored);
		virtual ComposedShape & operator--(int ignored);



	private:
		//Defining what inner shape and what container shape are with enum class ShapeType.
		ShapeType containerShapeDef;
		ShapeType innerShapeDef;

		//Vector that keeps the inner shapes whose type is shape pointer
		vector<Shape *> innerShapeVec;

		//Inner and container shape variables for different class types.
		Rectangle innerRect;
		Rectangle containerRect;

		Triangle innerTri;
		Triangle containerTri;

		Circle innerCir;
		Circle containerCir;

};
#endif
