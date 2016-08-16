import java.io.*;

public class CountUsers
{
	public static void main(String args[])
	{
		int counter = 0;
		String line;

		try
		{
			Process p = (Process) Runtime.getRuntime().exec("who");

			BufferedReader br = new BufferedReader(new InputStreamReader(p.getInputStream()));

			while((line = br.readLine()) != null)
			{
				System.out.println(" "+line);
				counter++;
			}

			System.out.println("Number of logged in users : "+counter);
		}
		catch(Exception e)
		{

		}

		br.close();
	}
}

