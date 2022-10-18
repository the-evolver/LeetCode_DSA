# Write your MySQL query statement below

SELECT DISTINCT l1.num AS ConsecutiveNums
FROM LOGS AS l1  JOIN LOGS AS l2 ON l1.id + 1 = l2.id AND l1.num = l2.num
JOIN LOGS AS l3 ON l1.id + 2 = l3.id AND l1.num = l3.num;