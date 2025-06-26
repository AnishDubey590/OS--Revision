function validateform(){
const email=document.getElementById("email").value.trim();
const pass=document.getElementById("password").value;
const confps=document.getElementById("confpass").value;
const dob=document.getElementById("dob").value;
let valid=true;
if(!email || !email.includes("@") || !email.includes(".")){
document.getElementById("emailerror").textContent="enter valid email";
valid=false;
}
if(!pass || pass.length<8){
document.getElementById("passerror").textContent="Password must be
minimum 8 characters";
valid=false;
}
if(confps!==pass){
document.getElementById("confpasserr").textContent="Password do not
match";
valid=false;
}
if(!dob){
document.getElementById("doberr").textContent="dob required";
valid=false;
}
if(valid){
alert("registration successful");
return true;
}
else{
return false;}}