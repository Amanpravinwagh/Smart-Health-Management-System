import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;

public class OnlinePortalServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        try {
            // Database Connection
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/healthcare", "root", "password");

            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery("SELECT * FROM patients");

            out.println("<html><body>");
            out.println("<h1>Patient Records</h1>");
            out.println("<table border='1'><tr><th>Name</th><th>Age</th><th>Disease</th></tr>");
            while (rs.next()) {
                out.println("<tr><td>" + rs.getString("name") + "</td><td>" + rs.getInt("age") + "</td><td>" + rs.getString("disease") + "</td></tr>");
            }
            out.println("</table></body></html>");

            conn.close();
        } catch (Exception e) {
            out.println("Error: " + e.getMessage());
        }
    }
}