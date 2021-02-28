select
    Department,
    Employee,
    Salary
from
    (
        select
            Department.Name as Department,
            Employee.Name as Employee,
            Employee.Salary,
            DENSE_RANK() Over(
                PARTITION BY Department.Name
                order by
                    Employee.Salary desc
            ) as num
        from
            Employee
            left join Department on Employee.DepartmentId = Department.Id
        where
            Department.Name is not null
    ) as a
where
    a.num < 4