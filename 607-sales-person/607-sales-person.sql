# Write your MySQL query statement below
WITH CTE AS(
SELECT o1.sales_id
FROM COMPANY AS C1 CROSS JOIN ORDERS as O1
ON C1.com_id = O1.com_id AND c1.name = 'RED'
)

SELECT name 
FROM SALESPERSON 
WHERE sales_id NOT IN (SELECT sales_id FROM CTE);