import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Project5 {
	public static void main(String[] args) {
		try {
			Scanner inFile = new Scanner(new FileReader(args[0]));
			PrintWriter outFile1 = new PrintWriter(args[1]);
			PrintWriter outFile2 = new PrintWriter(args[2]);
			
			PrimMST mst = new PrimMST();
			mst.PrimsMST(inFile, outFile1, outFile2);
			
			inFile.close();
			outFile1.close();
			outFile2.close();
		}
	
		catch (Exception e) {
			System.out.println(e);
		}
	}
}