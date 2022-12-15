const mongoose = require('mongoose')

const TaskSchema = new mongoose.Schema({
  name: {
    type: String,
    required: [true, '*Name Field cannot be left EMPTY'],
    trim: true,
    maxlength: [40, '*Name Field cannot contain more than 40 CHARACTERS'],
  },
  completed: {
    type: Boolean,
    default: false,
  },
})

module.exports = mongoose.model('Task', TaskSchema)
