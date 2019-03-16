<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<%--
  Created by IntelliJ IDEA.
  User: Satellite
  Date: 2019/2/26
  Time: 上午 09:32
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
        <div class="panel panel-warning">
            <div class="panel-heading"><span class="glyphicon glyphicon-exclamation-sign">　</span>編輯課程</div>
            <div class="panel-body">
                <form name="selectForm" action="/Edit" method="GET">
                    <label for="selectCourse">選擇欲修改之課程 </label>
                    <select class="form-control" id="selectCourse" name="selectCourse">
                        <c:forEach items="${courseList}" var="course" varStatus="status">
                            <option value="${course.getId()}">${course.getName()}</option>
                        </c:forEach>
                    </select>
                    <br>
                    <input type="submit" class="btn btn-primary" data-toggle='modal' data-target='#update' value="確認">
                </form>
            </div>
        </div>
    </div>
    <c:if test = "${selectCourse != null}">
        <jsp:include page="updateForm.jsp"></jsp:include>
    </c:if>
</div><!-- /container -->
</body>
</html>
