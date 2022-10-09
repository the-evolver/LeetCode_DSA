# Write your MySQL query statement below

# SELECT id , CASE WHEN p_id IS NULL THEN "Root" 
#                  END AS type
# FROM TREE

# UNION

SELECT id ,
           CASE
           WHEN p_id IS NULL THEN 'Root'
           WHEN id NOT IN ( SELECT T1.id  FROM TREE AS T1 JOIN TREE AS T2 ON T1.id = T2.p_id ) THEN 'Leaf'
           # WHEN id NOT IN ( SELECT T1.id  FROM TREE AS T1 JOIN TREE AS T2 ON T1.id = T2.p_id ) AND p_id IS NOT NULL THEN 
           ELSE 'Inner'
              # ELSE 'Root'
                END AS type
FROM TREE
ORDER BY id ;
