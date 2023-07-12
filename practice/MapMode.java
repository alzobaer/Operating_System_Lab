import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.MappedByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.channels.FileLock;

public class Writer {
    public static void main(String[] args) throws IOException {
        // Create a file object
        File file = new File("shared_memory.bin");

        // Open the file for reading and writing
        RandomAccessFile raf = new RandomAccessFile(file, "rw");

        // Map the file into memory
        MappedByteBuffer buffer = raf.getChannel().map(FileChannel.MapMode.READ_WRITE, 0, 1024);

        // Obtain an exclusive lock on the buffer
        FileLock lock = raf.getChannel().lock();

        // Write data to the buffer
        buffer.put("Hello, Shared Memory!".getBytes());

        // Release the lock
        lock.release();

        // Close the RandomAccessFile
        raf.close();
    }
}
