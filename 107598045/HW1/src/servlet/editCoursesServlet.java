package servlet;

import dao.CourseDao;
import dao.impl.CourseDaoImpl;
import model.Course;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;
import java.util.List;

/**
 * Created by David on 2019 / 03 / 01.
 */
@WebServlet("/editCourses")
public class editCoursesServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        System.out.println("333t = " );
        String i  = request.getParameter("id");
        request.setAttribute("idd", i);
        CourseDao coursedao = new CourseDaoImpl();
        try {
            Course TheCourse = coursedao.findTheCourse(Integer.parseInt(i));
            request.setAttribute("course_id", TheCourse.getCourseId());
            request.setAttribute("course_name", TheCourse.getCourseName());
            request.setAttribute("course_detail", TheCourse.getCourseDetail());
            request.setAttribute("course_suit_people", TheCourse.getCourseSuitPeople());
            request.setAttribute("course_price", TheCourse.getCoursePrice());
            request.setAttribute("course_notes", TheCourse.getCourseNotes());
            request.setAttribute("course_remark", TheCourse.getCourseRemark());
        } catch (SQLException e) {
            e.printStackTrace();
        }
        request.getRequestDispatcher("/WEB-INF/jsp/editCourses.jsp").forward(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        request.setCharacterEncoding("UTF-8");
        System.out.println("333t = " );

        String course_id = request.getParameter("course_id");
        String course_name = request.getParameter("course_name");
        String course_detail = request.getParameter("course_detail");
        String course_suit_people = request.getParameter("course_suit_people");
        String course_price = request.getParameter("course_price");
        String course_notes = request.getParameter("course_notes");
        String course_remark = request.getParameter("course_remark");

        Course editcourse = null;
        try {
            editcourse = new Course(Integer.parseInt(course_id), course_name, course_detail, course_suit_people, Integer.parseInt(course_price), course_notes, course_remark);
            CourseDao courseDao = new CourseDaoImpl();
            courseDao.editCourseToDB(editcourse);
        } catch (SQLException e) {
            e.printStackTrace();
        }

        response.sendRedirect("/listAllCourses"); //使用這個方會跑doGet
//        request.getRequestDispatcher("/WEB-INF/jsp/editCourses.jsp").forward(request, response);
//        request.getRequestDispatcher("/WEB-INF/jsp/listAllCourses.jsp").forward(request, response); //新增完跳回課程列表
    }
}
