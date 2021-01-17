/* Write your T-SQL query statement below */
update
    salary
set
    sex = CASE
        WHEN sex = 'm' THEN 'f'
        ELSE 'm'
    END