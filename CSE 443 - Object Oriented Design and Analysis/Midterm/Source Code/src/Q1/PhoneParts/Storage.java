package Q1.PhoneParts;

/**
 * This class represents a storage in a smartphone
 * @author Gokce Nur Erer
 */
public class Storage {
    /**
     * Storage support type of a storage unit
     */
    private StorageSupport storageSupport;
    /**
     * Capacity of a storage unit
     */
    private int capacity;
    /**
     * Maximum storage of a storage unit
     */
    private int maxStorage;

    /**
     * Consturctor of Storage
     * @param storageSupport Storage support type of the storage unit
     * @param capacity Capacity of the storage unit
     */
    public Storage(StorageSupport storageSupport, int capacity) {
        this.storageSupport = storageSupport;
        this.capacity = capacity;
    }

    /**
     * Setter for storage support type
     * @param storageSupport Storage support type of the storage unit
     */
    public void setStorageSupport(StorageSupport storageSupport) {
        this.storageSupport = storageSupport;
    }

    /**
     * Setter for storage capacity
     * @param capacity Capacity of the storage unit
     */
    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    /**
     * Setter for maximum storage capacity
     * @param maxStorage Maximum storage capacity of a storage unit
     */
    public void setMaxStorage(int maxStorage) {
        this.maxStorage = maxStorage;
    }

    /**
     * Returns a string representation of a Storage object
     * @return String representation of a Storage object
     */
    @Override
    public String toString() {
        return "Storage: Storage Support = " + storageSupport.toString() + " support , Capacity = " + capacity + "GB , Max Storage = " + maxStorage + "GB";

    }
}
