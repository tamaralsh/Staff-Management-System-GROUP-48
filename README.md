# Staff Management System
The structure of storing employee information on physically is inefficient and time consuming. Accumulating physical files on employees may lead to some information being misplaced. Even if the company stores the files digitally, there is not a system that can keep all the employee information orderly in one place.

Hence, a staff management system that works as a database to record information on every employee in a company can help the company to reduce inefficiency, make information retrieval easy and avoid human error. 

## Functionalities and Features
### Basic Features
1. Create a new employee with employee ID, name, age, role and salary.
2. Search for and delete and employee via their ID, name, age or role.
3. Fire an employee.
4. Edit the details of an existing employee.
5. Search for all the employees with a salary higher than or lower than a user input (only employees with full access can do this).
6. Allow adding user-defined attributes, the value of a new attribute of the existing employee should be empty or undefined.

### Additional Features
1. Show a key performance indicator (KPI) leader board (Sorted by weighted score).
2. Use of a user ID and password system (to protect sensitive information).
3. Export all the employee information after updates to a local text file (.txt).
4. Show extra employee information such as length of time at the company, date of birth, atttendance and work/education history.

## Assumptions
Every employee is assigned a 6-digit ID and a password. The first index of the 6-digit employee ID will determine whether the employee is allowed to create a new employee, edit employee information and view sensitive information such as salary. If the first index is "1", the employee has restricted access to the system and if the first index is "2", the employee has full access to the system.

## General Instructions
### Requisites
This program is a C++11 standard program. It will run in a C++11 standard complier i.e., Atom in a Ubuntu Linux environment.
### Input and output specifications
Input files _**must**_ be named "Employee_Details.txt" (contains employee details in the order of: name, employee ID, date of birth, time joined the company, position/role, contact number, email, status, attendance, education/work history), "UserIDpass.txt" (stores all the employee IDs and passwords) and "kpi.txt" (stores KPI information).

If any employee information is updated, the newly updated information will be outputed to the "Employee_Details.txt" file for future use.

### Compilation and execution instructions
To compile this program, type _make file_ in the terminal in a Linux environment. Once the compilation is successful, type _./main_ to run the program.

## Contributors
- Tamara Lee Su Hui [3035548922]
- Lam Zi Hao []
