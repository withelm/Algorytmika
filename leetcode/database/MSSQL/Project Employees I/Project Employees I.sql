/* Write your T-SQL query statement below */
select
    p.project_id,
    ROUND(avg(e.experience_years + 0.0), 2) as average_years
from
    Project as p
    left join Employee as e on p.employee_id = e.employee_id
group by
    p.project_id