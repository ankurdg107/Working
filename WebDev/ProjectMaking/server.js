if(process.env.NODE_ENV!='production'){
    require('dotenv').config();
}

const express=require("express");
const app =express();
app.set('view-engine',"ejs");
app.use(express.urlencoded({extended:false}));
const bycrypt =require('bcrypt');
const passport  = require("passport");
const flash = require("express-flash");
const session = require("express-session");
app.use(flash());
app.use(session({
    secret:process.env.SESSION_SECRET,
    resave:false,
    saveUninitialized:false
}))
app.use(passport.initialize());

const initializePassport = require("../ProjectMaking/passport-config");

initializePassport(passport,
    (email)=> users.find(user=>user.email===email),
    (email) => users.find(user=>user.id===id)
);

const users = [];
app.get('/',(req,res)=>{
    res.render("index.ejs",{name:" pp"});
})

app.get('/login',(req,res)=>{
    res.render('login.ejs');
})

app.get('/register',(req,res)=>{
    res.render('register.ejs');
})

app.post('/register',async(req,res)=>{
    try{
        const hashedPassword = await bycrypt.hash(req.body.password,10);
        users.push({
            id: Date.now().toString(),
            name:req.body.name,
            email:req.body.email,
            password: hashedPassword
        });
        res.redirect('/login');
    }catch{
        res.redirect('/register');
    }
    
})
app.post('/login',passport.authenticate('local',{
    successRedirect:'/',
    failureRedirect:'/login',
    failureFlash:true
}))

app.listen(3000,()=>{
    console.log("listening bc at 3000");
});