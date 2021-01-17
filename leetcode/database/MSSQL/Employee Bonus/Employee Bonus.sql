select
    Employee.name,
    Bonus.bonus
from
    Employee
    left join Bonus on Employee.empId = Bonus.empId
where
    Employee.empId not in (
        select
            Employee.empId
        from
            Employee
            left join Bonus on Employee.empId = Bonus.empId
        where
            Bonus.bonus > 1000
    )