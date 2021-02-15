package Q1.PhoneParts;

/**
 * This class represents the CPU and the RAM of a smartphone
 * @author Gokce Nur Erer
 */
public class CPU_RAM {
    /**
     * Spped of the CPU
     */
    private double CPUSpeed;
    /**
     * Capacity of the RAM
     */
    private int RAMCapacity;
    /**
     * Counts of cores in CPU
     */
    private int cores;

    /**
     * Constructor for CPU_RAM
     * @param CPUSpeed Speed of the CPU
     * @param RAMCapacity Capacity of the RAM
     */
    public CPU_RAM(double CPUSpeed, int RAMCapacity){
        this.CPUSpeed = CPUSpeed;
        this.RAMCapacity = RAMCapacity;
    }

    /**
     * Setter for CPU speed
     * @param CPUSpeed Speed of the CPU
     */
    public void setCPUSpeed(double CPUSpeed) {
        this.CPUSpeed = CPUSpeed;
    }

    /**
     * Setter for RAM capacity
     * @param RAMCapacity Capacity of the RAM
     */
    public void setRAMCapacity(int RAMCapacity) {
        this.RAMCapacity = RAMCapacity;
    }

    /**
     * Setter for CPU core count
     * @param cores Core count of the CPU
     */
    public void setCores(int cores) {
        this.cores = cores;
    }
    /**
     * Returns a string representation of a CPU_RAM object
     * @return String representation of a CPU_RAM object
     */
    @Override
    public String toString() {
        return "CPU & RAM: CPU Speed = " + CPUSpeed + "GHz , RAMCapacity = " + RAMCapacity + "GB , Cores = " + cores + " cores";

    }
}
