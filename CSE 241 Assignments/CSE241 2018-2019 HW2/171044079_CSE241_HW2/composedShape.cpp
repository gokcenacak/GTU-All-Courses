#include <iostream>
#include <cstdlib>
#include <cmath>
#include "composedShape.h"
using namespace std;
		//Initializes the composed shape object to have a rectangle container and a rectangle inner shape.
		//Also initializes innerShapeDef as 'r' and containerShapeDef as 'R'
		ComposedShape::ComposedShape(Rectangle rect_container, Rectangle rect_inner){
			innerShapeDef='r';
			containerShapeDef='R';
			setContainerShapeRect(rect_container);
			setInnerShapeRect(rect_inner);
		}
		//Initializes the composed shape object to have a rectangle container and a triangle inner shape.
		//Also initializes innerShapeDef as 't' and containerShapeDef as 'R'
		ComposedShape::ComposedShape(Rectangle rect_container, Triangle tri_inner){
			innerShapeDef='t';
			containerShapeDef='R';
			setContainerShapeRect(rect_container);
			setInnerShapeTri(tri_inner);
		}
		//Initializes the composed shape object to have a rectangle container and a circle inner shape.
		//Also initializes innerShapeDef as 'c' and containerShapeDef as 'R'
		ComposedShape::ComposedShape(Rectangle rect_container, Circle cir_inner){
			innerShapeDef='c';
			containerShapeDef='R';
			setContainerShapeRect(rect_container);
			setInnerShapeCir(cir_inner);
		}
		//Initializes the composed shape object to have a triangle container and a rectangle inner shape.
		//Also initializes innerShapeDef as 'r' and containerShapeDef as 'T'
		ComposedShape::ComposedShape(Triangle tri_container, Rectangle rect_inner){
			innerShapeDef='r';
			containerShapeDef='T';
			setContainerShapeTri(tri_container);
			setInnerShapeRect(rect_inner);
		}
		//Initializes the composed shape object to have a triangle container and a triangle inner shape.
		//Also initializes innerShapeDef as 't' and containerShapeDef as 'T'
		ComposedShape::ComposedShape(Triangle tri_container, Triangle tri_inner){
			innerShapeDef='t';
			containerShapeDef='T';
			setContainerShapeTri(tri_container);
			setInnerShapeTri(tri_inner);
		}
		//Initializes the composed shape object to have a triangle container and a circle inner shape.
		//Also initializes innerShapeDef as 'c' and containerShapeDef as 'T'
		ComposedShape::ComposedShape(Triangle tri_container, Circle cir_inner){
			innerShapeDef='c';
			containerShapeDef='T';
			setContainerShapeTri(tri_container);
			setInnerShapeCir(cir_inner);
		}
		//Initializes the composed shape object to have a circle container and a rectangle inner shape.
		//Also initializes innerShapeDef as 'r' and containerShapeDef as 'C'
		ComposedShape::ComposedShape(Circle cir_container, Rectangle rect_inner){
			innerShapeDef='r';
			containerShapeDef='C';
			setContainerShapeCir(cir_container);
			setInnerShapeRect(rect_inner);
		}
		//Initializes the composed shape object to have a circle container and a triangle inner shape.
		//Also initializes innerShapeDef as 't' and containerShapeDef as 'C'
		ComposedShape::ComposedShape(Circle cir_container, Triangle tri_inner){
			innerShapeDef='t';
			containerShapeDef='C';
			setContainerShapeCir(cir_container);
			setInnerShapeTri(tri_inner);
		}
		//Initializes the composed shape object to have a circle container and a circle inner shape.
		//Also initializes innerShapeDef as 'c' and containerShapeDef as 'C'
		ComposedShape::ComposedShape(Circle cir_container, Circle cir_inner){
			innerShapeDef='c';
			containerShapeDef='C';
			setContainerShapeCir(cir_container);
			setInnerShapeCir(cir_inner);
		}
		//Initializes the composed shape object to have nothing.
		//Also initializes innerShapeDef as ' ' and containerShapeDef as ' '
		ComposedShape::ComposedShape(){
			innerShapeDef=' ';
			containerShapeDef=' ';
		}

		char ComposedShape::getInnerShape() const {
			return innerShapeDef;
		}
		char ComposedShape::getContainerShape() const {
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
			if(containerShapeDef =='R' && innerShapeDef == 'r'){
				file << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << containerRect.getWidth() << "\" height=\"" << containerRect.getHeight()  << "\"> \n";
				file << "<rect x=\"" << 0 << "\" y=\""<< 0 <<"\" width=\"" << containerRect.getWidth() << "\" height=\"" << containerRect.getHeight() << "\" fill=\"green\" stroke-width=\"0.5\" stroke=\"black\"/> \n";
				for(auto i=0;i<rectVector.size();i++){
					rectVector[i].draw(file);
				}
			}
			else if(containerShapeDef =='R' && innerShapeDef == 't'){
				file << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << containerRect.getWidth() << "\" height=\"" << containerRect.getHeight()  << "\"> \n";
				file << "<rect x=\"" << 0 << "\" y=\""<< 0 <<"\" width=\"" << containerRect.getWidth() << "\" height=\"" << containerRect.getHeight() << "\" fill=\"green\" stroke-width=\"0.5\" stroke=\"black\"/> \n";
				for(auto i=0;i<triVector.size();i++){
					triVector[i].draw(file);
				}
			}
			else if(containerShapeDef =='R' && innerShapeDef == 'c'){
				file << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << containerRect.getWidth() << "\" height=\"" << containerRect.getHeight()  << "\"> \n";
				file << "<rect x=\"" << 0 << "\" y=\""<< 0 <<"\" width=\"" << containerRect.getWidth() << "\" height=\"" << containerRect.getHeight() << "\" fill=\"green\" stroke-width=\"0.5\" stroke=\"black\"/> \n";
				for(auto i=0;i<cirVector.size();i++){
					cirVector[i].draw(file);
				}
			}
			else if(containerShapeDef =='T' && innerShapeDef == 'r'){
				file << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << containerTri.getSideLength() << "\" height=\"" << containerTri.getSideLength()*sqrt(3)/2  << "\"> \n";
				file << "<polygon points=\"" << containerTri.getSideLength()/2 << "," << 0 << " " << 0 << "," << containerTri.getSideLength()*sqrt(3)/2 << " " << containerTri.getSideLength() << "," << containerTri.getSideLength()*sqrt(3)/2 << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" /> \n";
				for(auto i=0;i<rectVector.size();i++){
					rectVector[i].draw(file);
				}
			}
			else if(containerShapeDef =='T' && innerShapeDef == 't'){
				file << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << containerTri.getSideLength() << "\" height=\"" << containerTri.getSideLength()*sqrt(3)/2  << "\"> \n";
				file << "<polygon points=\"" << containerTri.getSideLength()/2 << "," << 0 << " " << 0 << "," << containerTri.getSideLength()*sqrt(3)/2 << " " << containerTri.getSideLength() << "," << containerTri.getSideLength()*sqrt(3)/2 << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" /> \n";
				for(auto i=0;i<triVector.size();i++){
					triVector[i].draw(file);
				}
			}
			else if(containerShapeDef =='T' && innerShapeDef == 'c'){
				file << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << containerTri.getSideLength() << "\" height=\"" << containerTri.getSideLength()*sqrt(3)/2  << "\"> \n";
				file << "<polygon points=\"" << containerTri.getSideLength()/2 << "," << 0 << " " << 0 << "," << containerTri.getSideLength()*sqrt(3)/2 << " " << containerTri.getSideLength() << "," << containerTri.getSideLength()*sqrt(3)/2 << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" /> \n";
				for(auto i=0;i<cirVector.size();i++){
					cirVector[i].draw(file);
				}
			}
			else if(containerShapeDef =='C' && innerShapeDef == 'r'){
				file << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << containerCir.getRadius()*2 << "\" height=\"" << containerCir.getRadius()*2  << "\"> \n";
				file  << "<circle cx=\"" << containerCir.getRadius() << "\" cy=\""<< containerCir.getRadius() <<"\" r=\"" << containerCir.getRadius() << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\"/> \n";
				for(auto i=0;i<rectVector.size();i++){
					rectVector[i].draw(file);
				}
			}
			else if(containerShapeDef =='C' && innerShapeDef == 't'){
				file << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << containerCir.getRadius()*2 << "\" height=\"" << containerCir.getRadius()*2  << "\"> \n";
				file  << "<circle cx=\"" << containerCir.getRadius() << "\" cy=\""<< containerCir.getRadius() <<"\" r=\"" << containerCir.getRadius() << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\"/> \n";
				for(auto i=0;i<triVector.size();i++){
					triVector[i].draw(file);
				}
			}
			else if(containerShapeDef =='C' && innerShapeDef == 'c'){
				file << "<svg version=\"1.1\" baseProfile=\"full\" width=\"" << containerCir.getRadius()*2 << "\" height=\"" << containerCir.getRadius()*2  << "\"> \n";
				file  << "<circle cx=\"" << containerCir.getRadius() << "\" cy=\""<< containerCir.getRadius() <<"\" r=\"" << containerCir.getRadius() << "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\"/> \n";
				for(auto i=0;i<cirVector.size();i++){
					cirVector[i].draw(file);
				}
			}
		}
		//optimalFit() function first decides which action to take by comparing the containerShapeDef and innerShapeDef values. Depending on values it determines an action.
		void ComposedShape::optimalFit() {
			//Calculating the optimal fit for rectangle inner shapes in a rectangle container .
			if(containerShapeDef =='R' && innerShapeDef == 'r'){
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
							//Creating inner shape object
							Rectangle innerRectTemp(j,i,innerRect.getWidth(),innerRect.getHeight());
							//Pushing it to vector
							rectVector.push_back(innerRectTemp);
						}
					}
					
					cout << "I can fit at most " << totalCount << " small shapes into the main container. The empty area (red) in container is " << area << "."<< endl;
			}
			//Calculating the optimal fit for triangle inner shapes in a rectangle container .
			else if(containerShapeDef =='R' && innerShapeDef == 't'){
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
								//Creating inner shape object
								Triangle innerTriTemp(x1,y1,x2,y2,x3,y3,innerTri.getSideLength());
								//Pushing it to vector
								triVector.push_back(innerTriTemp);

						}
					}
			}
			//Calculating the optimal fit for circle inner shapes in a rectangle container .
			else if(containerShapeDef =='R' && innerShapeDef == 'c'){
				int xCircleCount,yCircleCount,totalCircleCount;
				double area;

				xCircleCount=(int)(containerRect.getWidth()/(2*innerCir.getRadius()));
				yCircleCount=(int)(containerRect.getHeight()/(2*innerCir.getRadius()));
				totalCircleCount=xCircleCount*yCircleCount;
	
	
				for(int i=innerCir.getRadius();i<=containerRect.getHeight()-innerCir.getRadius();i+=2*innerCir.getRadius()){
					for(int j=innerCir.getRadius();j<=containerRect.getWidth()-innerCir.getRadius();j+=2*innerCir.getRadius()){
						//Creating inner shape object
						Circle innerCirTemp(j,i,innerCir.getRadius());
						//Pushing it to vector
						cirVector.push_back(innerCirTemp);
					}
				}
				area=(containerRect.getHeight()*containerRect.getWidth())-(totalCircleCount*pow(innerCir.getRadius(),2)*M_PI);
				cout << "I can fit at most " << totalCircleCount << " small shapes into the main container. The empty area (red) in container is " << area << "."<< endl;
			}
			//Calculating the optimal fit for rectangle inner shapes in a triangle container .
			else if(containerShapeDef =='T' && innerShapeDef == 'r'){
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
						//Creating inner shape object
						Rectangle innerRectangleTemp(x1,y1,innerRect.getWidth(),innerRect.getHeight());
						//Pushing it to the vector
						rectVector.push_back(innerRectangleTemp);
						
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
			else if(containerShapeDef =='T' && innerShapeDef == 't'){
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
								//Creating inner shape object
								Triangle innerTriTemp(x1,y1,x2,y2,x3,y3,innerTri.getSideLength());
								//Pushing it in vector
								triVector.push_back(innerTriTemp);
	
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
			else if(containerShapeDef =='T' && innerShapeDef == 'c'){
				double s_x1,s_y1,x1,y1,area;
				int total_circle=0;

					s_x1=(containerTri.getSideLength()/2);
					s_y1=2*innerCir.getRadius();

					for(int i=0;(s_y1<=containerTri.getSideLength()/2*sqrt(3)-innerCir.getRadius());++i){	
						x1=s_x1;
						for(int j=0;j<i+1;++j){

							y1=s_y1;
							//Creating inner shape object
							Circle innerCircleTemp(x1,y1,innerCir.getRadius());
							//Pushing it in vector
							cirVector.push_back(innerCircleTemp);
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
			else if(containerShapeDef =='C' && innerShapeDef == 'r'){
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
						//Creating inner shape object
						Rectangle innerRectTemp(x1,y1,innerRect.getWidth(),innerRect.getHeight());
						//Pushing it in vector
						rectVector.push_back(innerRectTemp);
						rect_count++;
						x1+=innerRect.getWidth();
			
					}
		
					s_y1+=innerRect.getHeight();
				}
				area=pow(containerCir.getRadius(),2)*M_PI-rect_count*innerRect.getWidth()*innerRect.getHeight();
				cout << "I can fit at most " << rect_count << " small shapes into the main container. The empty area (red) in container is "<<  area << "." <<endl;
			}
			//Calculating the optimal fit for triangle inner shapes in a circle container .
			else if(containerShapeDef =='C' && innerShapeDef == 't'){
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
						//Creating the inner shape object
						Triangle innerTriangleTemp(x1,y1,x2,y2,x3,y3,innerTri.getSideLength());
						//Pushing it to the vector
						triVector.push_back(innerTriangleTemp);
						
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
			else if(containerShapeDef =='C' && innerShapeDef == 'c'){
				double s_x1,s_y1,x1,y1,area;
				int circle_count=0;

				s_x1=containerCir.getRadius()-containerCir.getRadius()/sqrt(2)+innerCir.getRadius();
				s_y1=containerCir.getRadius()-containerCir.getRadius()/sqrt(2)+innerCir.getRadius();

				for(int i=0; s_y1<containerCir.getRadius()+containerCir.getRadius()/sqrt(2)-innerCir.getRadius() ;++i){
					x1=s_x1;
					y1=s_y1;

					for(int j=0; x1<containerCir.getRadius()+containerCir.getRadius()/sqrt(2)-innerCir.getRadius() ;++j){
						//Creating the inner shape object
						Circle innerCircleTemp(x1,y1,innerCir.getRadius());
						//Pushing it to the vector
						cirVector.push_back(innerCircleTemp);
						circle_count++;	
						x1+=2*innerCir.getRadius();
			
					}
					s_y1+=2*innerCir.getRadius();
				}
				area=pow(containerCir.getRadius(),2)*M_PI-(pow(innerCir.getRadius(),2)*M_PI)*circle_count;
				cout << "I can fit at most " << circle_count << " small shapes into the main container. The empty area (red) in container is "<<  area << "." <<endl;
			}
		}









