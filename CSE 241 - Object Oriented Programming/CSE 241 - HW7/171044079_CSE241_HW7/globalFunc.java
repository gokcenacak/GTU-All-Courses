import java.lang.*;
import java.util.*;
import java.awt.*;
import javax.swing.*;
/**This class declares all the global methods that will be used on shape arrays*/
public class globalFunc{
	/**This method takes a shape arr and sorts the array respect to each element's areas
	  *@param arr shape array to be sorted.
	  *@return sorted array.
	*/
	public static Shape[] sortShapes(Shape [] arr){
		Shape temp;
		for(int i=0;i<arr.length-1;++i){
			for(int j=0;j<arr.length-i-1;++j){
				if(arr[j].compareTo(arr[j+1])==1){
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
		}
		return arr;
	}
	/**This method takes a shape arr and converts each shape in the array to polygons.
	  *@param arr shape array to be converted.
	  *@return polygon array.
	*/
	public static Polygon [] convertAll(Shape [] arr){
		Polygon[] res=new Polygon[arr.length];
		for(int i=0;i<arr.length;++i){
			if(arr[i] instanceof Rectangle){
				res[i] = new PolygonVect((Rectangle)(arr[i]));
			}
			if(arr[i] instanceof Triangle){
				res[i] = new PolygonVect((Triangle)(arr[i]));
				
			}
			if(arr[i] instanceof Circle){
				res[i] = new PolygonVect((Circle)(arr[i]));
				
			}
		}
		return res;
	}
	/**This method takes a shape arr and a Graphics g object to draw all shapes to a panel.
	  *@param arr shape array to be drawn.
	  *@param g Graphics object used in paintComponent in JPanel.
	*/
	public static void drawAll(Shape[] arr, Graphics g){
        for(int i=0;i<arr.length;++i){
        	arr[i].draw(g);
		}
	}
}