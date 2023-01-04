# Write your MySQL query statement below
SELECT d.name AS Department, E1.name as Employee, E1.salary
FROM Employee E1 JOIN Department d 
ON E1.departmentId = d.id 
WHERE 3 > 
(SELECT COUNT(DISTINCT e2.salary)  FROM Employee E2 WHERE E2.salary > E1.salary AND E2.DepartmentId = E1.DepartmentId)