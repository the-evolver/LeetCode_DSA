# Write your MySQL query statement below

SELECT customer_id,COUNT(customer_id) AS count_no_trans
FROM VISITS 
WHERE visit_id NOT IN (SELECT visit_id FROM TRANSACTIONS)
GROUP BY customer_id;
