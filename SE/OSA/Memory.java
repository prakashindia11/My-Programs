import java.io.*;

public class Memory
{
	public static void main(String args[])
	{
		System.out.println("Total Memory : "+Runtime.getRuntime().totalMemory()/(1024*1024)+" MB");	
	}
}

