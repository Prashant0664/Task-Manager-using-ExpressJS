const mongoose=require('mongoose');

const taskss=new mongoose.Schema({
    name:String,
    completed: Boolean,
})

module.exports=mongoose.model('Task',taskss);