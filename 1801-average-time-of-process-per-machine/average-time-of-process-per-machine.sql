SELECT A.machine_id, ROUND((SUM(A.timestamp)-SUM(B.timestamp))/COUNT(A.timestamp),3 )
AS processing_time
FROM Activity A 
JOIN Activity B ON A.machine_id=B.machine_id
WHERE A.activity_type="end" AND B.activity_type="start" 
GROUP BY machine_id
ORDER BY machine_id