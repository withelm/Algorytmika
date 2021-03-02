with a (Id, Month, Salary) as (
    select
        Employee.Id,
        Month,
        Salary
    from
        Employee
        left join (
            select
                id,
                max(Month) as num
            from
                Employee
            group by
                id
        ) as a on a.id = Employee.id
        and a.num = Employee.Month
    where
        a.id is NULL
)
select
    a.Id,
    a.Month,
    (
        ISNULL(a.Salary, 0) + ISNULL(b.Salary, 0) + ISNULL(c.Salary, 0)
    ) as Salary
from
    a
    left join a as b on a.Month = b.Month + 1
    and a.Id = b.Id
    left join a as c on b.Month = c.Month + 1
    and b.Id = c.Id
order by
    a.Id,
    a.Month desc