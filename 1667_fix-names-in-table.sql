# Write your MySQL query statement below
SELECT 
    u.user_id,
    CONCAT(
        UPPER(SUBSTR(u.name, 1, 1)), 
        LOWER(SUBSTR(u.name, 2, LENGTH(u.name)-1))
    ) AS name
FROM Users AS u
ORDER BY u.user_id;
