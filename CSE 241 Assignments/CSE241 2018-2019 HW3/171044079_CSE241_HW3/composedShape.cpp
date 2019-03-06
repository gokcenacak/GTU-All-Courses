#include <iostream>
#include <cstdlib>
#include <cmath>
#include "composedShape.h"
using namespace std;
		//Initializes the composed shape object to have a rectangle container and a rectangle inner shape.
		//Also initializes innerShapeDef as 'r' and containerShapeDef as 'R'
		ComposedShape::ComposedShape(Rectangle rect_container, Rectangle rect_inner){
			containerShapeDef = Shape::Rectangle;
			setContainerShapeRect(rect_container);
			setInnerShapeRect(rect_inner);
			setInnerShape(ShapeElem(rect_inner));
			
		}
		//Initializes the composed shape object to have a rectangle container and a triangle inner shape.
		//Also initializes innerShapeDef as 't' and containerShapeDef as 'R'
		ComposedShape::ComposedShape(Rectangle rect_container, Triangle tri_inner){
			containerShapeDef = Shape::Rectangle;
			setContainerShapeRect(rect_container);
			setInnerShapeTri(tri_inner);
			setInnerShape(ShapeElem(tri_inner));
		}
		//Initializes the composed shape object to have a rectangle container and a circle inner shape.
		//Also initializes innerShapeDef as 'c' and containerShapeDef as 'R'
		ComposedShape::ComposedShape(Rectangle rect_container, Circle cir_inner){
			containerShapeDef = Shape::Rectangle;
			setContainerShapeRect(rect_container);
			setInnerShapeCir(cir_inner);
			setInnerShape(ShapeElem(cir_inner));
		}
		//Initializes the composed shape object to have a triangle container and a rectangle inner shape.
		//Also initializes innerShapeDef as 'r' and containerShapeDef as 'T'
		ComposedShape::ComposedShape(Triangle tri_container, Rectangle rect_inner){
			containerShapeDef = Shape::Triangle;
			setContainerShapeTri(tri_container);
			setInnerShapeRect(rect_inner);
			setInnerShape(ShapeElem(rect_inner));
		}
		//Initializes the composed shape object to have a triangle container and a triangle inner shape.
		//Also initializes innerShapeDef as 't' and containerShapeDef as 'T'
		ComposedShape::ComposedShape(Triangle tri_container, Triangle tri_inner){
			containerShapeDef = Shape::Triangle;
			setContainerShapeTri(tri_container);
			setInnerShapeTri(tri_inner);
			setInnerShape(ShapeElem(tri_inner));
		}
		//Initializes the composed shape object to have a triangle container and a circle inner shape.
		//Also initializes innerShapeDef as 'c' and containerShapeDef as 'T'
		ComposedShape::ComposedShape(Triangle tri_container, Circle cir_inner){
			containerShapeDef = Shape::Triangle;
			setContainerShapeTri(tri_container);
			setInnerShapeCir(cir_inner);
			setInnerShape(ShapeElem(cir_inner));
		}
		//Initializes the composed shape object to have a circle container and a rectangle inner shape.
		//Also initializes innerShapeDef as 'r' and containerShapeDef as 'C'
		ComposedShape::ComposedShape(Circle cir_container, Rectangle rect_inner){
			containerShapeDef = Shape::Circle;
			setContainerShapeCir(cir_container);
			setInnerShapeRect(rect_inner);
			setInnerShape(ShapeElem(rect_inner));
		}
		//Initializes the composed shape object to have a circle container and a triangle inner shape.
		//Also initializes innerShapeDef as 't' and containerShapeDef as 'C'
		ComposedShape::ComposedShape(Circle cir_container, Triangle tri_inner){
			containerShapeDef = Shape::Circle;
			setContainerShapeCir(cir_container);
			setInnerShapeTri(tri_inner);
			setInnerShape(ShapeElem(tri_inner));
		}
		//Initializes the composed shape object to have a circle container and a circle inner shape.
		//Also initializes innerShapeDef as 'c' and containerShapeDef as 'C'
		ComposedShape::ComposedShape(Circle cir_container, Circle cir_inner){
			containerShapeDef = Shape::Circle;
			setContainerShapeCir(cir_container);
			setInnerShapeCir(cir_inner);
			setInnerShape(ShapeElem(cir_inner));
		}
		//Initializes the composed shape object to have nothing.
		//Also initializes innerShapeDef as ' ' and containerShapeDef as ' '
		ComposedShape::ComposedShape(){
			containerShapeDef = Shape::NoShape;
			innerShape.shapeptr=NULL;
		}

		//char ComposedShape::getInnerShape() const {
		//	return innerShapeDef;
		//}
		Shape ComposedShape::getContainerShape() const {
			return containerShapeDef;
		}
		void ComposedShape::setInnerShapeRect(Rectangle rect_inner){
			innerRect=rect_inner;
		}
		void ComposedShape::setInnerShapeTri(Triangle tri_inner){
			innerTri=tri_inner;
		}
		void ComposedShape::setInnerShapeCir(Circle cir_inner){
			innerCir=cir_inner;
		}
		void ComposedShape::setContainerShapeRect(Rectangle rect_container){
			containerRect=rect_container;
		}
		void ComposedShape::setContainerShapeTri(Triangle tri_container){
			containerTri=tri_container;
		}
		void ComposedShape::setContainerShapeCir(Circle cir_container){
			containerCir=cir_container;
		}

		Rectangle ComposedShape::getInnerShapeRect() const{
			return innerRect;
		}
		Rectangle ComposedShape::getContainerShapeRect() const{
			return containerRect;
		}

		Triangle ComposedShape::getInnerShapeTri() const{
			return innerTri;
		}
		Triangle ComposedShape::getContainerShapeTri() const{
			return containerTri;
		}

		Circle ComposedShape::getInnerShapeCir() const{
			return innerCir;
		}
		Circle ComposedShape::getContainerShapeCir() const{
			return containerCir;
		}
		//Thought is to draw the vectors in a loop also drawing the main container seperately.
		void ComposedShape::draw(ofstream& file) const{
			if(containerShapeDef == Shape::Rectangle){
					file << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << containerRect.getWidth() << "\" height=\"" << containerRect.getHeight()  << "\"> \n";
					file << "<rect x=\"" << 0 << "\" y=\""<< 0 <<"\" width=\"" << containerRect.getWidth() << "\" height=\"" << containerRect.getHeight() << "\" fill=\"green\" stroke-width=\"0.5\" stroke=\"black\"/> \n";
			}
			else if(containerShapeDef == Shape::Triangle){
				file << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << containerTri.getSideLength() << "\" height=\"" << containerTri.getSideLength()*sqrt(3)/2  << "\"> \n";
				file << "<polygon points=\"" << containerTri.getSideLength()/2 << "," << 0 << " " << 0 << "," << containerTri.getSideLength()*sqrt(3)/2 << " " << containerTri.getSideLength() << "," << containerTri.getSideLength()*sqrt(3)/2 << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" /> \n";
			}
			else if(containerShapeDef == Shape::Circle){
				file << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << containerCir.getRadius()*2 << "\" height=\"" << containerCir.getRadius()*2  << "\"> \n";
				file  << "<circle cx=\"" << containerCir.getRadius() << "\" cy=\""<< containerCir.getRadius() <<"\" r=\"" << containerCir.getRadius() << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\"/> \n";
			}
			if(innerShape.shape == Shape::Rectangle){
				for(auto i=0;i<innerShapeVec.size();i++){
					static_cast<Rectangle*>(innerShapeVec[i].shapeptr)->draw(file);		
				}
			}
			else if(innerShape.shape == Shape::Triangle){
				for(auto i=0;i<innerShapeVec.size();i++){
					static_cast<Triangle*>(innerShapeVec[i].shapeptr)->draw(file);
				}
			}
			else if(innerShape.shape == Shape::Circle){
				for(auto i=0;i<innerShapeVec.size();i++){
					static_cast<Circle*>(innerShapeVec[i].shapeptr)->draw(file);
				}
			}	
		}
		//optimalFit() function first decides which action to take by comparing the containerShapeDef and innerShapeDef values. Depending on values it determines an action.
		void ComposedShape::optimalFit() {
			//Calculating the optimal fit for rectangle inner shapes in a rectangle container .
			if(containerShapeDef == Shape::Rectangle && innerShape.shape == Shape::Rectangle){
				int xCount,yCount,temp, totalCount;
				double area;
				if(((int)(containerRect.getWidth()/innerRect.getWidth())*(int)(containerRect.getHeight()/innerRect.getHeight()))>((int)(containerRect.getHeight()/innerRect.getHeight())*(int)(containerRect.getWidth()/innerRect.getWidth()))){

					xCount=(int)(containerRect.getWidth()/innerRect.getWidth());
					yCount=(int)(containerRect.getHeight()/innerRect.getHeight());
				}
				else{
					xCount=(int)(containerRect.getWidth()/innerRect.getHeight());
					yCount=(int)(containerRect.getHeight()/innerRect.getWidth());
					temp=innerRect.getHeight();
					innerRect.setHeight(innerRect.getWidth());
					innerRect.setWidth(temp);

				}	
				
					totalCount=xCount*yCount;
					area=(containerRect.getWidth()*containerRect.getHeight())-(totalCount*(innerRect.getHeight()*innerRect.getWidth()));
					for(int i=0;i<innerRect.getHeight()*yCount;i+=innerRect.getHeight()){
						for(int j=0;j<innerRect.getWidth()*xCount;j+=innerRect.getWidth()){
							//Creating temporary rectangle object to create a shapeelem object
							Rectangle innerRectTemp(j,i,innerRect.getWidth(),innerRect.getHeight());
							//Setting the new inner shape and pushing it to the vector
							setInnerShape(ShapeElem(innerRectTemp));
							innerShapeVec.push_back(innerShape);


						}
					}
					cout << "I can fit at most " << totalCount << " small shapes into the main container. The empty area (red) in container is " << area << "."<< endl;
			}
			//Calculating the optimal fit for triangle inner shapes in a rectangle container .
			else if(containerShapeDef == Shape::Rectangle && innerShape.shape == Shape::Triangle){
					int xTriCount,yTriCount,totalTriCount;
					double area,smallTriHeight,x1,y1,x2,y2,x3,y3;
					smallTriHeight=(innerTri.getSideLength()/2)*sqrt(3);

					xTriCount=((containerRect.getWidth()/innerTri.getSideLength())*2)-1;
					yTriCount=(containerRect.getHeight()/(smallTriHeight));
	
					totalTriCount=xTriCount*yTriCount;
					area=(containerRect.getWidth()*containerRect.getHeight())-(totalTriCount*(((pow(innerTri.getSideLength(),2))*sqrt(3))/4));
					cout << "I can fit at most " << totalTriCount << " small shapes into the main container. The empty area (red) in container is " << area << "."<< endl;

					for(int i=0;i<yTriCount;++i){
						for(int j=0;j<xTriCount;++j){
			
							x1=(innerTri.getSideLength()/2)+(j*innerTri.getSideLength()/2);
							x2=(innerTri.getSideLength()/2)*j;
							x3=(innerTri.getSideLength())+j*(innerTri.getSideLength()/2);

								if((j%2==0 && i%2==0) || (j%2!=0 && i%2!=0)){
									y1=(smallTriHeight)*i;
									y2=(smallTriHeight)+(smallTriHeight)*i;
									y3=y2;
								}
								else{
									y1=(smallTriHeight)*i+smallTriHeight;
									y2=(smallTriHeight)*i;
									y3=y2;
								}
								//Creating temporary triangle object to create a shapeelem object
								Triangle innerTriTemp(x1,y1,x2,y2,x3,y3,innerTri.getSideLength());
								//Setting the new inner shape and pushing it in to vector
								setInnerShape(ShapeElem(innerTriTemp));
								innerShapeVec.push_back(innerShape);


						}
					}
			}
			//Calculating the optimal fit for circle inner shapes in a rectangle container .
			else if(containerShapeDef == Shape::Rectangle && innerShape.shape == Shape::Circle){
				int xCircleCount,yCircleCount,totalCircleCount;
				double area;

				xCircleCount=(int)(containerRect.getWidth()/(2*innerCir.getRadius()));
				yCircleCount=(int)(containerRect.getHeight()/(2*innerCir.getRadius()));
				totalCircleCount=xCircleCount*yCircleCount;
	
	
				for(int i=innerCir.getRadius();i<=containerRect.getHeight()-innerCir.getRadius();i+=2*innerCir.getRadius()){
					for(int j=innerCir.getRadius();j<=containerRect.getWidth()-innerCir.getRadius();j+=2*innerCir.getRadius()){
						//Creating a temporary circle object to create shapeelem object
						Circle innerCirTemp(j,i,innerCir.getRadius());
						//Setting the new inner shape and pushing it in to vector
						setInnerShape(ShapeElem(innerCirTemp));
						innerShapeVec.push_back(innerShape);
					}
				}
				area=(containerRect.getHeight()*containerRect.getWidth())-(totalCircleCount*pow(innerCir.getRadius(),2)*M_PI);
				cout << "I can fit at most " << totalCircleCount << " small shapes into the main container. The empty area (red) in container is " << area << "."<< endl;
			}
			//Calculating the optimal fit for rectangle inner shapes in a triangle container .
			else if(containerShapeDef == Shape::Triangle && innerShape.shape == Shape::Rectangle){
				double s_x1,s_y1,x1,y1,area,temp,count;
				int total_rect=0;
				if(innerRect.getHeight()<innerRect.getWidth()){
					temp=innerRect.getWidth();
					innerRect.setWidth(innerRect.getHeight());
					innerRect.setHeight(temp);
				}
				count=(int)((containerTri.getSideLength()*sqrt(3)/2-innerRect.getWidth()*sqrt(3)/2)/innerRect.getHeight());
				cout << count << endl;
				s_x1=containerTri.getSideLength()/2-innerRect.getWidth()/2;
				s_y1=innerRect.getHeight()*sqrt(3)/2;

				for(int i=0;i<count ;++i){
					x1=s_x1;
					y1=s_y1;
					for(int j=0;x1<containerTri.getSideLength()-(count-i-1)*innerRect.getHeight()/sqrt(3) && s_x1>0;++j){
						//Creating a temporary rectangle object to create shapeelem object
						Rectangle innerRectangleTemp(x1,y1,innerRect.getWidth(),innerRect.getHeight());

						//Setting the new inner shape and pushing it to the vector
						setInnerShape(ShapeElem(innerRectangleTemp));
						innerShapeVec.push_back(innerShape);

						
						total_rect++;
						x1+=innerRect.getWidth();
					}
					s_x1-=innerRect.getHeight()/sqrt(3);
					s_y1+=innerRect.getHeight();
				}
				area=(pow(containerTri.getSideLength(),2)*sqrt(3)/4)-total_rect*innerRect.getWidth()*innerRect.getHeight();
				cout << "I can fit at most " << total_rect << " small shapes into the main container. The empty area (red) in container is "<<  area << "." <<endl;
				
			}
			//Calculating the optimal fit for triangle inner shapes in a triangle container .
			else if(containerShapeDef == Shape::Triangle && innerShape.shape == Shape::Triangle){
				int total_tri_count,base_count;
					double x1,y1,x2,y2,x3,y3,s_x1,s_x2,s_x3,s_y1,s_y2,s_y3,area;

					base_count=(int)(containerTri.getSideLength()/innerTri.getSideLength());
					total_tri_count=0;

					s_x1=containerTri.getSideLength()/2;
					s_y1=0;
	
					s_x2=containerTri.getSideLength()/2-innerTri.getSideLength()/2;
					s_y2=innerTri.getSideLength()/2*sqrt(3);

					s_x3=containerTri.getSideLength()/2+innerTri.getSideLength()/2;
					s_y3=s_y2;
	
					for(int i=0;i<base_count;++i){
						x1=s_x1;

						x2=s_x2;

						x3=s_x3;

							for(int j=0;j<2*i+1;++j){
								if(j%2==0){
									y1=i*innerTri.getSideLength()/2*sqrt(3);
									y2=(i*innerTri.getSideLength()/2*sqrt(3))+innerTri.getSideLength()/2*sqrt(3);
									y3=y2;
								}
								else{
									y1=(i*innerTri.getSideLength()/2*sqrt(3))+innerTri.getSideLength()/2*sqrt(3);
									y2=i*innerTri.getSideLength()/2*sqrt(3);
									y3=y2;
								}
								//Creating a temporary triangle object to create a shape element
								Triangle innerTriTemp(x1,y1,x2,y2,x3,y3,innerTri.getSideLength());
								//Setting the new inner shape and pushing it to the vector
								setInnerShape(ShapeElem(innerTriTemp));
								innerShapeVec.push_back(innerShape);

	
								total_tri_count++;
								x1+=innerTri.getSideLength()/2;
								x2+=innerTri.getSideLength()/2;
								x3+=innerTri.getSideLength()/2;
				
				
							}
						s_x1-=innerTri.getSideLength()/2;
						s_x2-=innerTri.getSideLength()/2;
						s_x3-=innerTri.getSideLength()/2;
		
			
					}
					if((int)containerTri.getSideLength()%(int)innerTri.getSideLength()==0){
						area=0;
					}
					else
						area=(pow(containerTri.getSideLength(),2)/4*sqrt(3))-(total_tri_count*(pow(innerTri.getSideLength(),2)/4*sqrt(3)));
	
					cout << "I can fit at most " << total_tri_count << " small shapes into the main container. The empty area (red) in container is "<<  area << "." <<endl;
			}
			//Calculating the optimal fit for circle inner shapes in a triangle container .
			else if(containerShapeDef == Shape::Triangle && innerShape.shape == Shape::Circle){
				double s_x1,s_y1,x1,y1,area;
				int total_circle=0;

					s_x1=(containerTri.getSideLength()/2);
					s_y1=2*innerCir.getRadius();

					for(int i=0;(s_y1<=containerTri.getSideLength()/2*sqrt(3)-innerCir.getRadius());++i){	
						x1=s_x1;
						for(int j=0;j<i+1;++j){

							y1=s_y1;
							//Creating a temporary circle object to create shapeelem object
							Circle innerCircleTemp(x1,y1,innerCir.getRadius());
							//Setting the new inner shape and pushing it to the vector
							setInnerShape(ShapeElem(innerCircleTemp));
							innerShapeVec.push_back(innerShape);

							total_circle++;
				
							x1+=2*innerCir.getRadius();
						}
						s_x1-=innerCir.getRadius();
						s_y1+=sqrt(3)*(innerCir.getRadius());
					}
					area=(pow(containerTri.getSideLength(),2)*sqrt(3)/4)-total_circle*pow(innerCir.getRadius(),2)*M_PI;
					cout << "I can fit at most " << total_circle << " small shapes into the main container. The empty area (red) in container is "<<  area << "." <<endl;
			}
			//Calculating the optimal fit for rectangle inner shapes in a circle container .
			else if(containerShapeDef == Shape::Circle && innerShape.shape == Shape::Rectangle){
				double s_x1,s_y1,x1,y1,area,temp;
				int rect_count=0;
				if(innerRect.getHeight()<innerRect.getWidth()){
					temp=innerRect.getWidth();
					innerRect.setWidth(innerRect.getHeight());
					innerRect.setHeight(temp);
				}
				s_x1=containerCir.getRadius()-containerCir.getRadius()/sqrt(2);
				s_y1=containerCir.getRadius()-containerCir.getRadius()/sqrt(2);

				for(double i=0; s_y1<containerCir.getRadius()+containerCir.getRadius()/sqrt(2)-innerRect.getHeight() ;++i){
					x1=s_x1;
					y1=s_y1;

					for(double j=0; x1<containerCir.getRadius()+containerCir.getRadius()/sqrt(2)-innerRect.getWidth();++j){
						//Creating a temporary rectangle object to create shapeelem object
						Rectangle innerRectTemp(x1,y1,innerRect.getWidth(),innerRect.getHeight());
						//Setting the new inner shape and pushing it to the vector
						setInnerShape(ShapeElem(innerRectTemp));
						innerShapeVec.push_back(innerShape);

						rect_count++;
						x1+=innerRect.getWidth();
			
					}
		
					s_y1+=innerRect.getHeight();
				}
				area=pow(containerCir.getRadius(),2)*M_PI-rect_count*innerRect.getWidth()*innerRect.getHeight();
				cout << "I can fit at most " << rect_count << " small shapes into the main container. The empty area (red) in container is "<<  area << "." <<endl;
			}
			//Calculating the optimal fit for triangle inner shapes in a circle container .
			else if(containerShapeDef == Shape::Circle && innerShape.shape == Shape::Triangle){
				double s_x1,s_x2,s_x3,area,small_shape_height,x1,x2,x3,y1,y2,y3;
				int tri_count=0,x_tri_count,y_tri_count;
				x_tri_count=((containerCir.getRadius()*sqrt(2))/innerTri.getSideLength())*2-1;

				small_shape_height=innerTri.getSideLength()*sqrt(3)/2;
				y_tri_count=(containerCir.getRadius()*sqrt(2))/small_shape_height;
				s_x1=containerCir.getRadius()-containerCir.getRadius()/sqrt(2)+innerTri.getSideLength()/2;
				s_x2=containerCir.getRadius()-containerCir.getRadius()/sqrt(2);
				s_x3=containerCir.getRadius()-containerCir.getRadius()/sqrt(2)+innerTri.getSideLength();


				for(int i = 0; i< y_tri_count ; ++i){
					x1=s_x1;
					x2=s_x2;
					x3=s_x3;	
					for(int j=0 ; j<x_tri_count;++j){
				
						if(((j%2==0) && (i%2==0)) || ((j%2!=0) && (i%2!=0))) {
							y1=containerCir.getRadius()-containerCir.getRadius()/sqrt(2)+(small_shape_height)*i;
							y2=containerCir.getRadius()-containerCir.getRadius()/sqrt(2)+(small_shape_height)+(small_shape_height)*i;
							y3=y2;
						}
						else{
							y1=containerCir.getRadius()-containerCir.getRadius()/sqrt(2)+(small_shape_height)*i+small_shape_height;
							y2=containerCir.getRadius()-containerCir.getRadius()/sqrt(2)+(small_shape_height)*i;
							y3=y2;
						}
						//Creating a temporary triangle object to create shapeelem object
						Triangle innerTriangleTemp(x1,y1,x2,y2,x3,y3,innerTri.getSideLength());
						//Setting the new inner shape and pushing it to the vector
						setInnerShape(ShapeElem(innerTriangleTemp));
						innerShapeVec.push_back(innerShape);


						
						tri_count++;			
						x1+=innerTri.getSideLength()/2;
						x2+=innerTri.getSideLength()/2;
						x3+=innerTri.getSideLength()/2;
					}
		
				}
				area=pow(containerCir.getRadius(),2)*M_PI-tri_count*(pow(innerTri.getSideLength(),2)*sqrt(3)/4);
				cout << "I can fit at most " << tri_count << " small shapes into the main container. The empty area (red) in container is "<<  area << "." <<endl;
			}
			//Calculating the optimal fit for circle inner shapes in a circle container .
			else if(containerShapeDef == Shape::Circle && innerShape.shape == Shape::Circle){
				double s_x1,s_y1,x1,y1,area;
				int circle_count=0;

				s_x1=containerCir.getRadius()-containerCir.getRadius()/sqrt(2)+innerCir.getRadius();
				s_y1=containerCir.getRadius()-containerCir.getRadius()/sqrt(2)+innerCir.getRadius();

				for(int i=0; s_y1<containerCir.getRadius()+containerCir.getRadius()/sqrt(2)-innerCir.getRadius() ;++i){
					x1=s_x1;
					y1=s_y1;

					for(int j=0; x1<containerCir.getRadius()+containerCir.getRadius()/sqrt(2)-innerCir.getRadius() ;++j){
						//Creating a temporary circle object to create shapeelem object
						Circle innerCircleTemp(x1,y1,innerCir.getRadius());
						//Setting the new inner shape and pushing it to the vector
						setInnerShape(ShapeElem(innerCircleTemp));
						innerShapeVec.push_back(innerShape);

						circle_count++;	
						x1+=2*innerCir.getRadius();
			
					}
					s_y1+=2*innerCir.getRadius();
				}
				area=pow(containerCir.getRadius(),2)*M_PI-(pow(innerCir.getRadius(),2)*M_PI)*circle_count;
				cout << "I can fit at most " << circle_count << " small shapes into the main container. The empty area (red) in container is "<<  area << "." <<endl;
			}
		}

		ostream& operator <<(ostream& outputStream, const ComposedShape::ShapeElem& se){
			if(se.shape==Shape::Rectangle){
				cout << "Shape: Rectangle" << endl;
				cout << "X Coordinate:" << static_cast<Rectangle*>(se.shapeptr)->getxCoor() << endl;
				cout << "Y Coordinate:" << static_cast<Rectangle*>(se.shapeptr)->getyCoor() << endl;
				cout << "Width:" << static_cast<Rectangle*>(se.shapeptr)->getWidth() << endl;
				cout << "Height:" << static_cast<Rectangle*>(se.shapeptr)->getHeight() << endl;
				cout << "Perimeter:" << se.getPerimeter() << endl;
				cout << "Area:" << se.getArea() << endl;
			}
			else if(se.shape==Shape::Triangle){
				cout << "Shape: Triangle" << endl;
				cout << "X1 Coordinate:" << static_cast<Triangle*>(se.shapeptr)->getx1Coor() << endl;
				cout << "Y1 Coordinate:" << static_cast<Triangle*>(se.shapeptr)->gety1Coor() << endl;
				cout << "X2 Coordinate:" << static_cast<Triangle*>(se.shapeptr)->getx2Coor()  << endl;
				cout << "Y2 Coordinate:" << static_cast<Triangle*>(se.shapeptr)->gety2Coor()  << endl;
				cout << "X3 Coordinate:" << static_cast<Triangle*>(se.shapeptr)->getx3Coor()  << endl;
				cout << "Y3 Coordinate:" << static_cast<Triangle*>(se.shapeptr)->gety3Coor()  << endl;
				cout << "Side Length:" << static_cast<Triangle*>(se.shapeptr)->getSideLength()  << endl;
				cout << "Perimeter:" << se.getPerimeter() << endl;
				cout << "Area:" << se.getArea() << endl;
			}
			else if(se.shape==Shape::Circle){
				cout << "Shape: Circle" << endl;
				cout << "X Coordinate:" <<  static_cast<Circle*>(se.shapeptr)->getxCoor() << endl;
				cout << "Y Coordinate:" <<  static_cast<Circle*>(se.shapeptr)->getyCoor() << endl;
				cout << "Radius:" << static_cast<Circle*>(se.shapeptr)->getRadius() << endl;
				cout << "Perimeter:" << se.getPerimeter() << endl;
				cout << "Area:" << se.getArea() << endl;
			}
			return outputStream;
		}
		ostream& operator <<(ostream& outputStream, const ComposedShape& cs){
			cout << "CONTAINER SHAPE" << endl;
			if(cs.getContainerShape() == Shape::Rectangle){
				cout << "Shape: Rectangle" << endl;
				cout << "Width:" << cs.containerRect.getWidth() << endl;
				cout << "Height:" << cs.containerRect.getHeight() << endl;
			}
			else if(cs.getContainerShape() == Shape::Triangle){
				cout << "Shape: Triangle" << endl;
				cout << "Side Length:" << cs.containerTri.getSideLength() << endl;
			}
			else if(cs.getContainerShape() == Shape::Circle){
				cout << "Shape: Circle" << endl;
				cout << "Radius:" << cs.containerCir.getRadius() << endl;
			}
			cout << "INNER SHAPE" << endl;
			cout << cs.innerShape;
			
			return outputStream;
		}
		
		double ComposedShape::ShapeElem::getPerimeter() const{
			return perimeter;
		}
		double ComposedShape::ShapeElem::getArea() const{
			return area;
		}

		void ComposedShape::setInnerShape(ShapeElem se){
			innerShape=se;
			
		}
	
		ComposedShape::ShapeElem::ShapeElem() : shapeptr(nullptr), shape(Shape::NoShape), perimeter(0.0), area(0.0) {};

		ComposedShape::ShapeElem::ShapeElem(Rectangle rect){
			shapeptr=new Rectangle(rect.getxCoor(),rect.getyCoor(),rect.getWidth(),rect.getHeight());
			shape=Shape::Rectangle;
			perimeter=rect.getRectanglePerimeter();
			area=rect.getRectangleArea();
			
		}
		ComposedShape::ShapeElem::ShapeElem(Triangle tri){
			shapeptr=new Triangle(tri.getx1Coor(),tri.gety1Coor(),tri.getx2Coor(),tri.gety2Coor(),tri.getx3Coor(),tri.gety3Coor(),tri.getSideLength());
			shape=Shape::Triangle;
			perimeter=tri.getTrianglePerimeter();
			area=tri.getTriangleArea();
		}
		ComposedShape::ShapeElem::ShapeElem(Circle cir){
			shapeptr=new Circle(cir.getxCoor(),cir.getyCoor(),cir.getRadius());
			shape=Shape::Circle;
			perimeter=cir.getCirclePerimeter();
			area=cir.getCircleArea();
		}

		ComposedShape::ShapeElem ComposedShape::operator[](const Rectangle& rect){
			return ShapeElem(rect);
		}
		ComposedShape::ShapeElem ComposedShape::operator[](const Triangle& tri){
			return ShapeElem(tri);
		}
		ComposedShape::ShapeElem ComposedShape::operator[](const Circle& cir){
			return ShapeElem(cir);
		}
		ComposedShape ComposedShape::operator+=(const Rectangle& rect){
			if(innerShape.shape!=Shape::Rectangle){
				cout << "You cannot add a different inner shape object than rectangle!" << endl;
				exit(1);
			}
			setInnerShape(ShapeElem(rect));
			innerShapeVec.push_back(innerShape);
			return *this;
		}
		ComposedShape ComposedShape::operator+=(const Triangle& tri){
			if(innerShape.shape!=Shape::Triangle){
				cout << "You cannot add a different inner shape object than triangle!" << endl;
				exit(1);
			}
			setInnerShape(ShapeElem(tri));
			innerShapeVec.push_back(innerShape);
			return *this;
		}
		ComposedShape ComposedShape::operator+=(const Circle& cir){
			if(innerShape.shape!=Shape::Circle){
				cout << "You cannot add a different inner shape object than circle!" << endl;
				exit(1);
			}
			setInnerShape(ShapeElem(cir));
			innerShapeVec.push_back(innerShape);
			return *this;
		}
		
		
		



