/* Write your T-SQL query statement below */
select
    Students.id,
    Students.name
from
    Students
    left join Departments on Departments.id = Students.department_id
where
    Departments.id IS NULL