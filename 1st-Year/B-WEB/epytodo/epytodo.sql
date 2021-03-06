CREATE DATABASE IF NOT EXISTS `epytodo` DEFAULT CHARACTER SET utf8mb4;
USE `epytodo`;

CREATE  TABLE IF NOT EXISTS `user` (
  `id` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `email` VARCHAR(255) NOT NULL,
  `password` VARCHAR(255) NOT NULL,
  `name` VARCHAR(255) NOT NULL,
  `firstname` VARCHAR(255) NOT NULL,
  `created_at`DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  UNIQUE KEY `email` (`email`)
) AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;

CREATE  TABLE IF NOT EXISTS `todo` (
  `id` INT(11) NOT NULL AUTO_INCREMENT,
  `title` VARCHAR(255) NOT NULL,
  `description` VARCHAR(255) NOT NULL,
  `created_at` DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `due_time` DATETIME NOT NULL,
  `status` enum('not started', 'todo', 'in progress', 'done') NOT NULL DEFAULT 'not started',
  `user_id` INT UNSIGNED NOT NULL,
  PRIMARY KEY (`id`),
  FOREIGN KEY (`user_id`) REFERENCES user(id) ON DELETE CASCADE
) AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;
