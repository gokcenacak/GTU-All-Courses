import java.io.File;
import java.util.*;

public class File_Map implements Map
{
    /*
    For this hashmap, you will use arraylists which will provide easy but costly implementation.
    Your should provide and explain the complexities for each method in your report.
    * */

    ArrayList<String> fnames;
    ArrayList<List<Integer>> occurances;
   public File_Map(){
       fnames = new ArrayList<>();
       occurances = new ArrayList<>();
   }
    public File_Map(ArrayList<String> file_names , ArrayList<List<Integer>> occurences){
        this.fnames = file_names;
        this.occurances = occurences;
    }
    @Override
    public int size() {
        return fnames.size();
    }

    @Override
    public boolean isEmpty() {
        return (fnames.size()==0);
    }

    @Override
    public boolean containsKey(Object key) {
        int index = fnames.indexOf(key.toString());
        return index != -1;
    }

    @Override
    public boolean containsValue(Object value) {
       if(!isEmpty()) {
           for (int i = 0; i < occurances.size(); i++) {
               for (int j = 0; j < occurances.get(i).size(); j++)
                   if (occurances.get(i).get(j) == value)
                       return true;
           }
           return false;
       }
       else
           return false;
    }

    @Override
    public List<Integer> get(Object key) {
        int index = fnames.indexOf(key.toString());
        if(index != -1)
            return occurances.get(index);
        else
            return null;
    }

    @Override
    /*Each put operation will extend the occurance list*/
    public Object put(Object key, Object value) {
        //Arraylist containing the key
       int index = fnames.indexOf(key.toString());
        if(index != -1){
            if(get(key).indexOf((int)value) == -1)
                get(key).add((int)value);
        }
        else{
            fnames.add((String)key);
            List<Integer> list = new ArrayList<>();
            list.add((int)value);
            occurances.add(list);
        }
        return value;
    }

    @Override
    public Object remove(Object key) {
        if(containsKey(key)){
            List<Integer> list = get(key);
            occurances.remove(fnames.indexOf(key.toString()));
            fnames.remove(key.toString());
            return list;
        }
        return null;
    }
    @SuppressWarnings("unchecked")

    @Override
    public void putAll(Map m) {
       Set<String> set = m.keySet();
       for(Iterator it = set.iterator() ; it.hasNext() ;){
           String key = it.next().toString();
           for(int i = 0 ; i < ((List<Integer>)(m).get(key)).size() ; i++){
               put(key,((List<Integer>) (m).get(key)).get(i));
           }
       }
    }

    @Override
    public void clear() {
        fnames.clear();
        occurances.clear();
    }

    @Override
    public Set keySet() {
        Set<String> keyset = new HashSet<>(fnames);
        return keyset;
    }

    @Override
    public ArrayList<List<Integer>> values() {
        return occurances;
    }
    public class Entry implements Map.Entry {
        private String key;
        private List<Integer> value;
        public Entry(String k , List<Integer> v) {
            this.key = k;
            this.value = v;
        }

        @Override
        public String getKey() {
            return key;
        }

        @Override
        public List<Integer> getValue() {
            return value;
        }
        @SuppressWarnings("unchecked")
        @Override
        public List<Integer> setValue(Object value) {
            List<Integer> old = this.value;
            this.value = (List<Integer>)value;
            return old;
        }
    }
    @Override
    public Set<Entry> entrySet() {
        Set<Entry> set = new HashSet<>();
        for(int i = 0 ; i < fnames.size() ; i++){
            set.add(new Entry(fnames.get(i),occurances.get(i)));
        }

        return set;
    }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();
        for(int i = 0 ; i < fnames.size() ; i++){
            str.append("\n").append(fnames.get(i));
            str.append("\t\t");
            str.append(occurances.get(i));
            str.append("\n");
        }
        return str.toString();
    }
}
