SELECT a.customer_id,COUNT(a.customer_id) AS 'count_no_trans'
FROM Visits a
left join Transactions b
ON a.visit_id=b.visit_id
WHERE transaction_id IS NULL
GROUP BY a.customer_id
ORDER BY count_no_trans