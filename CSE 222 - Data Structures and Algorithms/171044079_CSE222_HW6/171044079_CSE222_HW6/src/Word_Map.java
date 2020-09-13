import java.io.File;
import java.util.*;

public class Word_Map implements Map, Iterable
{

    final static int INITCAP=10;  //initial capacity
    int CURRCAP = INITCAP;   //current capacity
    final static float LOADFACT = 0.75f;
    private Node table[];
    private int size = 0 ;
    private int starting_Index = -1 ; //If list is empty the starting index would be -1
    private int last_Added;

    public Word_Map() {
        this.table = new Node[INITCAP];
    }
    public class Word_Map_Iterator implements Iterator<String>{
        private Node current;
        public Word_Map_Iterator(){
            if(starting_Index > -1){
                current = table[starting_Index];
            }
            else{
                throw new ArrayIndexOutOfBoundsException();
            }

        }

        public String getCurrent() {
            return current.key;
        }

        @Override
        public boolean hasNext() {
            return (current!=null);
        }

        @Override
        public String next() {
            if(hasNext()){
                Node temp = current;
                current=current.nextEntry;
                return temp.key;
            }
            else
                return null;
        }
    }
    @Override
    public Iterator iterator() {
        return new Word_Map_Iterator();
    }

    static class Node {
        // complete this class according to the given structure in homework definition
        private String key;
        private File_Map value;
        Node nextEntry;
        public Node(String key, File_Map value){
            this.key = key;
            this.value = value;
        }
        public Node(String key, File_Map value, Node nextEntry){
            this.key = key;
            this.value = value;
            this.nextEntry = nextEntry;
        }

        public String getKey() {
            return key;
        }

        public File_Map getValue() {
            return value;
        }
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return (size==0);
    }

    @Override
    /*Use linked structure instead of table index
    to perform search operation effectively
     * */
    public boolean containsKey(Object key) {
        if(!isEmpty()) {
            Word_Map_Iterator it = (Word_Map_Iterator) iterator();
            while (it.hasNext()) {
                if (it.getCurrent().equals(key)) {
                    return true;
                }
                it.next();
            }
            return false;
        }
        else
            return false;
    }

    @Override
    /*Use linked structure instead of table index
    to perform search operation effectively
     * */
    public boolean containsValue(Object value) {
        if(!isEmpty()) {
        Word_Map_Iterator it = (Word_Map_Iterator) iterator();
        while(it.hasNext()){
            if(get(it.getCurrent()).equals(value)){
                return true;
            }
            it.next();

        }
        return false;
        }
        else
            return false;
        
    }

    @Override
    public File_Map get(Object key) {
        for(int i = 0 ; i < table.length ; ++i){

            if(table[i]!= null && table[i].key.equals(key)){
                return table[i].value;
            }
        }
        return null;
    }

    @Override
    /*
    Use linear probing in case of collision
    * */
    public Object put(Object key, Object value)
    {
        int index = key.hashCode() % CURRCAP;
        if(index<0){
            index += CURRCAP;
        }

        if((int)(CURRCAP*LOADFACT) == size()){
            rehash();

        }
        if(size() == 0){
            starting_Index = index;
            last_Added = index;
            table[index] = new Node((String)key,(File_Map)value,null);

        }
        else{
            if(!containsKey(key)) {
                if(table[index] == null) {
                    table[index] = new Node((String) key, (File_Map) value, null);
                    table[last_Added].nextEntry = table[index];
                    last_Added = index;
                }
                else{
                    while (table[index] != null) {
                        if (index == table.length - 1)
                            index = 0;
                        else {
                            index++;
                        }
                    }
                    table[index] = new Node((String) key, (File_Map) value, null);
                    table[last_Added].nextEntry = table[index];
                    last_Added = index;

                }
            }
            else{
                for(int i = 0 ; i < table.length ; ++i){
                    if(table[i] != null && table[i].key.equals(key)){
                        table[i] = new Node((String) key, (File_Map) value, null);
                        table[last_Added].nextEntry = table[i];
                        last_Added = i;
                    }
                }

            }

        }

        size++;
        return table[last_Added].value;


    }

    @Override
    /*You do not need to implement remove function
    * */
    public Object remove(Object key) {
        return null;
    }
    @SuppressWarnings("unchecked")
    @Override
    public void putAll(Map m) {
        m.forEach((k,v) -> put(k,v));
    }

    @Override
    public void clear() {
        for(int i = 0 ; i < table.length ; ++i){
            table[i] = null;
        }
    }

    @Override
    /*Use linked structure instead of table index
    for efficiency
     * */
    public Set keySet() {
        Set<String> set = new HashSet<>();
        Word_Map.Word_Map_Iterator it =(Word_Map.Word_Map_Iterator) iterator();
        while(it.hasNext()){
            set.add(it.next());
        }
        return set;
    }

    @Override
    /*Use linked structure instead of table index
    for efficiency
     * */
    public ArrayList<File_Map> values() {
        ArrayList<File_Map> al = new ArrayList<>();
        Word_Map.Word_Map_Iterator it =(Word_Map.Word_Map_Iterator) iterator();
        while(it.hasNext()){
            al.add(get(it.next()));

        }
        return al;
    }

    @Override
    /*You do not need to implement entrySet function
     * */
    public Set<Entry> entrySet() {
        return null;
    }

    private void rehash(){
        Node[] old_Table = table;
        table = new Node[2 * old_Table.length + 1];
        CURRCAP = table.length;
        size = 0 ;
        starting_Index = -1 ; //If list is empty the starting index would be -1
        last_Added = -1;
        for(int i = 0 ; i<old_Table.length ;i++){
            if(old_Table[i] != null){
                put(old_Table[i].key,old_Table[i].value);
            }
        }
    }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();
        for(int i = 0 ; i < table.length ; i++){
            if(table[i]!= null)
                str.append("Word:").append(table[i].key).append("\n").append(table[i].value).append("\n");
            else
                str.append("empty\t\tempty\n\n");
        }
        return str.toString();
    }
}
