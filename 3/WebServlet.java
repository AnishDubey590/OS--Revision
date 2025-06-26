import java.io.*;
import java.sql.*; // You missed this
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*; // typo here corrected

@WebServlet("/studentservlet")
public class WebServlet extends HttpServlet {

    protected void doPost(HttpServletRequest request, HttpServletResponse response) 
        throws ServletException, IOException {

        // Correct method names and case
        String name = request.getParameter("name");
        int rollno = Integer.parseInt(request.getParameter("rollno"));
        int age = Integer.parseInt(request.getParameter("age"));

        response.setContentType("text/html"); // lowercase, correct MIME type
        PrintWriter out = response.getWriter();

        try {
            // Load MySQL JDBC driver
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Connect to the database
            Connection con = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/mydatabase", "root", "");

            // Insert query using PreparedStatement
            PreparedStatement pstmt = con.prepareStatement(
                "INSERT INTO students2(name, rollno, age) VALUES (?, ?, ?)");
            pstmt.setString(1, name);
            pstmt.setInt(2, rollno);
            pstmt.setInt(3, age);

            pstmt.executeUpdate(); // Execute query
            out.println("<h3>Data inserted successfully</h3>");

            con.close(); // Close connection
        } catch (Exception e) {
            out.println("<h3>Error: " + e.getMessage() + "</h3>");
        }
    }
}
