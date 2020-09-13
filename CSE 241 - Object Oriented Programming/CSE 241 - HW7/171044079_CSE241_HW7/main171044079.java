import java.lang.*;
import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class main171044079{
	private static JFrame f;
	private static MyPanel panel;
	public static void main (String args[]){

		final Rectangle rect = new Rectangle(0,0,240,160);
		final Rectangle rect1 = new Rectangle(0,0,40,20);
		System.out.println("\n-----TESTING FOR RECTANGLE-----");
		System.out.printf("For rect: Area=%.2f Perimeter=%.2f\n",rect.area(),rect.perimeter());
		System.out.printf("For rect1: Area=%.2f Perimeter=%.2f\n",rect1.area(),rect1.perimeter());
		System.out.println("For rect: Testing increment function..Current x,y values: x:" + rect.getxCoor() + " y:" + rect.getyCoor());
		rect.increment();
		System.out.printf("New x,y coord for rect after increment= %.2f %.2f\n",rect.getxCoor(),rect.getyCoor());
		System.out.println("For rect: Testing decrement function..Current x,y values: x:"+ rect.getxCoor() + " y:" + rect.getyCoor());
		rect.decrement();
		System.out.printf("New x,y coord for rect after decrement= %.2f %.2f\n",rect.getxCoor(),rect.getyCoor());

		System.out.println("Comparing rect to rect1, rect has area of "+rect.area()+" rect1 has area of "+ rect1.area());
		if(rect.compareTo(rect1)==-1)
			System.out.println("Comparison result: Smaller");
		else if(rect.compareTo(rect1)==0)
			System.out.println("Comparison result: Equal");
		else if(rect.compareTo(rect1)==1)
			System.out.println("Comparison result: Bigger");
		

		final Triangle tri = new Triangle(300);
		final Triangle tri1 = new Triangle(30);
		System.out.println("\n-----TESTING FOR TRIANGLE-----");
		System.out.printf("For tri: Area=%.2f Perimeter=%.2f\n",tri.area(),tri.perimeter());
		System.out.printf("For tri1: Area=%.2f Perimeter=%.2f\n",tri1.area(),tri1.perimeter());
		System.out.println("For tri: Testing increment function..Current x1,y1 x2,y2 x3,y3 values:\nx1: " + tri.getx1Coor() + " y1: " + tri.gety1Coor());
		System.out.println("x2: " + tri.getx2Coor() + " y2: " + tri.gety2Coor());
		System.out.println("x3: " + tri.getx3Coor() + " y3: " + tri.gety3Coor());


		tri.increment();
		System.out.println("New x1,y1 x2,y2 x3,y3 values after increment:\nx1: " + tri.getx1Coor() + " y1: " + tri.gety1Coor());
		System.out.println("x2: " + tri.getx2Coor() + " y2: " + tri.gety2Coor());
		System.out.println("x3: " + tri.getx3Coor() + " y3: " + tri.gety3Coor());

		System.out.println("For tri: Testing decrement function..Current x1,y1 x2,y2 x3,y3 values:\nx1: " + tri.getx1Coor() + " y1: " + tri.gety1Coor());
		System.out.println("x2: " + tri.getx2Coor() + " y2: " + tri.gety2Coor());
		System.out.println("x3: " + tri.getx3Coor() + " y3: " + tri.gety3Coor());
		tri.decrement();

		System.out.println("New x1,y1 x2,y2 x3,y3 values after decrement:\nx1: " + tri.getx1Coor() + " y1: " + tri.gety1Coor());
		System.out.println("x2: " + tri.getx2Coor() + " y2: " + tri.gety2Coor());
		System.out.println("x3: " + tri.getx3Coor() + " y3: " + tri.gety3Coor());

		System.out.println("Comparing tri to tri1, tri has area of "+tri.area()+" tri1 has area of "+ tri1.area());

		if(tri.compareTo(tri1)==-1)
			System.out.println("Comparison result: Smaller");
		else if(tri.compareTo(tri1)==0)
			System.out.println("Comparison result: Equal");
		else if(tri.compareTo(tri1)==1)
			System.out.println("Comparison result: Bigger");



		final Circle cir = new Circle(100,100,100);
		final Circle cir1 = new Circle(40,40,40);

		System.out.println("\n-----TESTING FOR CIRCLE-----");
		System.out.printf("For cir: Area=%.2f Perimeter=%.2f\n",cir.area(),cir.perimeter());
		System.out.printf("For cir1: Area=%.2f Perimeter=%.2f\n",cir1.area(),cir1.perimeter());
		System.out.println("For cir: Testing increment function..Current x,y values: x:" + cir.getxCoor() + " y:" + cir.getyCoor());
		cir.increment();
		System.out.printf("New x,y coord for cir after increment= %.2f %.2f\n",cir.getxCoor(),cir.getyCoor());
		System.out.println("For cir: Testing decrement function..Current x,y values: x:"+ cir.getxCoor() + " y:" + cir.getyCoor());
		cir.decrement();
		System.out.printf("New x,y coord for cir after decrement= %.2f %.2f\n",cir.getxCoor(),cir.getyCoor());

		System.out.println("Comparing cir to cir1, cir has area of "+cir.area()+" cir1 has area of "+ cir1.area());
		if(cir.compareTo(cir1)==-1)
			System.out.println("Comparison result: Smaller");
		else if(cir.compareTo(cir1)==0)
			System.out.println("Comparison result: Equal");
		else if(cir.compareTo(cir1)==1)
			System.out.println("Comparison result: Bigger");

		final ComposedShape cs = new ComposedShape(rect,rect1);
		final ComposedShape cs1 = new ComposedShape(rect,tri1);
		final ComposedShape cs2 = new ComposedShape(rect,cir1);
		final ComposedShape cs3 = new ComposedShape(tri,rect1);
		final ComposedShape cs4 = new ComposedShape(tri,tri1);
		final ComposedShape cs5 = new ComposedShape(tri,cir1);
		final ComposedShape cs6 = new ComposedShape(cir,rect1);
		final ComposedShape cs7 = new ComposedShape(cir,tri1);
		final ComposedShape cs8 = new ComposedShape(cir,cir1);

		System.out.println("\n-----TESTING FOR COMPOSED SHAPE-----");
		System.out.printf("For cs: Area=%.2f Perimeter=%.2f\n",cs.area(),cs.perimeter());
		System.out.printf("Testing optimal fit for 9 different combination, starts from R-R,R-T...C-T,C-C\n");

		cs.optimalFit();
		System.out.print("\n");

		cs1.optimalFit();
		System.out.print("\n");

		cs2.optimalFit();
		System.out.print("\n");

		cs3.optimalFit();
		System.out.print("\n");

		cs4.optimalFit();
		System.out.print("\n");

		cs5.optimalFit();
		System.out.print("\n");

		cs6.optimalFit();
		System.out.print("\n");

		cs7.optimalFit();
		System.out.print("\n");

		cs8.optimalFit();
		System.out.print("\n");



		final PolygonDyn pd = new PolygonDyn(rect1);
		System.out.println("\n-----TESTING FOR POLYGONDYN-----");
		System.out.printf("For pd: Area=%.2f Perimeter=%.2f\n",pd.area(),pd.perimeter());
		System.out.println("\nComparing pd with the rect1 that it is constructed with -- which will result equal");

		if(rect1.compareTo(pd)==-1)
			System.out.println("Comparison result: Smaller");
		else if(rect1.compareTo(pd)==0)
			System.out.println("Comparison result: Equal");
		else if(rect1.compareTo(pd)==1)
			System.out.println("Comparison result: Bigger");

		final PolygonVect pv = new PolygonVect(tri1);
		System.out.println("\n-----TESTING FOR POLYGONVECT-----");
		System.out.printf("For pv: Area=%.2f Perimeter=%.2f\n",pv.area(),pv.perimeter());
		System.out.println("\nComparing pd with the tri1 that it is constructed with -- which will result equal");

		if(tri1.compareTo(pv)==-1)
			System.out.println("Comparison result: Smaller");
		else if(tri1.compareTo(pv)==0)
			System.out.println("Comparison result: Equal");
		else if(tri1.compareTo(pv)==1)
			System.out.println("Comparison result: Bigger");

		System.out.println("\n-----TESTING GLOBAL METHODS-----\nCreated an array of Shape which each element's areas are:");

		Shape [] arr ={rect,rect1,tri,tri1,cir,cir1};
		for(int i=0;i<arr.length;++i){
			System.out.println("Area for index " + i + ": " + arr[i].area());
		}
		System.out.println("Testing sortShapes method...new sorted array of Shape which each element's areas are:");
		globalFunc.sortShapes(arr);
		for(int i=0;i<arr.length;++i){
			System.out.println("Area for index " + i + ": " + arr[i].area());
		}
		System.out.println("Testing convertAll method...new array of Polygon which each element's areas are:");
		System.out.println("PS index 2 and index 3 are circle so the lose a bit of area while getting converted:");

		Polygon[] polyArr = globalFunc.convertAll(arr);
		for(int i=0;i<polyArr.length;++i){
			System.out.println("Area for index " + i + ": " + polyArr[i].area());
		}
		System.out.println("Testing drawAll method...drawAll is used in ComposedShape class' draw function.");
		System.out.println("Testing draw methods for all classes...Check the GUI for the checks.\nClicking on each button will draw the corresponding shape.");
		System.out.println("Program continues after closing the GUI!");


		//GUI
		f = new JFrame("CSE241 HW7 171044079");
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setPreferredSize(new Dimension(2000, 1000));
        f.setLayout(new FlowLayout());

        JButton button = new JButton("Rectangle");
        button.setPreferredSize(new Dimension(125,30));

        JButton button1 = new JButton("Triangle");
        button1.setPreferredSize(new Dimension(125,30));

        JButton button2 = new JButton("Circle");
        button2.setPreferredSize(new Dimension(125,30));

        JButton button3 = new JButton("CS R-R");
        button3.setPreferredSize(new Dimension(125,30));

		JButton button4 = new JButton("CS R-T");
        button4.setPreferredSize(new Dimension(125,30));

        JButton button5 = new JButton("CS R-C");
        button5.setPreferredSize(new Dimension(125,30));

		JButton button6 = new JButton("CS T-R");
        button6.setPreferredSize(new Dimension(125,30));

		JButton button7 = new JButton("CS T-T");
        button7.setPreferredSize(new Dimension(125,30));

        JButton button8 = new JButton("CS T-C");
        button8.setPreferredSize(new Dimension(125,30));

		JButton button9 = new JButton("CS T-R");
        button9.setPreferredSize(new Dimension(125,30));

		JButton button10 = new JButton("CS T-T");
        button10.setPreferredSize(new Dimension(125,30));

        JButton button11 = new JButton("CS T-C");
        button11.setPreferredSize(new Dimension(125,30));

        JButton button12 = new JButton("PolygonDyn");
        button12.setPreferredSize(new Dimension(125,30));

        JButton button13 = new JButton("PolygonVect");
        button13.setPreferredSize(new Dimension(125,30));

    
        f.add(button);
        f.add(button1); 
        f.add(button2);
        f.add(button3);
        f.add(button4);
        f.add(button5);
        f.add(button6);
        f.add(button7); 
        f.add(button8);
        f.add(button9);
        f.add(button10);
        f.add(button11);
        f.add(button12);
        f.add(button13);

        button.addActionListener(new ActionListener(){
        	public void actionPerformed(ActionEvent e){
        		panel=new MyPanel(rect1);
        		f.add(panel);
        		f.setVisible(true);
        	}
        });
        button1.addActionListener(new ActionListener(){
        	public void actionPerformed(ActionEvent e){
        		panel=new MyPanel(tri1);
        		f.add(panel);
        		f.setVisible(true);
        	}
        });
        button2.addActionListener(new ActionListener(){
        	public void actionPerformed(ActionEvent e){
        		panel=new MyPanel(cir1);
        		f.add(panel);
        		f.setVisible(true);
        	}
        });
        button3.addActionListener(new ActionListener(){
        	public void actionPerformed(ActionEvent e){
        		panel=new MyPanel(cs);
        		f.add(panel);
        		f.setVisible(true);
        	}
        });
        button4.addActionListener(new ActionListener(){
        	public void actionPerformed(ActionEvent e){
        		panel=new MyPanel(cs1);
        		f.add(panel);
        		f.setVisible(true);
        	}
        });
        button5.addActionListener(new ActionListener(){
        	public void actionPerformed(ActionEvent e){
        		panel=new MyPanel(cs2);
        		f.add(panel);
        		f.setVisible(true);
        	}
        });
        button6.addActionListener(new ActionListener(){
        	public void actionPerformed(ActionEvent e){
        		panel=new MyPanel(cs3);
        		f.add(panel);
        		f.setVisible(true);
        	}
        });
        button7.addActionListener(new ActionListener(){
      	public void actionPerformed(ActionEvent e){
        		panel=new MyPanel(cs4);
        		f.add(panel);
        		f.setVisible(true);
        	}
        });
        button8.addActionListener(new ActionListener(){
       	public void actionPerformed(ActionEvent e){
        		panel=new MyPanel(cs5);
        		f.add(panel);
        		f.setVisible(true);
        	}
        });
        button9.addActionListener(new ActionListener(){
       	public void actionPerformed(ActionEvent e){
        		panel=new MyPanel(cs6);
        		f.add(panel);
        		f.setVisible(true);
        	}
        });
        button10.addActionListener(new ActionListener(){
        	public void actionPerformed(ActionEvent e){
        		panel=new MyPanel(cs7);
        		f.add(panel);
        		f.setVisible(true);
        	}
        });
        button11.addActionListener(new ActionListener(){
        	public void actionPerformed(ActionEvent e){
        		panel=new MyPanel(cs8);
        		f.add(panel);
        		f.setVisible(true);
        	}
        });
        button12.addActionListener(new ActionListener(){
        	public void actionPerformed(ActionEvent e){
        		panel=new MyPanel(pd);
        		f.add(panel);
        		f.setVisible(true);
        	}
        });
        button13.addActionListener(new ActionListener(){
        	public void actionPerformed(ActionEvent e){
        		panel=new MyPanel(pv);
        		f.add(panel);
        		f.setVisible(true);
        	}
        });

        f.setVisible(true);
        f.pack();
 
 		System.out.println("\nCHECKS FOR EXCEPTIONS...");
 		try{
 			System.out.println("Rectangle with negative x coordinate...");
 		    Rectangle rectexcp = new Rectangle(-1,0,240,160);
 		   
 		}
 		catch(RuntimeException e){
 			System.out.println(e.getMessage());
 		}
 		try{
 			System.out.println("Rectangle with negative y coordinate...");
 		    Rectangle rectexcp1 = new Rectangle(0,-1,240,160);
 		   
 		}
 		catch(RuntimeException e){
 			System.out.println(e.getMessage());
 		}
 		try{
 			System.out.println("Rectangle with negative width...");
 		    Rectangle rectexcp = new Rectangle(0,0,-1,160);
 		}
 		catch(RuntimeException e){
 			System.out.println(e.getMessage());
 		}
 		try{
 			System.out.println("Rectangle with negative height...");
 		    Rectangle rectexcp = new Rectangle(0,0,240,-1);
 		}
 		catch(RuntimeException e){
 			System.out.println(e.getMessage());
 		}
 		try{
 			System.out.println("\nTriangle with negative x1 coordinate...Exception works the same for x2 and x3 coordinates...");
 		    Triangle triexcp = new Triangle(-1,0,2,5,9,5,240);
 		   
 		}
 		catch(RuntimeException e){
 			System.out.println(e.getMessage());
 		}
 		try{
 			System.out.println("Triangle with negative y1 coordinate...Exception works the same for y2 and y3 coordinates...");
 		    Triangle triexcp = new Triangle(0,-1,2,5,9,5,240);
 		   
 		}
 		catch(RuntimeException e){
 			System.out.println(e.getMessage());
 		}
 		try{
 			System.out.println("Triangle with negative side length...");
 		    Triangle triexcp = new Triangle(-100);
 		   
 		}
 		catch(RuntimeException e){
 			System.out.println(e.getMessage());
 		}
 		try{
 			System.out.println("\nCircle with negative x coordinate...");
 		    Circle cirexcp = new Circle(-240,240,240);
 		   
 		}
 		catch(RuntimeException e){
 			System.out.println(e.getMessage());
 		}
 		try{
 			System.out.println("Circle with negative y coordinate...");
 		    Circle cirexcp = new Circle(240,-240,240);
 		   
 		}
 		catch(RuntimeException e){
 			System.out.println(e.getMessage());
 		}
 		try{
 			System.out.println("Circle with negative radius...");
 		    Circle cirexcp = new Circle(240,240,-240);
 		}
 		catch(RuntimeException e){
 			System.out.println(e.getMessage());
 		}
	}
}