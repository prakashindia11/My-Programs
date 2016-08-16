import java.io.*;

public class ListDevices
{
	public static void main(String args[])
	{
		int counter = 0;
		String line;		

		try
		{
			Process p = (Process) Runtime.getRuntime().exec("lshw");

			BufferedReader br = new BufferedReader(new InputStreamReader(p.getInputStream()));

			while((line = br.readLine())!= null)
			{
				System.out.println(" "+line);

				counter++;
			}
		}
		catch(Exception e)
		{

		}

		br.close();
	}
}

