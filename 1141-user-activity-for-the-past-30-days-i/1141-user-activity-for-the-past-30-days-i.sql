# Write your MySQL query statement below

SELECT activity_date AS day , COUNT(DISTINCT user_id) AS active_users
FROM ACTIVITY
GROUP BY activity_date
HAVING DATEDIFF(activity_date , "2019-06-28" ) >= 0  AND 
       DATEDIFF(activity_date , "2019-07-27") <= 0   ; 