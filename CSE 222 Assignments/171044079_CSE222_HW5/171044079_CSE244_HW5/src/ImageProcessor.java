import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class ImageProcessor {
   private PriorityQueue LEXpq;
   private PriorityQueue EUCpq;
   private PriorityQueue BMXpq;
   private BufferedImage image;
   private Thread pixelProducer;
   private Thread LEXConsumer;
   private Thread EUCConsumer;
   private Thread BMXConsumer;

    /**Constructs an ImageProcessor with a given image path also creates 4 threads to produce the pixels and
     * consume them.
     * @param imagePath the path of the image
     */
   public ImageProcessor(String imagePath){
       LEXpq = new PriorityQueue(new LEXComparator());
       EUCpq = new PriorityQueue(new EUCComparator());
       BMXpq = new PriorityQueue(new BMXComparator());
       try {
           image = ImageIO.read(new File(imagePath));
       }
       catch(IOException e){
           e.printStackTrace();
       }
       pixelProducer = new Thread(new Runnable() {
           @Override
           public void run() {
                producePixels();
           }
       });
       LEXConsumer = new Thread(new Runnable() {
           @Override
           public void run() {
                consumeLEX();
           }
       });
       EUCConsumer = new Thread(new Runnable() {
           @Override
           public void run() {
                consumeEUC();
           }
       });
       BMXConsumer = new Thread(new Runnable() {
           @Override
           public void run() {
                consumeBMX();
           }
       });
       pixelProducer.start();
       try {
           pixelProducer.join();
           LEXConsumer.join();
           EUCConsumer.join();
           BMXConsumer.join();
       }
       catch (InterruptedException e){
           e.printStackTrace();
       }

   }
   private void producePixels(){
       int count = 0 ;
       for(int i = 0 ; i < image.getHeight() ; ++i){
           for(int j = 0 ; j < image.getWidth() ; ++j){
               int[] arr = new int[4];
               image.getData().getPixel(j,i,arr);
               Color tempColor = new Color(arr[0],arr[1],arr[2]);
               System.out.println("Thread 1 : " + tempColor);
               LEXpq.add(tempColor);
               EUCpq.add(tempColor);
               BMXpq.add(tempColor);
               count++;
               if(count == 100){
                   LEXConsumer.start();
                   EUCConsumer.start();
                   BMXConsumer.start();
               }
           }
       }
   }

   private void consumeLEX(){
       for (int i = 0; i < image.getWidth() * image.getHeight(); i++) {
           System.out.println("Thread2 - PQLEX : " + LEXpq.remove());
       }
   }
   private void consumeEUC(){
       for (int i = 0; i < image.getWidth() * image.getHeight(); i++) {
           System.out.println("Thread3 - PQEUC : " + EUCpq.remove());
       }
   }
   private void consumeBMX(){
       for (int i = 0; i < image.getWidth() * image.getHeight(); i++) {
           System.out.println("Thread4 - PQBMX : " + BMXpq.remove());
       }
   }



}
