/* Write your T-SQL query statement below */
select
    (
        CASE
            WHEN Salaries.employee_id IS NULL THEN Employees.employee_id
            ELSE Salaries.employee_id
        END
    ) as employee_id
from
    Employees FULL
    OUTER JOIN Salaries on Salaries.employee_id = Employees.employee_id
where
    Salaries.employee_id is NULL
    OR Employees.employee_id is NULL
order by
    (
        CASE
            WHEN Salaries.employee_id IS NULL THEN Employees.employee_id
            ELSE Salaries.employee_id
        END
    )