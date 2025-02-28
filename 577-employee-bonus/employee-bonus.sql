SELECT A.name, B.bonus
FROM Employee AS A
LEFT JOIN Bonus AS B ON A.empId=B.empId
WHERE B.bonus<1000 OR B.bonus IS NULL