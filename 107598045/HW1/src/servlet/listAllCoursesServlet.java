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
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

/**
 * Created by David on 2019 / 02 / 23.
 */
@WebServlet("/listAllCourses")
public class listAllCoursesServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
//        request.getRequestDispatcher("/WEB-INF/jsp/listAllCourses.jsp").forward(request, response);
//        doPost(request, response);
        //22 23 24小考
        CourseDao coursedao = new CourseDaoImpl();
        try {
            List<Course> courseList = coursedao.getCourseList();
            request.setAttribute("courseList", courseList);
        } catch (SQLException e) {
            e.printStackTrace();
        }

        //以下讀取當前時間
        SimpleDateFormat sdFormat = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss");
        Date date = new Date();
        String strDate = sdFormat.format(date);
        System.out.println(strDate);

        request.getRequestDispatcher("/WEB-INF/jsp/listAllCourses.jsp").forward(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        request.setCharacterEncoding("UTF-8");
        HttpSession session = request.getSession();
//        String editId1 = request.getParameter("editId1");
//        System.out.println("test = " + editId1);
        CourseDao coursedao = new CourseDaoImpl();
        try {
            List<Course> courseList = coursedao.getCourseList();
            request.setAttribute("courseList", courseList);
//            System.out.println("tset = " + coursedao.getCourseList().get(0).getCourseDetail().toString());
        } catch (SQLException e) {
            e.printStackTrace();
        }
        request.getRequestDispatcher("/WEB-INF/jsp/listAllCourses.jsp").forward(request, response);
    }
}
