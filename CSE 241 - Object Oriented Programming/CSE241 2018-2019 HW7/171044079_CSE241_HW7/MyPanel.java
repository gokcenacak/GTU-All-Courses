import java.lang.*;
import java.util.*;
import java.awt.*;
import javax.swing.*;
/**This class extends from JPanel to draw specific shape objects to a panel*/
public class MyPanel extends JPanel{
	Shape s;
	/**Constructor of MyPanel that takes a Shape object.
	  *@param sh object to be drawn to the panel.
	*/
	public MyPanel(Shape sh){
		this.s=sh;
	}
	/**Default constructor.
	*/
	public MyPanel(){

	}
	public Dimension getPreferredSize() {
        return new Dimension(350,325);
    }
    /**Overriding the paintComponent method of the JPanel to use draw methods of the other shape classes(rectangle,triangle..).
      *@param g Graphics object used in paintComponent in JPanel.
	*/
	public void paintComponent(Graphics g) {
        super.paintComponent(g);       
        s.draw(g);
    }  
}