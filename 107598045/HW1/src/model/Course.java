package model;

import java.sql.SQLException;
import java.util.Arrays;
import java.util.List;

public class Course implements Authenticate{
    private boolean exist;

    private int courseId;
    private String courseName;
    private String courseDetail;
    private String courseSuitPeople;
    private int coursePrice;
    private String courseNotes;
    private String courseRemark;

    public Course(int courseId, String courseName, String courseDetail, String courseSuitPeople, int coursePrice, String courseNotes, String courseRemark) {
        if (courseName.isEmpty()) {
            throw new IllegalArgumentException("課程名稱不能為空");
        }

        this.courseId = courseId;
        this.courseName = courseName;
        this.courseDetail = courseDetail;
        this.courseSuitPeople = courseSuitPeople;
        this.coursePrice = coursePrice;
        this.courseNotes = courseNotes;
        this.courseRemark = courseRemark;

        this.exist = true;
    }


    public boolean isExist() {
        return exist;
    }

    public int getCourseId(){return courseId;}

    public String getCourseName(){return courseName;}

    public String getCourseDetail(){return courseDetail;}

    public String getCourseSuitPeople(){return courseSuitPeople;}

    public int getCoursePrice(){return coursePrice;}

    public String getCourseNotes(){return courseNotes;}

    public String getCourseRemark(){return courseRemark;}
}
