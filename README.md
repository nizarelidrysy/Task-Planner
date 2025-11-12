# 📅 Task Planner

## 📝 Project Description

This project is a simple console application developed in the C language to manage tasks. It allows users to **add**, **display**, and **delete** tasks, fulfilling the core objectives of the programming assignment.

The application uses a C structure to define each task with its **name**, **description**, and **execution date/time**. It includes user input validation mechanisms for the year, month, and day (including handling leap years), as well as the time, ensuring robust error management.

---

## ✨ Features

The program provides a simple text-based interface with the following options:

1.  **Add Tasks** (`1- Ajouter des taches`): Allows the user to enter the name, description, date (DD MM YYYY), and time (HH MM) for one or more new tasks.
2.  **Display Tasks** (`2- Afficher des taches`): Allows the user to view either all recorded tasks or a specific task by providing its number.
3.  **Delete Tasks** (`3- Supprimer des taches`): Allows the user to delete either all tasks at once or a specific task by its number.
4.  **Quit** (`4- Quitter`): Terminates the program execution.

---

## 🛠️ Code Structure

The program is implemented in the file `PT.c`.

### Task Structure

The details of each task are stored in the `alpha` structure:

```c
struct alpha{
	char name[100],description[200],clock_time[2];
	int day,month,year,hour,min;
};