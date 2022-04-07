const express = require('express');
const router = express.Router();

const todosCtrl = require('../controllers/todos');

router.get('/', todosCtrl.getAllTodos);

router.post('/', todosCtrl.createTodo);

router.get('/:id', todosCtrl.getTodoById);

router.put('/:id', todosCtrl.editTodo);

router.delete('/:id', todosCtrl.deleteTodo);

module.exports = router;
