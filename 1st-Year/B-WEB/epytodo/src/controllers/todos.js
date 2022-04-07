const Todo = require('../models/todos');

exports.getAllTodos = (req, res, next) => {
    Todo.findAll(function(err, tasks) {
        if (err) {
            res.status(500).json({ msg: "Internal server error"});
        } else {
            if (tasks.length === 0) return res.status(404).json({ msg: "Not found"});
            res.status(200).json( tasks );
        }
    });
};

exports.createTodo = (req, res, next) => {
    const newTodo = new Todo({
        title: req.body.title,
        description: req.body.description,
        due_time: req.body.due_time,
        user_id: req.body.user_id,
        status: req.body.status
    });
    Todo.create(newTodo, function(err, taskId) {
        if (err) {
            res.status(500).json({ msg: "internal server error"});
        } else {
            Todo.findById(taskId, function(err, createdTask) {
                if (err) {
                    res.status(500).json({ msg: "internal server error"});
                } else {
                    res.status(201).json( createdTask[0] );
                }
            });
        }
    });
};

exports.getTodoById = (req, res, next) => {
    Todo.findById(req.params.id, function(err, task) {
        if (err) {
            res.status(500).json({ msg: "internal server error"});
        } else {
            if (task.length === 0) return res.status(404).json({ msg: "Not found"});
            res.status(200).json( task[0] );
        }
    });
};

exports.editTodo = (req, res, next) => {
    const newTodo = new Todo({
        title: req.body.title,
        description: req.body.description,
        due_time: req.body.due_time,
        user_id: req.body.user_id,
        status: req.body.status
    });
    Todo.update(req.params.id, newTodo, function(err, editedTask) {
        if (err) {
            res.status(500).json({ msg: "internal server error"});
        } else {
            res.status(201).json({
                title: req.body.title,
                description: req.body.description,
                due_time: req.body.due_time,
                user_id: req.body.user_id,
                status: req.body.status
            });
        }
    });
};

exports.deleteTodo = (req, res, next) => {
    Todo.delete(req.params.id, function(err, deleted) {
        if (err) {
            res.status(500).json({ msg: "internal server error"});
        } else {
            if (deleted.affectedRows === 0) return res.status(404).json({ msg: "Not found"});
            res.status(201).json({ msg: `successfully deleted record number: ${req.params.id}`});
        }
    });
};
