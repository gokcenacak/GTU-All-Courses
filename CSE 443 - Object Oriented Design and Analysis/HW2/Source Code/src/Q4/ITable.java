package Q4;

public interface ITable {
    Object getElementAt(int row, int column);
    void setElementAt(int row, int column, Object o);
    int getNumberOfRows();
    int getNumberOfColumns();
}
