package dao;

import model.Course;

import java.sql.SQLException;
import java.util.List;

public interface CourseDao {
//    Account getAccountByRegNumber(String regNumber) throws SQLException;
    int getMaxCourseId() throws SQLException;
    List<Course> getCourseList() throws SQLException;
    void insertCourseToDB(Course course) throws SQLException;
    void deleteCourseToDB(int courseId) throws SQLException;
    Course findTheCourse(int courseId) throws SQLException;
    void editCourseToDB(Course course) throws SQLException;
}
