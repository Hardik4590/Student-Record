# Student-Record


To conduct any examination, an eligible candidate list should be maintained by the organization. For 
example, consider the semester examination of an education institute.  
There are five departments namely, Computer Sc. & Engg., Electronics & Comm., Electrical, 
Mechanical and Civil. The corresponding department codes are CS, EC, EE, ME and CV respectively. 
Every student has registered for 5 different courses belonging to his/her 
department. 
The record contains general student record list comprises of the following information:
• Name of student
• Department code
• Year/Sem
• Roll number (unique key across dept. and year)
• Number of classes conducted for each of the subjects registered. 
• Number of classes attended by the student for each of the subjects registered.


To track the attendance eligibility, only one subject (for which maximum number of classes were 
conducted) is considered for every semester and every department, and is denoted as MCC. The 
percentage of attendance is computed as belowThe attendance of the student, who has maximum number of classes attended for MCC, is 
considered as 100%. With respect to this, % of attendance for other students as required is to be 
computed using his/her attendance for MCC. 
Attendance record list which maintains the 
attendance of all students irrespective of their departments. The following 
information are to be kept in the attendance list:
• Roll number
• Department
• Attendance : Number of class attended for MCC and % attendance



The record contains fee status list to maintain the record of the fee status for all students. The list contains the 
below information:
• Roll number
• Fee status (pending/clear)


It also contains an applicant list to track the record of the students who have applied for the examination. 
The list stores the following fields:
• Name of the student
• Roll number
• A/NA (A stands for applicant, NA stands for non-applicant)

Following Operations can be conducted on this student record:

1) Sort the general student record list based first on semester, and then followed by 
department-name, and then the roll number.

2) Display year wise and then the department-wise names of the students who did not apply 
for the examination

3)Create a list of all 
eligible students for the semester examination and Sort the list based first on semester, and 
then followed by department-name, and then the roll number.( A student is eligible to sit for the semester examination if his/her attendance is more than 
75% for MCC, fees status is clear and he/she applied for the examination)

4)Create a list of students having attendance <=75%. based first on semester, and then 
followed by department-name, and then the roll number

5)Print the name of the students whose attendance is >75% for the respective MCC but their 
fee status is pending.

6)Create a list of defaulter students.(A student is called as defaulter either his/her attendance 
for MCC is <=75% or his/her fee status is pending). Find the name of the department in which 
maximum number of defaulters belong to.


