SELECT today.id 
FROM Weather AS today
CROSS JOIN Weather AS yesterday
WHERE DATEDIFF(today.recordDate,yesterday.recordDate) = 1
AND today.temperature > yesterday.temperature;