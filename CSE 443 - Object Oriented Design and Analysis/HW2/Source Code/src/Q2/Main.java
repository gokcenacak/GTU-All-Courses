package Q2;

import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        ArrayList<int [][]> arrayList = new ArrayList<>();
        int [][] array1 = {{1,2,3},{4,5,6},{7,8,9}};
        int [][] array2 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
        int [][] array3 = {{1,2,3,4,5}};
        int [][] array4 = {{1,2,3,4,5},{6,7,8,9,10}};
        int [][] array5 = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}};
        int [][] array6 = {{1,2},{3,4},{5,6},{7,8}};
        int [][] array7 = {{1,2},{3,4}};
        arrayList.add(array1);
        arrayList.add(array2);
        arrayList.add(array3);
        arrayList.add(array4);
        arrayList.add(array5);
        arrayList.add(array6);
        arrayList.add(array7);

        for(int [][] array : arrayList){
            String arrayStr = Arrays.deepToString(array);
            System.out.println("Example array:");
            for (int[] ints : array) {
                for (int j = 0; j < array[0].length; j++) {
                    System.out.print(ints[j] + " ");
                }
                System.out.println();
            }

            StringBuilder resStr = new StringBuilder();
            Iterable sd = new SatelliteData(array);
            for(Iterator i = sd.iterator(); i.hasNext(); i.next()){
                resStr.append(i.getCurrent()).append(" ");
            }
            System.out.println("Result : " + resStr);

        }

    }
}
