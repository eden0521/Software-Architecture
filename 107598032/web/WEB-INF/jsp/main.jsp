<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: Satellite
  Date: 2019/2/25
  Time: 上午 11:01
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
        <div class="panel panel-info">
            <div class="panel-heading"><span class="glyphicon glyphicon-exclamation-sign">　</span>課程</div>
            <div class="panel-body">
                <table class="table table-bordered">
                    <tr>
                        <th class="text-center">課程名稱</th>
                        <th class="text-center">課程說明</th>
                        <th class="text-center">適合對象</th>
                        <th class="text-center">定價</th>
                        <th class="text-center">注意事項</th>
                        <th class="text-center">備註</th>
                    </tr>
                    <c:forEach items="${courseList}" var="course" varStatus="status">
                        <tr class="text-center">
                            <td>${course.getName()}</td>
                            <td>${course.getContent()}</td>
                            <td>${course.getMember()}</td>
                            <td>${course.getPrice()}</td>
                            <td>${course.getNotice()}</td>
                            <td>${course.getRemark()}</td>
                        </tr>
                    </c:forEach>
                    <c:if test = "${fn:length(courseList) == 0}">
                        <tr class="text-center">
                            <td colspan="6">查無課程</td>
                        </tr>
                    </c:if>
                </table>
            </div>
        </div>
    </div>
</div><!-- /container -->
</body>
</html>
