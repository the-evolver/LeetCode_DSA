# Write your MySQL query statement below
SELECT e1.name AS EMPLOYEE
FROM EMPLOYEE AS e1 JOIN EMPLOYEE AS e2
ON e1.managerId = e2.id
WHERE e1.salary > e2.salary;