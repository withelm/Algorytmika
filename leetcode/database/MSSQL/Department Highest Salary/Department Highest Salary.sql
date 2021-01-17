select
    dName as Department,
    eName as Employee,
    Salary
from
    (
        select
            d.Name as dName,
            e.Name as eName,
            RANK() OVER(
                PARTITION BY d.Name
                ORDER BY
                    e.Salary DESC
            ) AS rank,
            e.Salary
        from
            Employee as e
            left join Department as d on e.DepartmentId = d.Id
    ) as A
where
    rank = 1
    and dName is NOT NULL