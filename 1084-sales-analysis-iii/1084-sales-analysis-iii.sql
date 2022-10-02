# Write your MySQL query statement below
SELECT P.product_id,P.product_name
FROM PRODUCT AS P CROSS JOIN SALES AS S
ON P.product_id = S.product_id 
GROUP BY product_id
HAVING MIN(sale_date) >= '2019-01-01' AND MAX(sale_date) <= '2019-03-31'
   
