# Staff Management System
The structure of storing employee information on physically is inefficient and time consuming. Accumulating physical files on employees may lead to some information being misplaced. Even if the company stores the files digitally, there is not a system that can keep all the employee information orderly in one place.

Hence, a staff management system that works as a database to record information on every employee in a company can help the company to reduce inefficiency, make information retrieval easy and avoid human error. 

## Functionalities and Features
### Basic Features
1. Create a new employee with employee ID, name, age, role and salary.
2. Search for and delete and employee via their ID, name, age or role(position/job).
3. Fire an employee with delete function to delete their details.
4. Edit the details of an existing employee.
5. Search for all the employees with a salary higher than or lower than a user input (only employees with full access can do this).
6. Allow adding user-defined attributes, the value of a new attribute of the existing employee will be empty.

### Additional Features
1. Show a key performance indicator (KPI) leader board (Sorted by weighted score).
2. Use of a user ID and password system (to restrict certain functions like edit/delete).
3. Export all the employee information after updates to a local text file (.txt).
4. Show extra employee information such as length of time at the company, attendance and work/education history, along with the KPI rankings from the leaderboard to ease with process of pay-raise or pay-cut.

## Assumptions
- Every employee is assigned with a random 6-digit ID and a password when you create a new employee detail
- The first index of the employee ID will determine whether the employee is allowed to access higher authority functions.
- If first index is "2", employee will have access to high authority functions such as :
    - Create a new employee
    - Edit employee information 
    - Delete employee
    - Search salary function
- If the first index is "1", employee will have access to basic functions such as:
    - Search by name
    - Search by employee ID
    - Search by job position
    - Show KPI leaderboard
 - The KPI weightage is already calculated in the _**kpi.txt**_ file and only **5** factors are taken into account when calculating the KPI score. In the text file, each weightage score is seperated by a space (" ") and the datas are in the order of name, employee ID and 5 KPI weightage scores (in the case where an employee gets a perfect score for every weightage score, the total final KPI score would be 100). Below is an example of the data:
 
 ```sh
Lee Tak Wah   <- name
200001        <- employee ID
24 45 2 3 10  <- weightage scores
```

## General Instructions
### Requisites
This program is a C++11 standard program. It will run in a C++11 standard compiler i.e., Atom in a Ubuntu Linux environment.
### Output specifications
Input files **must be named** _**"Employee_Details.txt"**_ (contains employee details in the order of: name, employee ID, date of birth, time joined the company, position/role, contact number, email, status, attendance, education/work history, additional attributes), _**"UserIDpass.txt"**_ (stores all the employee IDs and passwords) and _**"kpi.txt"**_ (stores KPI information).

In the _**"Employee_Details.txt"**_ file, a '//' is written at the end of an employee's information to distinguish information between different employees.

If any employee information is updated, the newly updated information will be outputed to the _**"Employee_Details.txt"**_ file for future use.

### Compilation and execution instructions
To compile this program, type 
```sh
make file
```
in the terminal in a Linux environment. Once the compilation is successful, type 
```sh
./main
````
to run the program.

Output messages of instructions will be shown in the screen along with the flow of the program.

The format of input when using **Create Employee function and Edit Employee function** are as follows:

- Name (Any alphanumeric letters)
- Employee Authority (Either 'H' for high, 'L' for low)
- Date of birth (DD/MM/YYYY)
- Joining time (MM/YYYY)
- Job Position (Any alphanumerical word)
- Contact number (Any alphanumerical or symbolic letters)
- Email (Any alphanumerical or symbolic letters)
- Status (Enter letter E/R/F/L : 'E' = Employed, 'R' = Resigned, 'F' = Fired, 'L' = Laid off)
- Attendance (total attended days / work days in a year)
- Salary (Only numerical letters)
- Education and work history (Work or education history startyear-endyear)
- Attribute (Any alphanumerical word, appends similar attribute to other employee details)

_**Follow strictly to the instructions given as entering letters which are not in the options might cause the program to work inaccurately.**_

## Contributors
- Tamara Lee Su Hui [3035548922]
- Lam Zi Hao [3035549146]
