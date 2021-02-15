package Q1.PhoneParts;

/**
 * Defines types of storage support.
 * @author Gokce Nur Erer
 */
public enum StorageSupport {
    MicroSD("MicroSD");

    private String typeName;
    StorageSupport(String name){
        this.typeName = name;
    }

    @Override
    public String toString() {
        return typeName;
    }
}
