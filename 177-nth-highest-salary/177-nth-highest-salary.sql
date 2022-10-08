CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      
      SELECT salary 
      FROM EMPLOYEE AS E1
      WHERE N-1 = (SELECT COUNT(DISTINCT E2.SALARY )
                   FROM EMPLOYEE AS E2
                   WHERE E1.salary <  E2.salary
                   
                  
                  )
      LIMIT 1
      
  );
END