CREATE FUNCTION getNthHighestSalary(n INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      WITH T AS (SELECT salary, DENSE_RANK() OVER(ORDER BY salary DESC) as rnk
                FROM Employee)
      SELECT MAX(salary) FROM T
      WHERE rnk = n
  );
END