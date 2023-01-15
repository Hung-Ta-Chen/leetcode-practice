# Write your MySQL query statement below
UPDATE Salary AS s
SET s.sex =
    CASE s.sex
        WHEN 'm' THEN 'f'
        WHEN 'f' THEN 'm'
    END;
# WHERE s.sex IN ('m', 'f');
