SELECT request_at as Day, round(sum(drive)/count(id), 2) as 'Cancellation Rate' ##4-step
 FROM
 (
  SELECT *,
      CASE WHEN status = 'cancelled_by_driver' OR status = 'cancelled_by_client' THEN 1 ELSE 0
        END AS drive 
        FROM Trips
        WHERE client_id IN (SELECT users_id FROM Users WHERE banned = 'NO' AND role = 'client') AND           driver_id IN (SELECT users_id FROM Users WHERE banned = 'NO' AND role = 'driver') ##1-step
        AND request_at between "2013-10-01" and "2013-10-03" ##2-step
        ) tbl

        GROUP BY request_at