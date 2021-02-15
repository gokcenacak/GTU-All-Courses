import javax.swing.*;
import java.awt.*;
import java.util.Random;

/**
 * This class represents the view model of a human
 * @author Gokce Nur Erer
 */
public class HumanViewModel extends JComponent {

    private final Human human;

    /**
     * Constructor that creates a human view model with a given human
     * @param human Human whose view model will be created
     */
    public HumanViewModel(Human human){
        this.human = human;
    }

    /**
     * Returns the human represented by this view model
     * @return Human that is represented by this view model
     */
    public Human getHuman() {
        return human;
    }

    /**
     * Draws the human view model
     * @param g Graphics that will be used
     */
    @Override
    public void paintComponent(Graphics g){
        super.paintComponent(g);

        g.setColor(Color.BLACK);
        g.drawRect(0, 0,5,5);
        if(human.isInfected())
            g.setColor(Color.RED);
        else
            g.setColor(Color.GREEN);
        g.fillRect(0, 0,5,5);
    }

    /**
     * Updates the view model
     */
    public void onTick(){
        setVisible(!human.isHospitalized());
        this.setBounds(human.getXPos(), human.getYPos() , 5, 5);
        this.repaint();

    }
}
