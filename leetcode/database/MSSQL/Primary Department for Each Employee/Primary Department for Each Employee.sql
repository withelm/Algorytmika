with source as (
    select
        employee_id,
        max(department_id) as department_id
    from
        Employee
    group by
        employee_id
    having
        count(1) = 1
    union
    all
    select
        employee_id,
        department_id
    from
        Employee
    where
        primary_flag = 'Y'
)
select
    *
from
    source
group by
    employee_id,
    department_id