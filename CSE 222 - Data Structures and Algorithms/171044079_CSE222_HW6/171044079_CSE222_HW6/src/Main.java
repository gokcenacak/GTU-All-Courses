import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("To see the method results of File_Map and Word_Map please enter 0");
        System.out.println("To see the method results of NLP please enter 1");
        int choice = s.nextInt();
        if(choice == 0){
            testingOfAllMethods();
        }
        if(choice == 1){
            NLP nlp = new NLP();
            nlp.readDataset("dataset");
            File file = new File("input.txt");
            Scanner scan = new Scanner(System.in);
            try{
                scan = new Scanner(file);
            }
            catch(FileNotFoundException e){
                e.printStackTrace();
            }
            while(scan.hasNextLine()){
                String str = scan.nextLine();
                String[] strarr = str.split(" ");
                if(strarr[0].equals("bigram")){
                    System.out.println("Calculating bigrams...");
                    List<String> list = nlp.bigrams(strarr[1]);
                    System.out.println(list);
                }
                else if(strarr[0].equals("tfidf")){
                    System.out.println("Calculating TFIDF...");
                    System.out.println(nlp.tfIDF(strarr[1],strarr[2]));
                }
            }
            System.out.println("To see the result of the printWordMap() please enter 0, to continue press 1:");
            choice =Integer.parseInt(s.next());
            if(choice == 0) {
                nlp.printWordMap();
                System.out.println("Size of the word map in NLP:" + nlp.wmap.size());
            }
            else if(choice == 1){
                System.out.println("Size of the word map in NLP:"  + nlp.wmap.size());
            }
        }
    }

    public static void testingOfAllMethods(){
        Word_Map wm = new Word_Map();
        File_Map fm = new File_Map();
        File_Map fm1 = new File_Map();
        File_Map fm2 = new File_Map();
        fm2.put("file200",0);
        System.out.println("Created file maps...");
        fm.put("file1",5);
        fm.put("file1",6);
        fm.put("file2",8);
        fm.put("file3",20);

        fm1.put("file4",4);
        fm1.put("file5",14);
        fm1.put("file6",82);
        fm1.put("file7",220);
        System.out.println("FOR FILE MAP FM:\nFile name\tList");
        System.out.println(fm);
        System.out.println("FOR FILE MAP FM1:\nFile name\tList");
        System.out.println(fm1);

        System.out.println("TESTS FOR FILE MAP\nAll testing will be shown on fm file map");
        System.out.println("Size:" + fm.size());
        System.out.println("isEmpty:" + fm.isEmpty());
        System.out.println("containsKey(file1):" + fm.containsKey("file1"));
        System.out.println("containsKey(doesNotExist):" + fm.containsKey("doesNotExist"));
        System.out.println("containsValue(5):" + fm.containsValue(5));
        System.out.println("containsValue(99999):" + fm.containsValue(99999));
        System.out.println("get(file1):" + fm.get("file1"));
        System.out.println("put method is tested during adding the elements in to the file map");
        fm.putAll(fm1);
        System.out.println("putAll(fm1):\n" + fm);
        System.out.println("keySet():" + fm.keySet());
        System.out.println("values():" + fm.values());
        System.out.println("entrySet():\nKey\t\tValue");
        Set<File_Map.Entry> entrySet = fm.entrySet();
        Iterator<File_Map.Entry> it = entrySet.iterator();
        while(it.hasNext()){
            File_Map.Entry next = it.next();
            System.out.println(next.getKey() + "\t\t" + next.getValue());
        }
        fm.remove("file1");
        System.out.println("\nremove():\n" + fm);
        fm.clear();
        System.out.println("clear():" + fm);

        System.out.println("\nTESTS FOR WORD MAP\nAll testing will be shown on wm word map");

        wm.put("word1",fm);
        wm.put("word2",fm1);
        wm.put("word3",fm);
        wm.put("word1",fm1);
        wm.put("word4",fm1);
        wm.put("word5",fm1);
        wm.put("word6",fm1);
        wm.put("word7",fm1);
        wm.put("word8",fm1);
        wm.put("word9",fm1);

        System.out.println("FOR WORD MAP WM:");
        System.out.println(wm);

        System.out.println("Size:" + wm.size());
        System.out.println("isEmpty:" + wm.isEmpty());
        System.out.println("containsKey(word1):" + wm.containsKey("word1"));
        System.out.println("containsKey(doesNotExist):" + wm.containsKey("doesNotExist"));
        System.out.println("containsValue(fm1):" + wm.containsValue(fm1));
        System.out.println("containsValue(fm2):" + wm.containsValue(fm2));
        System.out.println("get(word1):\n" + wm.get("word1"));
        System.out.println("put method is tested during adding the elements in to the word map");
        wm.putAll(fm);
        System.out.println("putAll(fm):\n" + wm);
        System.out.println("keySet():" + wm.keySet());
        System.out.println("values():\n" + wm.values());
        wm.clear();
        System.out.println("clear():\n" + wm);
    }
}
