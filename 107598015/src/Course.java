public class Course 
{
	private String courseId;
	private String courseName;
	private String courseDescription;
	private String applicableObject;
	private String price;
	private String precautions;
	private String remark;
	
	public String getCourseId() 
	{
		return courseId;
	}
	
	public void setCourseId(String courseId) 
	{
		this.courseId = courseId;
	}
	public String getCourseName() 
	{
		return courseName;
	}
	
	public void setCourseName(String courseName) 
	{
		this.courseName = courseName;
	}
	
	public String getCourseDescription() 
	{
		return courseDescription;
	}
	
	public void setCourseDescription(String courseDescription)
	{
		this.courseDescription = courseDescription;
	}
	
	public String getApplicableObject()
	{
		return applicableObject;
	}
	
	public void setApplicableObject(String applicableObject) 
	{
		this.applicableObject = applicableObject;
	}
	
	public String getPrice() 
	{
		return price;
	}
	
	public void setPrice(String price) 
	{
		this.price = price;
	}
	
	public String getPrecautions() 
	{
		return precautions;
	}
	
	public void setPrecautions(String precautions)
	{
		this.precautions = precautions;
	}
	
	public String getRemark()
	{
		return remark;
	}
	
	public void setRemark(String remark)
	{
		this.remark = remark;
	}
}
