<%--
  Created by IntelliJ IDEA.
  User: WHM
  Date: 2019/2/27
  Time: 下午 01:47
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>新增課程</title>

    <link href="https://cdn.jsdelivr.net/npm/semantic-ui@2.4.2/dist/semantic.min.css" rel="stylesheet" type="text/css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/semantic-ui@2.4.2/dist/semantic.min.js"></script>
</head>
<body>
<br>
<button class="large ui inverted violet button" onclick="location.href = '/listAllCourses'">返回課程列表</button>
<br><br>
<div class="ui grid" align="center">    <%--使用網格方式來排版頁面 semantic-ui 把螢幕切為16等分--%>
    <div class="four wide column"></div>    <%--先塞四等分空的 已把後面內容擠到中間去--%>
    <div class="eight wide column">
        <form name="myForm" action="newCourses" method="POST" >
            <table class="ui center aligned six olive table" border="2" >    <%-- table為 兩column --%>
                <tr>
                    <th>課程名稱</th>
                    <td>
                        <div class="ui input">
                            <i class="attention icon"></i>
                            <input type="text" class="form-control" id="course_name" name="course_name" placeholder="必填欄位" required="required" size="25">
                        </div>
                    </td>
                </tr>
                <tr>
                    <th>課程說明</th>
                    <td>
                        <div class="ui input">
                            <input type="text" class="form-control" id="course_detail" name="course_detail" size="25">
                        </div>
                    </td>
                </tr>
                <tr>
                    <th>適合對象</th>
                    <td>
                        <div class="ui input">
                            <input type="text" class="form-control" id="course_suit_people" name="course_suit_people" size="25" >
                        </div>
                    </td>
                </tr>
                <tr>
                    <th>定價</th>
                    <td>
                        <div class="ui right labeled input">
                            <label for="course_price" class="ui label">NT</label>
                            <input type="number" class="form-control" id="course_price" name="course_price" size="15" value="0" min="0" step="1" >
                        </div>
                    </td>
                </tr>
                <tr>
                    <th>注意事項</th>
                    <td>
                        <div class="ui input">
                            <input type="text" class="form-control" id="course_notes" name="course_notes" size="25" >
                         </div>
                    </td>
                </tr>
                <tr>
                    <th>備註</th>
                    <td>
                        <div class="ui input">
                            <input type="text" class="form-control" id="course_remark" name="course_remark" size="25">
                        </div>
                    </td>
                </tr>
            </table>
            <input type="submit" class="ui inverted green button" value="確定新增">
        </form>
    </div>
</div>

</body>
</html>
