# Write your MySQL query statement below
SELECT t.request_at as `Day`, ROUND(SUM(t.Status != "completed") / COUNT(*), 2) as "Cancellation Rate"
FROM Trips t 
JOIN Users c ON t.client_id = c.users_id 
JOIN Users d ON t.driver_id = d.users_id
WHERE c.banned = "No" AND d.banned = "No" AND t.request_at BETWEEN "2013-10-01" AND "2013-10-03"
GROUP BY t.request_at;

                