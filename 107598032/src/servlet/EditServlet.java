package servlet;

import dao.CourseDao;
import model.Course;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.sql.SQLException;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@WebServlet("/Edit")
public class EditServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        CourseDao courseDao = new CourseDao();
        Map<Integer, Course> courseMap = new HashMap<>();
        Map<String, Integer> memberOption = new HashMap<>();
        String[] option = {"大一", "大二", "大三", "大四", "碩一", "碩二"};
        for(String str: option){
            memberOption.put(str, 0);
        }
        try {
            List<Course> courseList = courseDao.getCourseList();
            for(Course course : courseList){
                courseMap.put(course.getId(), course);
            }
            request.setAttribute("courseList", courseList);
        } catch (SQLException e) {
            e.printStackTrace();
        }
        if(request.getParameter("selectCourse") != null){
            int selectId = Integer.parseInt(request.getParameter("selectCourse"));
            request.setAttribute("selectCourse", courseMap.get(selectId));
            String[] memberString = courseMap.get(selectId).getMember().split("/");
            for(String member: memberString){
                if(memberOption.get(member) != null){
                    memberOption.put(member, 1);
                }
            }
            request.setAttribute("memberOption", memberOption);
            request.setAttribute("id", selectId);
        }
        request.getRequestDispatcher("/WEB-INF/jsp/edit.jsp").forward(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        request.setCharacterEncoding("UTF-8");
        int id = Integer.parseInt(request.getParameter("id"));
        String name = request.getParameter("name");
        String content = request.getParameter("content");
        String[] memberList = request.getParameterValues("member");
        String memberString = "";
        if(memberList != null && memberList.length > 1){
            for(int i = 0; i < memberList.length; i++){
                if(i != 0) memberString += "/";
                memberString += memberList[i];
            }
        }
        else if(memberList != null && memberList.length == 1){
            memberString = memberList[0];
        }
        String priceTemp = request.getParameter("price");
        int price = 0;
        if(priceTemp.length() > 0)
            price = Integer.parseInt(request.getParameter("price"));
        String notice = request.getParameter("notice");
        String remark = request.getParameter("remark");
        Course course = new Course(id, name, content, memberString, price, notice, remark);
        CourseDao courseDao = new CourseDao();
        try {
            courseDao.updateCourse(course);
        } catch (SQLException e) {
            e.printStackTrace();
        }
        response.sendRedirect("/Edit");
    }
}
