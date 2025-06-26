const express = require('express');
const app = express();

app.get('/', (req, res) => {
  const param = req.query.param1;

  if (!param) {
    res.send('<p>Param is empty</p>');
  } 
  else if (param.length <= 5) {
    res.send(`<p>Param is too short. Size is ${param.length}</p>`);
  } 
  else if (param.length > 5) {
    res.send(`<p>Param is long. Good size is ${param.length}</p>`);
  }
});

app.listen(3000, () => {
  console.log("App is running on http://localhost:3000");
});
