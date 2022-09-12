# Write your MySQL query statement below

SELECT stock_name,SUM(
    CASE WHEN operation = 'Buy' then -price
    ELSE price
    END
) AS capital_gain_loss
FROM stocks
GROUP BY stock_name;

