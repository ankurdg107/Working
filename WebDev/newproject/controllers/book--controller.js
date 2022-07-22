
const Book = require("../model/Book");
 
const getAllBooks = async (req,res,next) => {
 
   let books;
 
   try{
       books = await Book.find(); //inbuilt func .find
   }catch (err){
       console.log(err);
   }
 
   if(!books){
       return res.status(404).json({message:"No products found"});
   }else
       return res.status(200).json({books});
 
};
const addBooks = async (req,res,next) => {

    const {name , author, price} = req.body;
    const newBook = new Book(req.body);
    await newBook.save();
 };
  
 
 
exports.getAllBooks = getAllBooks;
exports.addBooks = addBooks;