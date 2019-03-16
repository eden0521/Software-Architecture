package servlet;

import dao.CourseDao;
import dao.impl.CourseDaoImpl;
import model.Course;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.sql.SQLException;
import java.util.List;

/**
 * Created by David on 2019 / 03 / 01.
 */
@WebServlet("/deleteCourses")
public class deleteCoursesServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        CourseDao coursedao = new CourseDaoImpl();
        try {
            List<Course> courseList = coursedao.getCourseList();
            request.setAttribute("courseList", courseList);
        } catch (SQLException e) {
            e.printStackTrace();
        }
        request.getRequestDispatcher("/WEB-INF/jsp/deleteCourses.jsp").forward(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        request.setCharacterEncoding("UTF-8");
        HttpSession session = request.getSession();

        CourseDao coursedao = new CourseDaoImpl();
        String[] deleteCourseId = request.getParameterValues("deleteId");
        if(deleteCourseId != null){
            for(String courseid: deleteCourseId) {
                try {
                    coursedao.deleteCourseToDB(Integer.parseInt(courseid));
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
        }
        response.sendRedirect("listAllCourses"); //使用這個方會跑doGet
//        request.getRequestDispatcher("/WEB-INF/jsp/deleteCourses.jsp").forward(request, response);
//        request.getRequestDispatcher("/WEB-INF/jsp/listAllCourses.jsp").forward(request, response); //新增完跳回課程列表
    }
}
