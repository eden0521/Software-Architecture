package dao;

import dbconn.DbConn;
import model.Course;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class CourseDao {
    private final Connection pcon = DbConn.getConnection(DbConn.COURSE);

    public List<Course> getCourseList() throws SQLException {
        List<Course> courseList = new ArrayList<>();
        String sql = "SELECT * FROM course_system";
        PreparedStatement preparedStatement = null;
        ResultSet resultSet = null;
        try {
            preparedStatement = pcon.prepareStatement(sql);
            resultSet = preparedStatement.executeQuery();
            while (resultSet.next()) {
                Course course = new Course(
                        resultSet.getInt("id"),
                        resultSet.getString("name"),
                        resultSet.getString("content"),
                        resultSet.getString("member"),
                        resultSet.getInt("price"),
                        resultSet.getString("notice"),
                        resultSet.getString("remark")
                );
                courseList.add(course);
            }
            return courseList;
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

    public void insertCourse(Course course) throws SQLException {
        String sql = "INSERT INTO course_system (name, content, member, price, notice, remark) VALUES (?, ?, ?, ?, ?, ?)";
        PreparedStatement preparedStatement = null;
        int i = 1;
        try {
            preparedStatement = pcon.prepareStatement(sql);
            preparedStatement.setString(i++, course.getName());
            preparedStatement.setString(i++, course.getContent());
            preparedStatement.setString(i++, course.getMember());
            preparedStatement.setInt(i++, course.getPrice());
            preparedStatement.setString(i++, course.getNotice());
            preparedStatement.setString(i++, course.getRemark());
            preparedStatement.execute();
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            if (preparedStatement != null) {
                preparedStatement.close();
            }
        }
    }

    public void deleteCourse(int id) throws SQLException {
        String sql = "DELETE FROM course_system WHERE id = ?";
        PreparedStatement preparedStatement = null;
        try{
            preparedStatement = pcon.prepareStatement(sql);
            preparedStatement.setInt(1, id);
            preparedStatement.execute();
        } catch (SQLException e){
            e.printStackTrace();
        } finally {
            if(preparedStatement != null){
                preparedStatement.close();
            }
        }
    }

    public void updateCourse(Course course) throws SQLException {
        String sql = "UPDATE course_system SET name = ?, content = ?, member = ?, price = ?, notice = ?, remark = ? WHERE id = ?";
        PreparedStatement preparedStatement = null;
        int i = 1;
        try{
            preparedStatement = pcon.prepareStatement(sql);
            preparedStatement.setString(i++, course.getName());
            preparedStatement.setString(i++, course.getContent());
            preparedStatement.setString(i++, course.getMember());
            preparedStatement.setInt(i++, course.getPrice());
            preparedStatement.setString(i++, course.getNotice());
            preparedStatement.setString(i++, course.getRemark());
            preparedStatement.setInt(i++, course.getId());
            preparedStatement.execute();
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            if(preparedStatement != null){
                preparedStatement.close();
            }
        }
    }
}
