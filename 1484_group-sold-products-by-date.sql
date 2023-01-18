# Write your MySQL query statement below
SELECT
    a.sell_date,
    COUNT(DISTINCT a.product) AS num_sold,
    GROUP_CONCAT(DISTINCT a.product SEPARATOR ',') AS products
FROM Activities AS a
GROUP BY a.sell_date
ORDER BY a.sell_date, a.product

/*
1. We can use 'DISTINCT' independently to get unique values in a column.
2. We can concat all values in a column in a given group using 'GROUP_CONCAT' together with 'SEPARATOR'.
*/
