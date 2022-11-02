# Write your MySQL query statement below
SELECT d.name AS Department, a.name AS Employee, a.salary
FROM (SELECT *, MAX(salary) OVER (PARTITION BY departmentId) AS Max_Salary FROM Employee) a
INNER JOIN Department d 
ON a.departmentId = d.id
WHERE a.salary = a.Max_Salary;