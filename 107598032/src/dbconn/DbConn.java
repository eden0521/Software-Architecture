package dbconn;


import com.mysql.cj.jdbc.Driver;

import java.sql.Connection;
import java.sql.DriverManager;

public class DbConn {

    public final static String COURSE = "course";
    public final static String COURSE_CACHE = "course_cache";

    public static Connection getConnection(String dbName) {
        return getConnection(dbName, "root", "islab1221");
    }

    public static Connection getConnection(String dbName, String userName, String password) {
        try {
            String url = "jdbc:mysql://140.124.181.7:3306/" + dbName + "?useUnicode=true&characterEncoding=utf-8&serverTimezone=UTC&useSSL=false";
            DriverManager.registerDriver(new Driver());
            return DriverManager.getConnection(url, userName, password);
        }catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
}