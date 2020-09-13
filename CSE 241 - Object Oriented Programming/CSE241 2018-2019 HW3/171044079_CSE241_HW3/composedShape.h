#include <fstream>
#include <vector>
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"

using namespace std;
enum class Shape { Rectangle, Triangle, Circle, NoShape };
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
		//char getInnerShape() const;
		Shape getContainerShape() const;

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

		//Overload of << operator to print a composed shape object on to screen
		friend ostream& operator <<(ostream& outputStream, const ComposedShape& cs);

		//Inner class ShapeElem
		class ShapeElem{
			public:
				ShapeElem();
				ShapeElem(Rectangle rect);
				ShapeElem(Triangle tri);
				ShapeElem(Circle cir);
				//Type of the shape
				Shape shape;
				//Pointer that will point the actual shape object such as (rect,tri,cir)
				void * shapeptr;
				//Getting perimeter
				double getPerimeter() const;
				//Getting area
				double getArea() const;
				//Setting perimeter
				void setPerimeter(double perimeter);
				//Setting area
				void setArea(double area);
				//Overload of << operator to print a shape elem object on to screen
				friend ostream& operator <<(ostream& outputStream, const ShapeElem& se);
	
			private:
				double perimeter;
				double area;
				
		
		};
		//Setting the inner shape as a shape elem type for composed shape
		void setInnerShape(ShapeElem se);
		//Getting the inner shape which is a shape elem type
		ShapeElem getInnerShape() const { return innerShape; }
		//Getter for shape elem vector
		vector <ShapeElem> getInnerShapeVec() const { return innerShapeVec; }
		//Overloads of [] for creating a shape elem object with different shapes
		ShapeElem operator [](const Rectangle& rect);
		ShapeElem operator [](const Triangle& tri);
		ShapeElem operator [](const Circle& cir);
		//Overloads of += for adding a shape object(rect,tri,cir) to a composed shape
		ComposedShape operator+=(const Rectangle& rect);
		ComposedShape operator+=(const Triangle& rect);
		ComposedShape operator+=(const Circle& rect);


	private:
		//Defining what inner shape and what container shape are with enum class Shape.
		Shape containerShapeDef;
		ShapeElem innerShape;
		
		//Vector that keeps the inner shapes whose type is shape elem
		vector<ShapeElem> innerShapeVec;

		//Inner and container shape variables for different class types.
		Rectangle innerRect;
		Rectangle containerRect;

		Triangle innerTri;
		Triangle containerTri;

		Circle innerCir;
		Circle containerCir;

};
#endif
