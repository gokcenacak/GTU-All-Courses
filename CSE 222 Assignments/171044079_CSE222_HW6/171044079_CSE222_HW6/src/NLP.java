import java.io.*;
import java.util.*;

public class NLP
{
    public Word_Map wmap;
    private int file_count;
    private String datasetDirectory;
    /*You should not use File_Map class in this file since only word hash map is aware of it.
    In fact, you can define the File_Map class as a nested class in Word_Map,
     but for easy evaluation we defined it separately.
     If you need to access the File_Map instances, write wrapper methods in Word_Map class.
    * */
    public NLP(){
        wmap = new Word_Map();
        file_count=0;
    }
    /*Reads the dataset from the given dir and created a word map */
    public void readDataset(String dir)
    {
        datasetDirectory = dir;
        File dataset = new File(dir);
        ArrayList<File> file = new ArrayList<>(Arrays.asList(dataset.listFiles()));
        for(int i = 0 ; i < file.size() ; ++i){
            if(file.get(i).isFile()){
                file_count++;
                int wordPos = 1;
                Scanner reader = new Scanner(System.in);
                try {
                     reader = new Scanner(file.get(i));
                }
                catch (FileNotFoundException e){
                        e.printStackTrace();
                }

                try {
                    while (reader.hasNextLine()) {
                        String line = reader.nextLine();
                        if(!line.isEmpty()){
                            Scanner scan = new Scanner(line);
                            while (scan.hasNext()) {
                                String word = scan.next().trim().replaceAll("\\p{Punct}", "");
                                if(!word.equals("")) {
                                    if (!wmap.containsKey(word)) {
                                        File_Map fmap = new File_Map();
                                        fmap.put(file.get(i).getName(), wordPos);
                                        wmap.put(word, fmap);
                                    } else {
                                        wmap.get(word).put(file.get(i).getName(), wordPos);
                                    }
                                    wordPos++;
                                }
                            }
                        }
                    }
                }
                catch(NullPointerException e){
                    e.printStackTrace();
                }

            }
        }
    }


    /*Finds all the bigrams starting with the given word*/
    public List<String> bigrams(String word){
        List<String> bigrams = new ArrayList<>();
        Set<File_Map.Entry> set;
        if(wmap.containsKey(word)) {
            set = wmap.get(word).entrySet();
            Iterator<File_Map.Entry> iter = set.iterator();


            while (iter.hasNext()) {
                File_Map.Entry next = iter.next();
                for (int i = 0; i < next.getValue().size(); i++) {
                    for (Word_Map.Word_Map_Iterator it = (Word_Map.Word_Map_Iterator) wmap.iterator(); it.hasNext(); ) {
                        String nextword = it.next();
                        Set<File_Map.Entry> set2 = wmap.get(nextword).entrySet();
                        Iterator<File_Map.Entry> iter2 = set2.iterator();
                        while (iter2.hasNext()) {
                            File_Map.Entry next2 = iter2.next();
                            for (int j = 0; j < next2.getValue().size(); j++) {
                                if ((next.getValue().get(i) + 1 == next2.getValue().get(j)) && next.getKey().equals(next2.getKey())) {
                                    StringBuilder str = new StringBuilder();
                                    str.append(word).append(" ").append(nextword);
                                    if(!bigrams.contains(str.toString()))
                                        bigrams.add(str.toString());
                                }
                            }
                        }
                    }
                }
            }
        }
        return bigrams;
    }



    /*Calculates the tfIDF value of the given word for the given file */
    public float tfIDF(String word, String fileName)
    {
        float count = 0f;
        float tf,idf;
        File file = new File(datasetDirectory + "\\" + fileName);
        Scanner scan = new Scanner(System.in);
        try {
            scan = new Scanner(file);
        }
        catch(FileNotFoundException e ){
            e.printStackTrace();
        }
        try {
            while (scan.hasNextLine()) {
                String line = scan.nextLine();
                if(!line.isEmpty()){
                    Scanner scan2 = new Scanner(line);
                    while (scan2.hasNext()) {
                        String readword = scan2.next().trim().replaceAll("\\p{Punct}", "");
                        if(!readword.equals("")) {
                            count++;
                        }
                    }
                }
            }
        }
        catch(NullPointerException e){
            e.printStackTrace();
        }

        tf = wmap.get(word).get(fileName).size()/count;
        idf = (float)Math.log((float)file_count/(float)wmap.get(word).values().size());


        return tf*idf;
    }

    /*Print the WordMap by using its iterator*/
    public  void printWordMap()
    {
        Word_Map.Word_Map_Iterator it = (Word_Map.Word_Map_Iterator)wmap.iterator();
        while(it.hasNext()){
            String next = it.next();
            System.out.println("Word:" + next + "\nMap:\n" + wmap.get(next));
        }
    }

}
