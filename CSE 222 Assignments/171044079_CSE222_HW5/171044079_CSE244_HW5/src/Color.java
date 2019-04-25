/**Color class is a class that represents colors that can be represented with
 * RGB values.
 */
public class Color {
    private int red;
    private int green;
    private int blue;
    /**Constructs a color instance with the given red , green and blue values.
     * @param red red value
     * @param green green value
     * @param blue blue value
     * */
    public Color(int red , int green , int blue ){
        this.red = red;
        this.green = green;
        this.blue = blue;
    }
    /**Getter for the red value
     * @return red value of the color
     * */
    public int getRed() {
        return red;
    }
    /**Getter for the green value
     * @return green value of the color
     * */
    public int getGreen() {
        return green;
    }
    /**Getter for the blue value
     * @return blue value of the color
     * */
    public int getBlue() {
        return blue;
    }

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        string.append("[");
        string.append(red);
        string.append(", ");
        string.append(green);
        string.append(", ");
        string.append(blue);
        string.append("]");
        return string.toString();
    }
}
