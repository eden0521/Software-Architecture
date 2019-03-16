<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page import="java.util.List" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<%--
  Created by IntelliJ IDEA.
  User: WHM
  Date: 2019/2/28
  Time: 下午 01:52
  To change this template InsertCourseUseCase File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>課程列表</title>

    <link href="https://cdn.jsdelivr.net/npm/semantic-ui@2.4.2/dist/semantic.min.css" rel="stylesheet" type="text/css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/semantic-ui@2.4.2/dist/semantic.min.js"></script>
</head>
<body>
<br>
<div class="ui buttons">
    <button class="large ui inverted green button" onclick="location.href = '/newCourses'">新增課程</button>
    <div class="or"></div>
    <button class="large ui inverted red button" onclick="location.href = '/deleteCourses'">刪除課程</button>
</div>
<br><br>
<div class="ui grid" align="center">    <%--使用網格方式來排版頁面 semantic-ui 把螢幕切為16等分--%>
    <div class="two wide column"></div>    <%--先塞兩等分空的 已把後面內容擠到中間去--%>
    <div class="twelve wide column">
        <form name="myForm" action="listAllCourses" method="POST" >
            <table class=" ui large eight yellow striped table" align="center" >
                <thead>
                <tr class="text-center">
                    <th>課程編號</th>
                    <th>課程名稱</th>
                    <th>課程說明</th>
                    <th>適合對象</th>
                    <th>定價</th>
                    <th>注意事項</th>
                    <th>備註</th>
                    <th colspan="1"></th>
                </tr>
                </thead>
                <tbody>
                <c:forEach items="${courseList}" var="course" varStatus="status">
                    <tr class="text-center">
                        <td>${course.getCourseId()}</td>
                        <td>${course.getCourseName()}</td>
                        <td style="word-break: break-all">${course.getCourseDetail()}</td>
                        <td>${course.getCourseSuitPeople()}</td>
                        <td>${course.getCoursePrice()}</td>
                        <td>${course.getCourseNotes()}</td>
                        <td>${course.getCourseRemark()}</td>
                            <%--<td><input type="button" onclick="location.href = '/editCourses?id=${course.getCourseId()}'" value="編輯"></td>--%>
                        <td class="right aligned collapsing">
                            <input type="button" name="編輯" value="編輯" class="circular ui icon button"
                                   onclick="window.location='editCourses?id=${course.getCourseId()}';"/>
                        </td>
                            <%--<td><button name="editId${course.getCourseId()}" value="3" onclick="location.href = '/editCourses?method=GET&id=${course.getCourseId()}'">編輯</button></td>--%>
                            <%--<a methods="POST" class="btn btn-warning" href="editCourses?id=${course.getId()}" role="button">編輯課程</a>--%>
                    </tr>
                </c:forEach>
                <c:if test = "${fn:length(courseList) == 0}">
                    <tr class="text-center">
                        <td colspan="7">目前尚無課程，請加把勁</td>
                    </tr>
                </c:if>
                </tbody>
            </table>
        </form>
    </div>
</div>
<div class="ui left icon input">
    <i class="braille icon"></i>
    <input type="submit" value="顯示課程列表">
</div>
<%--<a href="/db_test">我的帳戶</a>--%>
</body>
</html>
