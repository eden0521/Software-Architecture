import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class DataControler {
	static Course[] c;
	static int totalCourseNum;
	static Scanner Keyin;
	JFrame f = null;


	DataControler() throws IOException
	{
		String inData;
		String file_R="1.txt";
		File fileID=new File(file_R);
		
		c=new Course[50];
		totalCourseNum=0;
		if(fileID.exists())
		{
			BufferedReader data=new BufferedReader(new FileReader(fileID));
			while((inData=data.readLine())!=null)
			{
				Scanner s=new Scanner(inData).useDelimiter(",");
				c[totalCourseNum]=new Course();
				c[totalCourseNum].setCourseId(s.next());
				c[totalCourseNum].setCourseName(s.next());
				c[totalCourseNum].setCourseDescription(s.next());
				c[totalCourseNum].setApplicableObject(s.next());
				c[totalCourseNum].setPrice(s.next());
				c[totalCourseNum].setPrecautions(s.next());
				c[totalCourseNum].setRemark(s.next());
				totalCourseNum++;
			}
			data.close();
		}
		else 
		{
			System.out.print("nothing mach file");
		}
	}
	
	void delete_data(String courseID) throws IOException
	{
		int courseNum=0;
		boolean isExistClass = false;
		while(courseNum<totalCourseNum)
		{
			
			if(courseID.equals(c[courseNum].getCourseId()))
			{
				isExistClass=true;
				break;
			}
			courseNum++;
		}
		if(isExistClass==false)
		{
			return ;
		}

		for(int i=courseNum;i<totalCourseNum;i++)
		{
			c[i]=c[i+1];
		}
		totalCourseNum--;
		save_data();
		
		
	
	}
	public void save_data() throws IOException
	{
		String file_R="1.txt";
		BufferedWriter outData=new BufferedWriter(new FileWriter(file_R));
		Keyin=new Scanner(System.in);
	
		for(int i=0;i<totalCourseNum;i++)
		{
			c[i].setCourseId(Integer.toString(i));
			outData.write(c[i].getCourseId()+',');
			outData.write(c[i].getCourseName()+',');
			outData.write(c[i].getCourseDescription()+',');
			outData.write(c[i].getApplicableObject()+',');
			outData.write(c[i].getPrice()+',');
			outData.write(c[i].getPrecautions()+',');
			outData.write(c[i].getRemark()+'\n');
		}
		outData.close();
	}
	
	public void modify_data(String courseID,String courseDescription,String applicableObject,String price,String precautions,String remark) throws IOException
	{
		int num=0;
		boolean isExistClass = false;
		System.out.print(courseID);
		while(num<totalCourseNum)
		{
			
			if(courseID.equals(c[num].getCourseId()))
			{
				isExistClass=true;
				break;
			}
			num++;
		}
		c[num].setCourseDescription(courseDescription);
		c[num].setApplicableObject(applicableObject);
		c[num].setPrice(price);
		c[num].setPrecautions(precautions);
		c[num].setRemark(remark);	
		save_data();

	}
	public void add_data(String courseName,String courseDescription,String applicableObject,String price,String precautions,String remark) throws IOException
	{
		
		c[totalCourseNum]=new Course();
		System.out.print(c[totalCourseNum].getCourseId());
		if(courseName.equals(""))
		{
			JOptionPane.showMessageDialog(f,"不可為空！！！", "錯誤", JOptionPane.ERROR_MESSAGE);
		}
		else
		{
			c[totalCourseNum].setCourseName(courseName);
		}
		
		if(courseDescription.equals(""))
		{
			c[totalCourseNum].setCourseDescription("NULL");
		}
		else
		{
			c[totalCourseNum].setCourseDescription(courseDescription);
		}
		
		if(applicableObject.equals(""))
		{
			c[totalCourseNum].setApplicableObject("NULL");
		}
		else
		{
			c[totalCourseNum].setApplicableObject(applicableObject);
		}
		
		if(price.equals(""))
		{
			c[totalCourseNum].setPrice("NULL");
		}
		else
		{
			c[totalCourseNum].setPrice(price);
		}
		
		if(precautions.equals(""))
		{
			c[totalCourseNum].setPrecautions("NULL");
		}
		else
		{
			c[totalCourseNum].setPrecautions(precautions);
		}
		if(remark.equals(""))
		{
			c[totalCourseNum].setRemark("NULL");
		}
		else
		{
			c[totalCourseNum].setRemark(remark);
		}
		if(!courseName.equals(""))
		{
			totalCourseNum++;
			save_data();
		}
	}
	
		
		
}
