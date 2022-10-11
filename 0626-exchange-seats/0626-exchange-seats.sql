# Write your MySQL query statement below
# SELECT CASE 
#         WHEN (id % 2 = 0)  THEN id - 1  ,
#         WHEN (id % 2 != 0) AND id = MAX(id) THEN id
#         ELSE id - 1
#         END AS id
# FROM SEAT
# ORDER BY id;

SELECT  IF(id % 2 = 0 , id-1,IF(id != ( SELECT MAX(id) FROM SEAT ),id+1,id)) AS id
        ,student
    FROM SEAT
    ORDER BY id
                                         
                                      
                               
       

       
       
       