<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<%--
  Created by IntelliJ IDEA.
  User: WHM
  Date: 2019/3/1
  Time: 上午 11:32
  To change this template InsertCourseUseCase File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>刪除課程</title>

    <link href="https://cdn.jsdelivr.net/npm/semantic-ui@2.4.2/dist/semantic.min.css" rel="stylesheet" type="text/css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/semantic-ui@2.4.2/dist/semantic.min.js"></script>
</head>
<body>
<br>
<button class="large ui inverted violet button" onclick="location.href = '/listAllCourses'">返回課程列表</button>
<br><br>
<div class="ui grid" align="center">    <%--使用網格方式來排版頁面 semantic-ui 把螢幕切為16等分--%>
    <div class="three wide column"></div>    <%--先塞四等分空的 已把後面內容擠到中間去--%>
    <div class="ten wide column">
        <form name="" action="deleteCourses" method="POST">
            <table class="ui center aligned two pink table" border="2" >
                <tr class="text-center">
                    <th><font size="4">選擇欲刪除課程</font></th>
                    <th><font size="4">課程名稱</font></th>
                    <th><font size="4">適合對象</font></th>
                </tr>
                <c:forEach items="${courseList}" var="course" varStatus="status">
                    <tr class="text-center" align="center">
                        <td>
                            <input type="checkbox" name="deleteId" value=${course.getCourseId()}>
                        </td>
                        <td>${course.getCourseName()}</td>
                        <td>${course.getCourseSuitPeople()}</td>
                    </tr>
                </c:forEach>
                <c:if test = "${fn:length(courseList) == 0}">
                    <tr class="text-center">
                        <td colspan="6">目前尚無課程，請加把勁</td>
                    </tr>
                </c:if>
            </table>
            <%--<input type="submit" value="刪除確定">--%>
            <input type="submit" class="ui inverted red button" onclick="{ if(confirm('確定刪除這些課程??')){ return true; }return false; }" value="刪除確定" />
        </form>
    </div>
</div>

</body>
</html>
