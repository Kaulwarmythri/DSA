# Write your MySQL query statement below
SELECT a.Department, a.Employee, a.Salary FROM 
    (SELECT d.name as Department, e.name as Employee, e.salary, DENSE_RANK() OVER (PARTITION BY d.id ORDER BY e.salary DESC) AS rnk 
     FROM Employee e 
     JOIN Department d
     ON e.departmentId = d.id) a
     WHERE a.rnk <= 3;

