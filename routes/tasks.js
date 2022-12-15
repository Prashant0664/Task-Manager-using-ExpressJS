const express=require('express')
const {getalltasks,gettask,createtask,updatetask,deletetask} = require("../controllers/tasks")
const router=express.Router();

router.route('/').get(getalltasks).post(createtask);
router.route('/:id').get(gettask).patch(updatetask).delete(deletetask);

module.exports=router