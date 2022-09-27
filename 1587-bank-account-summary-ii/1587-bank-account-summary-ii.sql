# Write your MySQL query statement below

SELECT name,SUM(amount) AS balance

FROM USERS CROSS JOIN  Transactions ON USERS.account = Transactions.account

GROUP BY name HAVING balance > 10000;





