/* Write your T-SQL query statement below */
select
    p.project_id as project_id
from
    Project as p
    left join Employee as e on p.employee_id = e.employee_id
group by
    p.project_id
having
    count(1) = (
        select
            max(A.c)
        from
            (
                select
                    count(1) as c
                from
                    Project
                group by
                    project_id
            ) as A
    )
order by
    count(1) desc