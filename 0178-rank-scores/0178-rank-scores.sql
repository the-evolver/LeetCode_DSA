# Write your MySQL query statement below
    
        
        SELECT  S1.score , (SELECT COUNT(DISTINCT S2.score) 
                              FROM SCORES AS S2
                              WHERE S2.score >= S1.score
                        )  AS "rank"
        
        FROM SCORES AS S1
        ORDER BY S1.score DESC;