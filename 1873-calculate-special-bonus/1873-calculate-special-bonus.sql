# Write your MySQL query statement below
SELECT employee_id, salary * (employee_id % 2) * (name NOT LIKE "M%") as Bonus
FROM Employees
ORDER BY employee_id;