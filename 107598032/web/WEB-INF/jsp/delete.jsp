<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<%--
  Created by IntelliJ IDEA.
  User: Satellite
  Date: 2019/2/26
  Time: 上午 08:42
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>課程系統</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
</head>
<body>
<div class="container">
    <jsp:include page="buttons.jsp"></jsp:include>
    <div class="col-md-15">
        <div class="panel panel-danger">
            <div class="panel-heading"><span class="glyphicon glyphicon-exclamation-sign">　</span>刪除課程</div>
            <div class="panel-body">
                <form name="deleteForm" action="/Delete" method="POST">
                    <table class="table table-bordered">
                        <tr>
                            <th class="text-center">勾選</th>
                            <th class="text-center">課程名稱</th>
                            <th class="text-center">課程說明</th>
                        </tr>
                        <c:forEach items="${courseList}" var="course" varStatus="status">
                            <tr class="text-center">
                                <td><input type="checkbox" name="deleteId" value=${course.getId()}></td>
                                <td>${course.getName()}</td>
                                <td>${course.getContent()}</td>
                            </tr>
                        </c:forEach>
                        <c:if test = "${fn:length(courseList) == 0}">
                            <tr class="text-center">
                                <td colspan="3">查無課程</td>
                            </tr>
                        </c:if>
                    </table>
                    <input type="submit" class="btn btn-primary" value="刪除">
                </form>
            </div>
        </div>
    </div>
</div><!-- /container -->
</body>
</html>
