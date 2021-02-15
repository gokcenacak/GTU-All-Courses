package Q1.PhoneParts;

/**
 * This class represents a camera in a smartphone
 * @author Gokce Nur Erer
 */
public class Camera {
    private int frontResolution;
    private int rearResolution;
    private int optZoom;

    /**
     * Constructor for Camera
     * @param frontResolution Front resolution of the camera
     * @param rearResolution Rear resolution of the camera
     */
    public Camera(int frontResolution, int rearResolution){
        this.frontResolution = frontResolution;
        this.rearResolution = rearResolution;
    }

    /**
     * Setter for optical zoom of the camera
     * @param optZoom Optical zoom value of the camera
     */
    public void setOptZoom(int optZoom) {
        this.optZoom = optZoom;
    }

    /**
     * Returns a string representation of a Camera object
     * @return String representation of a Camera object
     */
    @Override
    public String toString() {
        return "Camera: Front Resolution = " + frontResolution + "Mp , Rear Resolution = " + rearResolution + "Mp , Opt Zoom = " + optZoom + "x";
    }
}
