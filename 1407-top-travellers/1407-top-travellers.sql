# Write your MySQL query statement below

SELECT T1.name,COALESCE(SUM(R1.distance),0) AS travelled_distance
FROM USERS AS T1 LEFT JOIN  RIDES AS R1 
ON T1.id = R1.user_id
GROUP BY user_id 
ORDER BY 2 DESC , 1 ASC
    


