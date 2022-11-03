# Write your MySQL query statement below
SELECT id, visit_date, people
FROM (
      SELECT id,  visit_date, people,
      LEAD(people, 1) OVER (ORDER BY id) nxt,
      LEAD(people, 2) OVER (ORDER BY id) nxt2,
      LAG(people, 1) OVER (ORDER BY id) pre,
      LAG(people, 2) OVER (ORDER BY id) pre2
        FROM Stadium
) S
WHERE (S.people >= 100 AND S.nxt >= 100 AND S.nxt2 >= 100) 
OR (S.people >= 100 AND S.nxt >= 100 AND S.pre >= 100)  
OR (S.people >= 100 AND S.pre >= 100 AND S.pre2 >= 100)

 