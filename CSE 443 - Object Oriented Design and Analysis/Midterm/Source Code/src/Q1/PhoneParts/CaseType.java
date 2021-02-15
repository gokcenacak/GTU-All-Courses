package Q1.PhoneParts;

/**
 * Defines type of cases.
 * @author Gokce Nur Erer
 */
public enum CaseType {
    Aluminum("Aluminum"),
    Plastic("Plastic");
    private String typeName;
    CaseType(String name){
        this.typeName = name;
    }

    @Override
    public String toString() {
        return typeName;
    }
}
