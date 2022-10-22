# Write your MySQL query statement below

SELECT D.name AS DEPARTMENT ,  E.name AS EMPLOYEE , E.salary as Salary
FROM EMPLOYEE AS E JOIN DEPARTMENT AS D
ON E.departmentId = D.id
WHERE E.salary =    (SELECT MAX(salary)
                    FROM EMPLOYEE AS E1
                    WHERE  E1.departmentId = D.id)
 ;