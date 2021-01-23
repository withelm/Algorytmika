/* Write your T-SQL query statement below */
select
    EmpTo.employee_id,
    EmpTo.name,
    count(1) as reports_count,
    round(avg(EmpFrom.age + 0.0), 0) as average_age
from
    Employees as EmpFrom
    left join Employees as EmpTo on EmpFrom.reports_to = EmpTo.employee_id
where
    EmpFrom.reports_to IS NOT NULL
group by
    EmpTo.employee_id,
    EmpTo.name
order by
    EmpTo.employee_id