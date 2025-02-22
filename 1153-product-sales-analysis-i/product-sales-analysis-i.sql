SELECT b.product_name,a.year,a.price
FROM Sales AS a
JOIN Product AS b
ON a.product_id=b.product_id