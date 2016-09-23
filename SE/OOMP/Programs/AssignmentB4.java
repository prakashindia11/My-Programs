Name : Prakash Iyer
Class : SE A
Roll No : 138

package Assignment4;
import java.util.*;

class student
{
	String name,subject;
	int rollno;
}

class studentinfo extends student
{
	int subcode,imarks,emarks;
	public static int count=0;
	
	Scanner in = new Scanner(System.in);
	
	void Accept()
	{
		System.out.println("Enter Name : ");
		name = in.next();
		
		System.out.println("Enter Subject : ");
		subject = in.next();
		
		System.out.println("Enter Roll No : ");
		rollno = in.nextInt();
		
		System.out.println("Enter Subject Code : ");
		subcode = in.nextInt();
		
		System.out.println("Enter Internal Marks : ");
		imarks = in.nextInt();
		
		System.out.println("Enter University Marks : ");
		emarks = in.nextInt();
		
		count++;
		
	}
	
	void Display()
	{
		System.out.println("\n");
		System.out.println("Name : "+name);
		System.out.println("Subject : "+subject);
		System.out.println("Roll No : "+rollno);
		System.out.println("Subject Code : "+subcode);
		System.out.println("Internal Marks : "+imarks);
		System.out.println("University Marks : "+emarks);
		System.out.println("Count : "+count);
	}
	
	int Delete(String sname,int srollno) throws Exception
	{
			int flag = 0;
		
			if(srollno==rollno && sname.equals(name))
			{			
				flag = 1;
			}
			
			if(flag == 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		
	}
	
	void Search(String sname,int srollno)
	{
		if(srollno == rollno && sname.equals(name))
		{
			System.out.println("\nDetails of Roll No : "+srollno+"\n");
			System.out.println("Name : "+name);
			System.out.println("Subject : "+subject);
			System.out.println("Roll No : "+rollno);
			System.out.println("Subject Code : "+subcode);
			System.out.println("Internal Marks : "+imarks);
			System.out.println("University Marks : "+emarks);
		}
	}
}


public class Assignment4 
{
	public static void main(String args[]) throws Exception
	{
		studentinfo s[] = new studentinfo[50];
		studentinfo del;
		int choice,c=1,i,srollno;
		boolean l=true;
		String sname;
		
		Scanner in = new Scanner(System.in);
		
		System.out.println("Select one of the following option : ");
		
		while(l==true)
		{
			System.out.println("\n1 Enter data \n2 Display Data \n3 Search Data \n4 Delete Data \n5 Exit");
			System.out.println("Enter your choice : ");
			choice = in.nextInt();
			
			switch(choice)
			{
			case 1 : 
				s[c] = new studentinfo();
				s[c].Accept();
				c++;
				break;
				
			case 2 :
				for(i=1;i<c;i++)
				{
					s[i].Display();
				}
				break;
				
			case 3 :
				System.out.println("Enter the name to be searched : ");
				sname = in.next();
				System.out.println("Enter the Roll Number :  ");
				srollno = in.nextInt();
				
				for(i=1;i<c;i++)
				{
					s[i].Search(sname,srollno);
				}
				
				break;
				
			case 4 : 
				int d;
				System.out.println("Enter the name to be deleted : ");
				sname = in.next();
				System.out.println("Enter the Roll Number :  ");
				srollno = in.nextInt();
			
				for(i=1;i<c;i++)
				{
					d = s[i].Delete(sname,srollno);
					
					if(d==1)
					{
						for(int j=i;j<c;j++)
						{
							s[j] = s[j+1];
						}
						
						break;
					}
				}
				
				break;
				
			case 5 :
				l = false;			
			}
		}
	}
}