# Write your MySQL query statement below

SELECT DISTINCT e1.email
FROM PERSON AS e1 JOIN PERSON AS e2
ON e1.email = e2.email AND e1.id != e2.id;
