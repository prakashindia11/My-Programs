import java.io.*;

public class ProcessList
{
	public static void main(String args[])
	{
		String line;
		
		try
		{
			Process p = (Process) Runtime.getRuntime().exec("ps - axl");

			BufferedReader br = new BufferedReader(new InputStreamReader(p.getInputStream()));

			while((line = br.readLine())!= null)
			{
				System.out.println(line);
			}
		}
		catch(Exception e)
		{

		}

		br.close();
	}
}

