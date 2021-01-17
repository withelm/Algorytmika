/* Write your T-SQL query statement below */
select
    employee_id,
    (
        select
            count(1)
        from
            Employee as k
        where
            k.team_id = Employee.team_id
    ) as team_size
from
    Employee