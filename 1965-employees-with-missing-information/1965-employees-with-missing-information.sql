# Write your MySQL query statement below

SELECT T1.employee_id AS employee_id
FROM EMPLOYEES AS T1 LEFT JOIN SALARIES AS S1
     ON T1.employee_id = S1.employee_id
WHERE S1.salary IS NULL

UNION

SELECT S1.employee_id AS employee_id
FROM SALARIES AS S1 LEFT JOIN EMPLOYEES AS T1
     ON S1.employee_id = T1.employee_id
WHERE T1.name IS NULL

ORDER BY employee_id;


