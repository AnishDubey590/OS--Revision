<%-- Document : The we host --%>
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>
</head>
<body>
  <form method="post" action="<%= request.getContextPath() %>/studentservlet">
    Name: <input type="text" name="name"><br>
    Roll no: <input type="number" name="rollno"><br>
    Age: <input type="number" name="age"><br>
    <button type="submit">Submit</button>
  </form>
</body>
</html>
