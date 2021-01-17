/* Write your T-SQL query statement below */
select
    e.employee_id
from
    Employees as e
    left join Employees as e2 on e.manager_id = e2.employee_id
    left join Employees as e3 on e2.manager_id = e3.employee_id
    left join Employees as e4 on e3.manager_id = e4.employee_id
where
    e4.manager_id = 1
    and e.employee_id <> 1
group by
    e.employee_id