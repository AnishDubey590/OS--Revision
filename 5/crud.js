const express = require('express');
const app = express();
const port = 4000;

app.use(express.json());

let students = [
  { id: 1, name: "Anish", age: 21 },
  { id: 2, name: "Rahul", age: 22 }
];

// GET all students
app.get('/students', (req, res) => {
  res.json(students);
});

// GET student by ID
app.get('/students/:id', (req, res) => {
  const student = students.find(s => s.id == req.params.id);
  if (student) res.json(student);
  else res.status(404).send("Student not found");
});

// POST add new student
app.post('/students', (req, res) => {
  const newStudent = {
    id: students.length + 1,
    name: req.body.name,
    age: req.body.age
  };
  students.push(newStudent);
  res.status(201).json(newStudent);
});

// PUT update student
app.put('/students/:id', (req, res) => {
  const student = students.find(s => s.id == req.params.id);
  if (student) {
    student.name = req.body.name || student.name;
    student.age = req.body.age || student.age;
    res.json(student);
  } else {
    res.status(404).send("Student not found");
  }
});

// DELETE student
app.delete('/students/:id', (req, res) => {
  students = students.filter(s => s.id != req.params.id);
  res.send("Student deleted");
});

app.listen(port, () => {
  console.log(`Student API running on http://localhost:${port}`);
});
