import java.nio.ByteBuffer;
import java.nio.IntBuffer;
import java.nio.channels.FileChannel;
import java.io.RandomAccessFile;
import java.io.IOException;
import java.nio.MappedByteBuffer;

public class p1 {
    public static void main(String[] args) {
        try {
            // Create a file object
            java.io.File file = new java.io.File("shmfile");

            // Open the file for reading and writing
            RandomAccessFile raf = new RandomAccessFile(file, "rw");

            // Map the file into memory
            MappedByteBuffer buffer = raf.getChannel().map(FileChannel.MapMode.READ_WRITE, 0, 1024);

            // Create a ByteBuffer from the MappedByteBuffer
            ByteBuffer bb = buffer.slice();

            // Create an IntBuffer from the ByteBuffer
            IntBuffer ib = bb.asIntBuffer();

            // Read data from the buffer
            System.out.print("Write Data: ");
            String str = System.console().readLine();
            byte[] strBytes = str.getBytes();
            buffer.put(strBytes);

            // Print the data
            System.out.println("Data written in memory: " + new String(strBytes));

            // Close the RandomAccessFile
            raf.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
