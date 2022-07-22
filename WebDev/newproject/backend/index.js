const express = require("express");
 
const mongoose = require("mongoose");
 
const router = require("../routes/book-routes");
 
const app = express();
 
mongoose.connect(
   "mongodb+srv://Ankur:1204@nodeprojects.sv0tc.mongodb.net/?retryWrites=true&w=majority"
).then(()=> console.log("Connected to a database"))
.then(()=> {
   app.listen(5000);
})
.catch((err)=> console.log(err));
 
app.use("/books",router);