# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
/*
We 'join' the same table to compare the value of a certain column,
and we use 'delete' on one of them to delete some records. 
*/
DELETE p1 
FROM Person AS p1
JOIN Person AS p2
ON p1.email = p2.email
WHERE p1.id > p2.id;
