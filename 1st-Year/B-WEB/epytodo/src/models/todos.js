const mysql = require('../config/db');

const Todo = function(todo) {
    this.title = todo.title;
    this.description = todo.description;
    this.created_at = new Date();
    this.due_time = todo.due_time;
    this.status = todo.status || "not started";
    this.user_id = todo.user_id;
};

Todo.create = function(newTodo, result) {
    mysql.query("INSERT INTO todo SET ?", newTodo, function (err, res) {
        if (err) {
            console.log("error when create (todo): ", err);
            result(err, null);
        } else {
            console.log("successfully create (todo): ", res.insertId);
            result(null, res.insertId);
        }
    });
};

Todo.findById = function(todoId, result) {
    mysql.query("SELECT id, title, description, DATE_FORMAT(created_at, '%Y-%m-%d %T') AS created_at, DATE_FORMAT(due_time, '%Y-%m-%d %T') AS due_time, user_id, status FROM todo WHERE id = ?", todoId, function(err, res) {
        if (err) {
            console.log("error when find by ID (todo): ", err);
            result(err, null);
        } else {
            result(null, res);
        }
    });
};

Todo.findByUserId = function(UserId, result) {
    mysql.query("SELECT id, title, description, DATE_FORMAT(created_at, '%Y-%m-%d %T') AS created_at, DATE_FORMAT(due_time, '%Y-%m-%d %T') AS due_time, user_id, status FROM todo WHERE user_id = ?", UserId, function(err, res) {
        if (err) {
            console.log("error when find by USER ID (todo): ", err);
            result(err, null);
        } else {
            result(null, res);
        }
    });
};

Todo.findAll = function(result) {
    mysql.query("SELECT id, title, description, DATE_FORMAT(created_at, '%Y-%m-%d %T') AS created_at, DATE_FORMAT(due_time, '%Y-%m-%d %T') AS due_time, user_id, status FROM todo", function(err, res) {
        if (err) {
            console.log("error when find all (todo): ", err);
            result(err, null);
        } else {
            result(null, res);
        }
    });
};

Todo.update = function(id, todo, result) {
    mysql.query("UPDATE todo SET title=?, description=?, status=? WHERE id=?",
                [todo.email, todo.password, todo.name, todo.firstname, id],
                function(err, res) {
                    if (err) {
                        console.log("error when update (todo): ", err);
                        result(err, null);
                    } else {
                        result(null, res);
                    }
    });
};

Todo.delete = function(id, result) {
    mysql.query("DELETE FROM todo WHERE id=?", id, function(err, res) {
        if (err) {
            console.log("error when delete (todo): ", err);
            result(err, null);
        } else {
            result(null, res);
        }
    });
};

module.exports = Todo;