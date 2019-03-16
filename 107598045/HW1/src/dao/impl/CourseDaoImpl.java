package dao.impl;

import dao.CourseDao;
import dbconn.Dbcon;
import model.Course;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import static sun.nio.cs.Surrogate.MAX;

public class CourseDaoImpl implements CourseDao {

    private final Connection pcon = Dbcon.getConnection(Dbcon.SACMS);

    public CourseDaoImpl(){}

    @Override
    public int getMaxCourseId() throws SQLException {
        String sql = "SELECT MAX(courseId) FROM sacms.course_purpose";
        PreparedStatement preparedStatement = null;
        ResultSet resultSet = null;
        int MaxCourseId = 0;
        try{
            preparedStatement = pcon.prepareStatement(sql);
            resultSet = preparedStatement.executeQuery();
            resultSet.next();
            MaxCourseId = resultSet.getInt(1);
            return MaxCourseId;
        }catch (SQLException e) {
            e.printStackTrace();
        } finally {
            if (preparedStatement != null)
                preparedStatement.close();
        }
        return 0;
    }

    @Override
    public List<Course> getCourseList() throws SQLException {
        String sql = "SELECT * FROM sacms.course_purpose ORDER BY courseId";
        List<Course> courses = new ArrayList<Course>();
        PreparedStatement preparedStatement = null;
        ResultSet resultSet = null;
        try {
            preparedStatement = pcon.prepareStatement(sql);
            resultSet = preparedStatement.executeQuery();
            while (resultSet.next()) {
                Course course = new Course(
                        resultSet.getInt("courseId"),
                        resultSet.getString("courseName"),
                        resultSet.getString("courseDetail"),
                        resultSet.getString("courseSuitPeople"),
                        resultSet.getInt("coursePrice"),
                        resultSet.getString("courseNotes"),
                        resultSet.getString("courseRemark")
                );
                courses.add(course);
            }
            return courses;
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            if (preparedStatement != null) {
                preparedStatement.close();
            }
            if (resultSet != null) {
                resultSet.close();
            }
        }
        return null;
    }

    @Override
    public void insertCourseToDB(Course course) throws SQLException {
        String sql = "INSERT INTO sacms.course_purpose(courseId, courseName, courseDetail, courseSuitPeople, coursePrice, courseNotes, courseRemark) VALUES (?, ?, ?, ?, ?, ?, ?)";
        PreparedStatement preparedStatement = null;
        try {
            preparedStatement = pcon.prepareStatement(sql);
            int i = 1;
            preparedStatement.setInt(i++, course.getCourseId());
            preparedStatement.setString(i++, course.getCourseName());
            preparedStatement.setString(i++, course.getCourseDetail());
            preparedStatement.setString(i++, course.getCourseSuitPeople());
            preparedStatement.setInt(i++, course.getCoursePrice());
            preparedStatement.setString(i++, course.getCourseNotes());
            preparedStatement.setString(i++, course.getCourseRemark());
            preparedStatement.execute();
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            if (preparedStatement != null)
                preparedStatement.close();
        }
    }

    @Override
    public void deleteCourseToDB(int courseId) throws SQLException {
        String sql = "DELETE FROM sacms.course_purpose WHERE courseId = ?";
        PreparedStatement preparedStatement = null;
        try{
            preparedStatement = pcon.prepareStatement(sql);
            preparedStatement.setInt(1, courseId);
            preparedStatement.execute();
        } catch (SQLException e){
            e.printStackTrace();
        } finally {
            if(preparedStatement != null){
                preparedStatement.close();
            }
        }
    }

    @Override
    public Course findTheCourse(int courseId) throws SQLException {
        String sql = "SELECT * FROM sacms.course_purpose WHERE courseId = ?";
        PreparedStatement preparedStatement = null;
        ResultSet resultSet = null;
        Course TheCourse = null;
        try{
            preparedStatement = pcon.prepareStatement(sql);
            preparedStatement.setInt(1, courseId);
            resultSet = preparedStatement.executeQuery();
            while (resultSet.next()) {
                TheCourse = new Course(
                        resultSet.getInt("courseId"),
                        resultSet.getString("courseName"),
                        resultSet.getString("courseDetail"),
                        resultSet.getString("courseSuitPeople"),
                        resultSet.getInt("coursePrice"),
                        resultSet.getString("courseNotes"),
                        resultSet.getString("courseRemark")
                );
            }
            return TheCourse;
        } catch (SQLException e){
            e.printStackTrace();
        } finally {
            if(preparedStatement != null){
                preparedStatement.close();
            }
        }
        return null;
    }

    @Override
    public void editCourseToDB(Course course) throws SQLException {
        String sql = "UPDATE sacms.course_purpose SET courseName = ?, courseDetail = ?, courseSuitPeople = ?, coursePrice = ?, courseNotes = ?, courseRemark = ? WHERE courseId = ?";
        PreparedStatement preparedStatement = null;
        int i = 1;
        try {
            preparedStatement = pcon.prepareStatement(sql);
            preparedStatement.setString(i++, course.getCourseName());
            preparedStatement.setString(i++, course.getCourseDetail());
            preparedStatement.setString(i++, course.getCourseSuitPeople());
            preparedStatement.setInt(i++, course.getCoursePrice());
            preparedStatement.setString(i++, course.getCourseNotes());
            preparedStatement.setString(i++, course.getCourseRemark());

            preparedStatement.setInt(i++, course.getCourseId());
            preparedStatement.execute();
        } catch (SQLException e){
            e.printStackTrace();
        } finally {
            if(preparedStatement != null){
                preparedStatement.close();
            }
        }
    }

}
