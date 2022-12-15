// const Task=require('../mongoose/Task')
const Task=require("./models/Task")
const sw=require("../middlewares/async")

const getalltasks=sw(async (req,res)=>{
        const tasks=await Task.find({})
        res.status(201).json({tasks})
        // res.status(200).json({status:true,data:{tasks,nbHits:tasks.length}})
})


const createtask=async (req,res)=>{
    try{
        const task=await Task.create(req.body)
        res.status(201).json({task})
}
    catch(error){
        res.status(500).json({ "msg":error}) 
    }
}


const gettask=async (req,res)=>{
    try{
        const {id:taskid}=req.params;
        const task=await Task.findOne({_id:taskid});
        if(!task){
            return res.status(404).json({msg:"NOT FOUND"}) 
        }
        res.status(200).json({task})
    }
    catch(err){
        res.status(500).json({msg:err})
    }
}



const updatetask= async (req,res)=>{
    try{
        const {id:taskID}=req.params;
        const task=await Task.findOneAndUpdate({_id:taskID},req.body,{
            new: true,
            runValidators: true,
        });
        if(!task){
            return res.status(404).json({msg:"NOT FOUND!"}) 
        }
        res.status(200).json({id:taskID,data:req.body});
    }
    catch(err){
        res.status(500).json({msg:err})
    }
}



const deletetask= async (req,res)=>{
    try{
        const {id:taskid}=req.params;
        const task=await Task.findOneAndDelete({_id:taskid});
        if(!task){
            return res.status(404).json({msg:"NOT FOUND!"}) 
        }
        res.status(200).json({task:null , status:'success'})
    }
    catch(err){
        res.status(500).json({msg:err})
    }
}

module.exports={getalltasks,gettask,createtask,updatetask,deletetask}