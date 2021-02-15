package Q1;

import Q1.PhoneParts.*;

/**
 * This class represents a smartphone
 * @author Gokce Nur Erer
 */
public class Smartphone {
    /**
     * Model of the smartphone
     */
    PhoneModel model;
    /**
     * Display of the smartphone
     */
    Display display;
    /**
     * Battery of the smartphone
     */
    Battery battery;
    /**
     * CPU&RAM of the smartphone
     */
    CPU_RAM cpuAndRam;
    /**
     * Storage of the smartphone
     */
    Storage storage;
    /**
     * Camera of the smartphone
     */
    Camera camera;
    /**
     * Phone case of the smartphone
     */
    Case phoneCase;

    /**
     * Getter for the model of the smartphone
     * @return Model of the smartphone
     */
    public PhoneModel getModel() {
        return model;
    }

    /**
     * Getter for the display of the smartphone
     * @return Display of the smartphone
     */
    public Display getDisplay() {
        return display;
    }

    /**
     * Getter for the battery of the smartphone
     * @return Battery of the smartphone
     */
    public Battery getBattery() {
        return battery;
    }

    /**
     * Getter for the CPU and RAM of the smartphone
     * @return CPU and RAM of the smartphone
     */
    public CPU_RAM getCpuAndRam() {
        return cpuAndRam;
    }

    /**
     * Getter for the storage of the smartphone
     * @return Storage of the smartphone
     */
    public Storage getStorage() {
        return storage;
    }

    /**
     * Getter for the camera of the smartphone
     * @return Camera of the smartphone
     */
    public Camera getCamera() {
        return camera;
    }

    /**
     * Getter for the phone case of the smartphone
     * @return Phone case of the smartphone
     */
    public Case getPhoneCase() {
        return phoneCase;
    }

    /**
     * Constructor of Smartphone
     * @param model Model of the smartphone
     * @param display Display of the smartphone
     * @param battery Battery of the smartphone
     * @param cpuAndRam CPU and RAM of the smartphone
     * @param storage Storage unit of the smartphone
     * @param camera Camera of the smartphone
     * @param phoneCase Phone case of the smartphone
     */
    public Smartphone(PhoneModel model, Display display, Battery battery, CPU_RAM cpuAndRam, Storage storage, Camera camera, Case phoneCase) {
        setModel(model);
        setBattery(battery);
        setCpuAndRam(cpuAndRam);
        setDisplay(display);
        setStorage(storage);
        setCamera(camera);
        setPhoneCase(phoneCase);
    }

    /**
     * Setter for the model
     * @param model Model of the smartphone
     */
    public void setModel(PhoneModel model) {
        this.model = model;
    }

    /**
     * Setter for the display
     * @param display Display of the smartphone
     */
    public void setDisplay(Display display) {
        this.display = display;
    }

    /**
     * Setter for the battery
     * @param battery Battery of the smartphone
     */
    public void setBattery(Battery battery) {
        this.battery = battery;
    }

    /**
     * Setter for the CPU and RAM
     * @param cpuAndRam CPU and RAM of the smartphone
     */
    public void setCpuAndRam(CPU_RAM cpuAndRam) {
        this.cpuAndRam = cpuAndRam;
    }

    /**
     * Setter for the storage unit
     * @param storage Storage unit of the smartphone
     */
    public void setStorage(Storage storage) {
        this.storage = storage;
    }

    /**
     * Setter for the camera
     * @param camera Camera of the smartphone
     */
    public void setCamera(Camera camera) {
        this.camera = camera;
    }

    /**
     * Setter for the phone case
     * @param phoneCase Phone case of the smartphone
     */
    public void setPhoneCase(Case phoneCase) {
        this.phoneCase = phoneCase;
    }
    /**
     * Returns a string representation of a Smartphone object
     * @return String representation of a Smartphone object
     */
    @Override
    public String toString() {
        return "Model = " + model.toString() + "\n"
                + display.toString() + "\n"
                + battery.toString() + "\n"
                + cpuAndRam.toString() + "\n"
                + storage.toString() + "\n"
                + camera.toString() + "\n"
                + phoneCase.toString() + "\n";
    }
}
