package Q2;

/**
 * This interface represents a Iterator
 * @author Gökçe Nur Erer
 */
public interface Iterator{
    /**
     * Checks if the iterator has a next element to visit in the data
     * @return If there is still unvisited data left, true; else false
     */
    boolean hasNext();
    /**
     * Changes the position of the iterator to the next element
     */
    void next();
    /**
     * Returns the element currently pointed by the iterator
     * @return The element currently pointed by the iterator
     */
    Object getCurrent();
}
