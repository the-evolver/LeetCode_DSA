# Write your MySQL query statement below

SELECT customer_number
FROM ORDERS
GROUP BY customer_number
ORDER BY COUNT(customer_number) DESC
LIMIT 1;
