
DELETE P1
FROM PERSON P1 JOIN PERSON P2
     ON P1.email = P2.email
     WHERE P1.id > P2.id
