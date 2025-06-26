import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

@WebServlet("/LoginServlet")
public class LoginServlet extends HttpServlet {
  protected void doPost(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException {
    String user = req.getParameter("username");
    Cookie c = new Cookie("username", user);
    c.setMaxAge(300); // 5 min
    res.addCookie(c);
    res.sendRedirect("dashboard.jsp");
  }
}
