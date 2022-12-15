const express=require('express');
const app=express();
const tasks=require("./routes/tasks")
require('dotenv').config() 
const connectDB = require('./controllers/db/connect');
const nf=require('./middlewares/404nf')


app.use(express.json())
app.use(express.static('./public'))



// app.use(express.json())


app.use('/api/v1/tasks',tasks)

app.use(nf)

const port= process.env.PORT || 3000;

const start=async ()=>{
    try{
        await connectDB(process.env.MONGO_URI)
        app.listen(port,console.log("listen"))
    }
    catch(error){
        console.log(error);
    }
}

start()