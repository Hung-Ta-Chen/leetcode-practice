/*
In MySQL, we don't have FULL JOIN clause.
Therefore we have to use LEFT JOIN together with UNION to achieve the same function
*/
# Write your MySQL query statement below
SELECT e.employee_id
FROM Employees AS e
LEFT JOIN Salaries as s
ON e.employee_id = s.employee_id
WHERE s.salary IS NULL
UNION
SELECT s.employee_id
FROM Salaries AS s
LEFT JOIN Employees as e
ON s.employee_id = e.employee_id
WHERE e.name IS NULL
ORDER BY employee_id
