import java.util.*;
import java.lang.*;
import java.awt.*;

enum ShapeType{
	RECTANGLE, TRIANGLE, CIRCLE, NOSHAPE;
}
/**ComposedShape class represents one shape being fitted in a container shape.
  *ComposedShape class implements Shape interface's methods.
*/
public class ComposedShape implements Shape{
	//Defining what inner shape and what container shape are with enum class ShapeType.
	private ShapeType containerShapeDef;
	private ShapeType innerShapeDef;

	//Array that keeps the inner shapes whose type is shape pointer
	private Shape innerShapeArr[];

	//Inner and container shape variables for different class types.
	private Rectangle innerRect;
	private Rectangle containerRect;

	private Triangle innerTri;
	private Triangle containerTri;

	private Circle innerCir;
	private Circle containerCir;

	private Shape containerShape;

	/**ComposedShape constructor which takes a container shape of a rectangle and an inner shape of a rectangle
		 *@param rect_container container rectangle
		 *@param rect_inner inner rectangle
	*/
	public ComposedShape(Rectangle rect_container, Rectangle rect_inner){
		containerShapeDef = ShapeType.RECTANGLE;
		innerShapeDef = ShapeType.RECTANGLE;
		setContainerShapeRect(rect_container);
		setInnerShapeRect(rect_inner);
		containerShape=rect_container;
	}

	/**ComposedShape constructor which takes a container shape of a rectangle and an inner shape of a triangle
		 *@param rect_container container rectangle
		 *@param tri_inner inner triangle
	*/
	public ComposedShape(Rectangle rect_container, Triangle tri_inner){
		containerShapeDef = ShapeType.RECTANGLE;
		innerShapeDef = ShapeType.TRIANGLE;
		setContainerShapeRect(rect_container);
		setInnerShapeTri(tri_inner);
		containerShape=rect_container;

	}

	/**ComposedShape constructor which takes a container shape of a rectangle and an inner shape of a circle
		 *@param rect_container container rectangle
		 *@param cir_inner inner circle
	*/
	public ComposedShape(Rectangle rect_container, Circle cir_inner){
		containerShapeDef = ShapeType.RECTANGLE;
		innerShapeDef = ShapeType.CIRCLE;
		setContainerShapeRect(rect_container);
		setInnerShapeCir(cir_inner);
		containerShape=rect_container;

	}

	/**ComposedShape constructor which takes a container shape of a triangle and an inner shape of a rectangle
		 *@param tri_container container triangle
		 *@param rect_inner inner rectangle
	*/
	public ComposedShape(Triangle tri_container, Rectangle rect_inner){
		containerShapeDef = ShapeType.TRIANGLE;
		innerShapeDef = ShapeType.RECTANGLE;
		setContainerShapeTri(tri_container);
		setInnerShapeRect(rect_inner);
		containerShape=tri_container;

	}

	/**ComposedShape constructor which takes a container shape of a triangle and an inner shape of a triangle
		 *@param tri_container container triangle
		 *@param tri_inner inner triangle
	*/
	public ComposedShape(Triangle tri_container, Triangle tri_inner){
		containerShapeDef = ShapeType.TRIANGLE;
		innerShapeDef = ShapeType.TRIANGLE;
		setContainerShapeTri(tri_container);
		setInnerShapeTri(tri_inner);
		containerShape=tri_container;
	}

	/**ComposedShape constructor which takes a container shape of a triangle and an inner shape of a circle
		 *@param tri_container container triangle
		 *@param cir_inner inner circle
	*/
	public ComposedShape(Triangle tri_container, Circle cir_inner){
		containerShapeDef = ShapeType.TRIANGLE;
		innerShapeDef = ShapeType.CIRCLE;
		setContainerShapeTri(tri_container);
		setInnerShapeCir(cir_inner);
		containerShape=tri_container;
	}

	/**ComposedShape constructor which takes a container shape of a circle and an inner shape of a rectangle
		 *@param cir_container container circle
		 *@param rect_inner inner rectangle
	*/
	public ComposedShape(Circle cir_container, Rectangle rect_inner){
		containerShapeDef = ShapeType.CIRCLE;
		innerShapeDef = ShapeType.RECTANGLE;
		setContainerShapeCir(cir_container);
		setInnerShapeRect(rect_inner);
		containerShape=cir_container;
	}

	/**ComposedShape constructor which takes a container shape of a circle and an inner shape of a triangle
		 *@param cir_container container circle
		 *@param tri_inner inner triangle
	*/
	public ComposedShape(Circle cir_container, Triangle tri_inner){
		containerShapeDef = ShapeType.CIRCLE;
		innerShapeDef = ShapeType.TRIANGLE;
		setContainerShapeCir(cir_container);
		setInnerShapeTri(tri_inner);
		containerShape=cir_container;
	}

	/**ComposedShape constructor which takes a container shape of a circle and an inner shape of a circle
		 *@param cir_container container circle
		 *@param cir_inner inner circle
	*/
	public ComposedShape(Circle cir_container, Circle cir_inner){
		containerShapeDef = ShapeType.CIRCLE;
		innerShapeDef = ShapeType.CIRCLE;
		setContainerShapeCir(cir_container);
		setInnerShapeCir(cir_inner);
		containerShape=cir_container;
	}

	/**Default constructor*/
	public ComposedShape(){
		containerShapeDef = ShapeType.NOSHAPE;
		innerShapeDef = ShapeType.NOSHAPE;
	}

	/**Getter for the container shape type.
	  *@return container shape type.
	*/	
	public ShapeType getContainerShape(){
		return containerShapeDef;
	}
	/**Getter for the container shape.
	  *@return container shape.
	*/	
	public Shape getContainer(){
		return containerShape;
	}
	/**Getter for the inner shape type.
	  *@return container shape type.
	*/	
	public ShapeType getInnerShapeDef(){
		return innerShapeDef;
	}
	/**Getter for the inner shape rectangle.
	  *@return inner shape rectangle.
	*/	
	public Rectangle getInnerShapeRect(){
		return innerRect;
	}
	/**Getter for the container shape rectangle.
	  *@return container shape rectangle.
	*/	
	public Rectangle getContainerShapeRect(){
		return containerRect;
	}
	/**Getter for the inner shape triangle.
	  *@return inner shape triangle.
	*/	
	public Triangle getInnerShapeTri(){
		return innerTri;
	}
	/**Getter for the container shape triangle.
	  *@return inner container triangle.
	*/	
	public Triangle getContainerShapeTri(){
		return containerTri;
	}
	/**Getter for the inner shape circle.
	  *@return inner shape circle.
	*/	
	public Circle getInnerShapeCir(){
		return innerCir;
	}
	/**Getter for the container shape circle.
	  *@return container shape circle.
	*/	
	public Circle getContainerShapeCir(){
		return containerCir;
	}
	/**Setter for the inner shape rectangle.
	  *@param rect_inner inner rectangle.
	*/	
	public void setInnerShapeRect(Rectangle rect_inner){
		innerRect=rect_inner;
	}
	/**Setter for the container shape rectangle.
	  *@param rect_container container rectangle.
	*/	
	public void setContainerShapeRect(Rectangle rect_container){
		containerRect=rect_container;
	}
	/**Setter for the inner shape triangle.
	  *@param tri_inner inner triangle.
	*/	
	public void setInnerShapeTri(Triangle tri_inner){
		innerTri=tri_inner;
	}
	/**Setter for the container shape triangle.
	  *@param tri_container container triangle.
	*/	
	public void setContainerShapeTri(Triangle tri_container){
		containerTri=tri_container;
	}
	/**Setter for the inner shape circle.
	  *@param cir_inner inner circle.
	*/	
	public void setInnerShapeCir(Circle cir_inner){
		innerCir=cir_inner;
	}
	/**Setter for the container shape circle.
	  *@param cir_container container circle.
	*/	
	public void setContainerShapeCir(Circle cir_container){
		containerCir=cir_container;
	}
		
	/**This method fits the most given inner shapes in to the container shape*/
	public void optimalFit(){
		//Calculating the optimal fit for rectangle inner shapes in a rectangle container .
			if(containerShapeDef == ShapeType.RECTANGLE && innerShapeDef == ShapeType.RECTANGLE){
				int xCount,yCount, totalCount;
				double area,temp;
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
					innerShapeArr=new Shape[0];
					area=(containerRect.getWidth()*containerRect.getHeight())-(totalCount*(innerRect.getHeight()*innerRect.getWidth()));
					for(int i=0;i<innerRect.getHeight()*yCount;i+=innerRect.getHeight()){
						for(int j=0;j<innerRect.getWidth()*xCount;j+=innerRect.getWidth()){

							//Creating temporary rectangle object to create a shapeelem object
							Shape s = new Rectangle(j,i,innerRect.getWidth(),innerRect.getHeight());
							//Setting the new inner shape and pushing it to the vector
							Shape[] tempArr=new Shape[innerShapeArr.length+1];
							for(int k=0;k<innerShapeArr.length;++k){
								tempArr[k]=innerShapeArr[k];
							}
							tempArr[tempArr.length-1]=s;
							innerShapeArr=tempArr.clone();
						}
					}
					System.out.printf("I can fit at most %d small shapes into the main container. The empty area (red) in container is %f.\n",totalCount,area);
			}
			//Calculating the optimal fit for triangle inner shapes in a rectangle container .
			else if(containerShapeDef == ShapeType.RECTANGLE && innerShapeDef == ShapeType.TRIANGLE){
					int xTriCount,yTriCount,totalTriCount;
					double area,smallTriHeight,x1,y1,x2,y2,x3,y3;
					smallTriHeight=(innerTri.getSideLength()/2)*Math.sqrt(3);

					xTriCount=(int)(((containerRect.getWidth()/innerTri.getSideLength())*2)-1);
					yTriCount=(int)((containerRect.getHeight()/(smallTriHeight)));
	
					totalTriCount=xTriCount*yTriCount;
					area=(containerRect.getWidth()*containerRect.getHeight())-(totalTriCount*(((Math.pow(innerTri.getSideLength(),2))*Math.sqrt(3))/4));
					System.out.printf("I can fit at most %d small shapes into the main container. The empty area (red) in container is %f.\n",totalTriCount,area);

					innerShapeArr=new Shape[0];
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
								Shape s = new Triangle(x1,y1,x2,y2,x3,y3,innerTri.getSideLength());
								//Setting the new inner shape and pushing it to the vector
								Shape[] tempArr=new Shape[innerShapeArr.length+1];
								for(int k=0;k<innerShapeArr.length;++k){
									tempArr[k]=innerShapeArr[k];
								}
								tempArr[tempArr.length-1]=s;
								innerShapeArr=tempArr.clone();

						}
					}
			}
			//Calculating the optimal fit for circle inner shapes in a rectangle container .
			else if(containerShapeDef == ShapeType.RECTANGLE && innerShapeDef == ShapeType.CIRCLE){
				int xCircleCount,yCircleCount,totalCircleCount;
				double area;

				xCircleCount=(int)(containerRect.getWidth()/(2*innerCir.getRadius()));
				yCircleCount=(int)(containerRect.getHeight()/(2*innerCir.getRadius()));
				totalCircleCount=xCircleCount*yCircleCount;

				innerShapeArr = new Shape[0];
	
				for(double i=innerCir.getRadius();i<=containerRect.getHeight()-innerCir.getRadius();i+=2*innerCir.getRadius()){
					for(double j=innerCir.getRadius();j<=containerRect.getWidth()-innerCir.getRadius();j+=2*innerCir.getRadius()){
						//Creating a temporary circle object to create shapeelem object
						Shape s = new Circle(j,i,innerCir.getRadius());
						//Setting the new inner shape and pushing it to the vector
						Shape[] tempArr=new Shape[innerShapeArr.length+1];
						for(int k=0;k<innerShapeArr.length;++k){
							tempArr[k]=innerShapeArr[k];
						}
						tempArr[tempArr.length-1]=s;
						innerShapeArr=tempArr.clone();
					}
				}
				area=(containerRect.getHeight()*containerRect.getWidth())-(totalCircleCount*Math.pow(innerCir.getRadius(),2)*Math.PI);
					System.out.printf("I can fit at most %d small shapes into the main container. The empty area (red) in container is %f.\n",totalCircleCount,area);
			}
			//Calculating the optimal fit for rectangle inner shapes in a triangle container .
			else if(containerShapeDef == ShapeType.TRIANGLE && innerShapeDef == ShapeType.RECTANGLE){
				double s_x1,s_y1,x1,y1,area,temp,count;
				int total_rect=0;
				if(innerRect.getHeight()<innerRect.getWidth()){
					temp=innerRect.getWidth();
					innerRect.setWidth(innerRect.getHeight());
					innerRect.setHeight(temp);
				}
				count=(int)((containerTri.getSideLength()*Math.sqrt(3)/2-innerRect.getWidth()*Math.sqrt(3)/2)/innerRect.getHeight());
				s_x1=containerTri.getSideLength()/2-innerRect.getWidth()/2;
				s_y1=innerRect.getHeight()*Math.sqrt(3)/2;
				//THIS IS WRONG TRY A SOLUTION FOR IT!
				innerShapeArr = new Shape[0];
				for(int i=0;i<count ;++i){
					x1=s_x1;
					y1=s_y1;
					for(int j=0;x1<containerTri.getSideLength()-(count-i-1)*innerRect.getHeight()/Math.sqrt(3) && s_x1>0;++j){
						//Creating a temporary rectangle object to create shapeelem object
						Shape s = new Rectangle(x1,y1,innerRect.getWidth(),innerRect.getHeight());

						//Setting the new inner shape and pushing it to the array
						Shape[] tempArr=new Shape[innerShapeArr.length+1];
						for(int k=0;k<innerShapeArr.length;++k){
							tempArr[k]=innerShapeArr[k];
						}
						tempArr[tempArr.length-1]=s;
						innerShapeArr=tempArr.clone();
						total_rect++;
						x1+=innerRect.getWidth();
					}
					s_x1-=innerRect.getHeight()/Math.sqrt(3);
					s_y1+=innerRect.getHeight();
				}
				area=(Math.pow(containerTri.getSideLength(),2)*Math.sqrt(3)/4)-total_rect*innerRect.getWidth()*innerRect.getHeight();
				System.out.printf("I can fit at most %d small shapes into the main container. The empty area (red) in container is %f.(WORKS WRONG)\n",total_rect,area);
				
			}
			//Calculating the optimal fit for triangle inner shapes in a triangle container .
			else if(containerShapeDef == ShapeType.TRIANGLE && innerShapeDef == ShapeType.TRIANGLE){
				int total_tri_count,base_count;
					double x1,y1,x2,y2,x3,y3,s_x1,s_x2,s_x3,s_y1,s_y2,s_y3,area;

					base_count=(int)(containerTri.getSideLength()/innerTri.getSideLength());
					total_tri_count=0;
					s_x1=containerTri.getSideLength()/2;
					s_y1=0;
	
					s_x2=containerTri.getSideLength()/2-innerTri.getSideLength()/2;
					s_y2=innerTri.getSideLength()/2*Math.sqrt(3);

					s_x3=containerTri.getSideLength()/2+innerTri.getSideLength()/2;
					s_y3=s_y2;
					innerShapeArr = new Shape[0];
					for(int i=0;i<base_count;++i){
						x1=s_x1;

						x2=s_x2;

						x3=s_x3;

							for(int j=0;j<2*i+1;++j){
								if(j%2==0){
									y1=i*innerTri.getSideLength()/2*Math.sqrt(3);
									y2=(i*innerTri.getSideLength()/2*Math.sqrt(3))+innerTri.getSideLength()/2*Math.sqrt(3);
									y3=y2;
								}
								else{
									y1=(i*innerTri.getSideLength()/2*Math.sqrt(3))+innerTri.getSideLength()/2*Math.sqrt(3);
									y2=i*innerTri.getSideLength()/2*Math.sqrt(3);
									y3=y2;
								}
								//Creating a temporary triangle object to create a shape element
								Shape s = new Triangle(x1,y1,x2,y2,x3,y3,innerTri.getSideLength());
								//Setting the new inner shape and pushing it to the vector
								//Setting the new inner shape and pushing it to the vector
								Shape[] tempArr=new Shape[innerShapeArr.length+1];
								for(int k=0;k<innerShapeArr.length;++k){
									tempArr[k]=innerShapeArr[k];
								}
								tempArr[tempArr.length-1]=s;
								innerShapeArr=tempArr.clone();

	
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
						area=(Math.pow(containerTri.getSideLength(),2)/4*Math.sqrt(3))-(total_tri_count*(Math.pow(innerTri.getSideLength(),2)/4*Math.sqrt(3)));
	
					System.out.printf("I can fit at most %d small shapes into the main container. The empty area (red) in container is %f.\n",total_tri_count,area);
			}
			//Calculating the optimal fit for circle inner shapes in a triangle container .
			else if(containerShapeDef == ShapeType.TRIANGLE && innerShapeDef == ShapeType.CIRCLE){
				double s_x1,s_y1,x1,y1,area;
				int total_circle=0;
				innerShapeArr=new Shape[0];
					s_x1=(containerTri.getSideLength()/2);
					s_y1=2*innerCir.getRadius();

					for(int i=0;(s_y1<=containerTri.getSideLength()/2*Math.sqrt(3)-innerCir.getRadius());++i){	
						x1=s_x1;
						for(int j=0;j<i+1;++j){

							y1=s_y1;
							//Creating a temporary circle object to create shapeelem object
							Shape s = new Circle(x1,y1,innerCir.getRadius());
							//Setting the new inner shape and pushing it to the array
							Shape[] tempArr=new Shape[innerShapeArr.length+1];
							for(int k=0;k<innerShapeArr.length;++k){
								tempArr[k]=innerShapeArr[k];
							}
							tempArr[tempArr.length-1]=s;
							innerShapeArr=tempArr.clone();

							total_circle++;
				
							x1+=2*innerCir.getRadius();
						}
						s_x1-=innerCir.getRadius();
						s_y1+=Math.sqrt(3)*(innerCir.getRadius());
					}
					area=(Math.pow(containerTri.getSideLength(),2)*Math.sqrt(3)/4)-total_circle*Math.pow(innerCir.getRadius(),2)*Math.PI;
					System.out.printf("I can fit at most %d small shapes into the main container. The empty area (red) in container is %f.\n",total_circle,area);
			}
			//Calculating the optimal fit for rectangle inner shapes in a circle container .
			else if(containerShapeDef == ShapeType.CIRCLE && innerShapeDef == ShapeType.RECTANGLE){
				double s_x1,s_y1,x1,y1,area,temp;
				int rect_count=0;
				if(innerRect.getHeight()<innerRect.getWidth()){
					temp=innerRect.getWidth();
					innerRect.setWidth(innerRect.getHeight());
					innerRect.setHeight(temp);
				}
				s_x1=containerCir.getRadius()-containerCir.getRadius()/Math.sqrt(2);
				s_y1=containerCir.getRadius()-containerCir.getRadius()/Math.sqrt(2);
				innerShapeArr=new Shape[0];
				for(double i=0; s_y1<containerCir.getRadius()+containerCir.getRadius()/Math.sqrt(2)-innerRect.getHeight() ;++i){
					x1=s_x1;
					y1=s_y1;

					for(double j=0; x1<containerCir.getRadius()+containerCir.getRadius()/Math.sqrt(2)-innerRect.getWidth();++j){
						//Creating a temporary rectangle object to create shapeelem object
						Shape s = new Rectangle(x1,y1,innerRect.getWidth(),innerRect.getHeight());
						//Setting the new inner shape and pushing it to the vector
						Shape[] tempArr=new Shape[innerShapeArr.length+1];
						for(int k=0;k<innerShapeArr.length;++k){
							tempArr[k]=innerShapeArr[k];
						}
						tempArr[tempArr.length-1]=s;
						innerShapeArr=tempArr.clone();

						rect_count++;
						x1+=innerRect.getWidth();
			
					}
		
					s_y1+=innerRect.getHeight();
				}
				area=Math.pow(containerCir.getRadius(),2)*Math.PI-rect_count*innerRect.getWidth()*innerRect.getHeight();
				System.out.printf("I can fit at most %d small shapes into the main container. The empty area (red) in container is %f.\n",rect_count,area);
			}
			//Calculating the optimal fit for triangle inner shapes in a circle container .
			else if(containerShapeDef == ShapeType.CIRCLE && innerShapeDef == ShapeType.TRIANGLE){
				double s_x1,s_x2,s_x3,area,small_shape_height,x1,x2,x3,y1,y2,y3;
				int tri_count=0,x_tri_count,y_tri_count;
				x_tri_count=(int)(((containerCir.getRadius()*Math.sqrt(2))/innerTri.getSideLength())*2-1);

				small_shape_height=innerTri.getSideLength()*Math.sqrt(3)/2;
				y_tri_count=(int)((containerCir.getRadius()*Math.sqrt(2))/small_shape_height);
				s_x1=containerCir.getRadius()-containerCir.getRadius()/Math.sqrt(2)+innerTri.getSideLength()/2;
				s_x2=containerCir.getRadius()-containerCir.getRadius()/Math.sqrt(2);
				s_x3=containerCir.getRadius()-containerCir.getRadius()/Math.sqrt(2)+innerTri.getSideLength();

				
				innerShapeArr=new Shape[0];

				for(int i = 0; i< y_tri_count ; ++i){
					x1=s_x1;
					x2=s_x2;
					x3=s_x3;	
					for(int j=0 ; j<x_tri_count;++j){
				
						if(((j%2==0) && (i%2==0)) || ((j%2!=0) && (i%2!=0))) {
							y1=containerCir.getRadius()-containerCir.getRadius()/Math.sqrt(2)+(small_shape_height)*i;
							y2=containerCir.getRadius()-containerCir.getRadius()/Math.sqrt(2)+(small_shape_height)+(small_shape_height)*i;
							y3=y2;
						}
						else{
							y1=containerCir.getRadius()-containerCir.getRadius()/Math.sqrt(2)+(small_shape_height)*i+small_shape_height;
							y2=containerCir.getRadius()-containerCir.getRadius()/Math.sqrt(2)+(small_shape_height)*i;
							y3=y2;
						}
						//Creating a temporary triangle object to create shapeelem object
						Shape s = new Triangle(x1,y1,x2,y2,x3,y3,innerTri.getSideLength());
						//Setting the new inner shape and pushing it to the vector
						Shape[] tempArr=new Shape[innerShapeArr.length+1];
						for(int k=0;k<innerShapeArr.length;++k){
							tempArr[k]=innerShapeArr[k];
						}
						tempArr[tempArr.length-1]=s;
						innerShapeArr=tempArr.clone();

						tri_count++;			
						x1+=innerTri.getSideLength()/2;
						x2+=innerTri.getSideLength()/2;
						x3+=innerTri.getSideLength()/2;
					}
		
				}
				area=Math.pow(containerCir.getRadius(),2)*Math.PI-tri_count*(Math.pow(innerTri.getSideLength(),2)*Math.sqrt(3)/4);
				System.out.printf("I can fit at most %d small shapes into the main container. The empty area (red) in container is %f.\n",tri_count,area);
			}
			//Calculating the optimal fit for circle inner shapes in a circle container .
			else if(containerShapeDef == ShapeType.CIRCLE && innerShapeDef == ShapeType.CIRCLE){
				double s_x1,s_y1,x1,y1,area;
				int circle_count=0;
				s_x1=containerCir.getRadius()-containerCir.getRadius()/Math.sqrt(2)+innerCir.getRadius();
				s_y1=containerCir.getRadius()-containerCir.getRadius()/Math.sqrt(2)+innerCir.getRadius();
				innerShapeArr=new Shape[0];
				for(int i=0; s_y1<containerCir.getRadius()+containerCir.getRadius()/Math.sqrt(2)-innerCir.getRadius() ;++i){
					x1=s_x1;
					y1=s_y1;

					for(int j=0; x1<containerCir.getRadius()+containerCir.getRadius()/Math.sqrt(2)-innerCir.getRadius() ;++j){
						//Creating a temporary circle object to create shapeelem object
						Shape s = new Circle(x1,y1,innerCir.getRadius());
						//Setting the new inner shape and pushing it to the vector
						//Setting the new inner shape and pushing it to the vector
						Shape[] tempArr=new Shape[innerShapeArr.length+1];
						for(int k=0;k<innerShapeArr.length;++k){
							tempArr[k]=innerShapeArr[k];
						}
						tempArr[tempArr.length-1]=s;
						innerShapeArr=tempArr.clone();

						circle_count++;	
						x1+=2*innerCir.getRadius();
			
					}
					s_y1+=2*innerCir.getRadius();
				}
				area=Math.pow(containerCir.getRadius(),2)*Math.PI-(Math.pow(innerCir.getRadius(),2)*Math.PI)*circle_count;
				System.out.printf("I can fit at most %d small shapes into the main container. The empty area (red) in container is %f.\n",circle_count,area);
			}
	}
	/**Draws the composed shape to a panel.
	  *@param g Graphics object used in paintComponent.
	*/
	public void draw(Graphics g){
		getContainer().draw(g);
		globalFunc.drawAll(innerShapeArr,g);
	}

	/**Getter for shape pointer array
	  *@return array that has all the inner shapes in it.
	*/
	public Shape [] getInnerShapeArr(){
		return innerShapeArr;
	}
	/**Calculates the area of the composed shape by calculating its container shape's area
	  *@return the area of the composed shape.
	*/
	public double area(){
		if(containerShapeDef==ShapeType.RECTANGLE)
			return containerRect.area();
		else if(containerShapeDef==ShapeType.TRIANGLE)
			return containerTri.area();
		else if(containerShapeDef==ShapeType.CIRCLE)
			return containerCir.area();
		else
			return 0;
	}
	/**Calculates the perimeter of the composed shape by calculating its container shape's perimeter
	  *@return the perimeter of the composed shape.
	*/
	public double perimeter(){
		if(containerShapeDef==ShapeType.RECTANGLE)
			return containerRect.perimeter();
		else if(containerShapeDef==ShapeType.TRIANGLE)
			return containerTri.perimeter();
		else if(containerShapeDef==ShapeType.CIRCLE)
			return containerCir.perimeter();
		else
			return 0;
	}
	/**Implementation of compareTo function in Comparable interface.
	  *@param s object to be compared with the current composed shape object.
	*/
	public int compareTo(Object s){
		if(s instanceof Triangle){
			Triangle t =(Triangle)s;
			return (Double.valueOf(this.area()).compareTo(t.area()));
		}
		else if(s instanceof Rectangle){
			Rectangle r =(Rectangle)s;
			return (Double.valueOf(this.area()).compareTo(r.area()));
		}
		else if(s instanceof Circle){
			Circle c =(Circle)s;
			return (Double.valueOf(this.area()).compareTo(c.area()));
		}
		else if(s instanceof ComposedShape){
			ComposedShape c =(ComposedShape)s;
			return (Double.valueOf(this.area()).compareTo(c.area()));
		}
		else if(s instanceof PolygonDyn){
			PolygonDyn pd =(PolygonDyn)s;
			return (Double.valueOf(this.area()).compareTo(pd.area()));
		}
		else if(s instanceof PolygonVect){
			PolygonVect pv =(PolygonVect)s;
			return (Double.valueOf(this.area()).compareTo(pv.area()));
		}
		else
			return -1;
	}

	public Shape increment(){
		return this;
	}
	public Shape decrement(){
		return this;
	}
}

