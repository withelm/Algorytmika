/* Write your T-SQL query statement below */
select
    e.name
from
    Employee as e
    left join Employee as e2 on e2.ManagerId = e.Id
group by
    e.Name
having
    count(1) >= 5