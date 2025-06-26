<%
String name = null;
for (Cookie c : request.getCookies()) {
  if ("username".equals(c.getName())) {
    name = c.getValue(); break;
  }
}
if (name == null) {
  response.sendRedirect("login.jsp"); return;
}
%>
<!DOCTYPE html>
<html>
<head><title>Dashboard</title></head>
<body>
<h2>Welcome, <%= name %>!</h2>
<p>Session tracked using cookies.</p>
<a href="LogoutServlet">Logout</a>
</body>
</html>
