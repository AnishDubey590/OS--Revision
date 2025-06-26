import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

@WebServlet("/LogoutServlet")
public class LogoutServlet extends HttpServlet {
  protected void doGet(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException {
    for (Cookie c : req.getCookies()) {
      if ("username".equals(c.getName())) {
        c.setMaxAge(0); res.addCookie(c);
      }
    }
    res.sendRedirect("login.jsp");
  }
}
