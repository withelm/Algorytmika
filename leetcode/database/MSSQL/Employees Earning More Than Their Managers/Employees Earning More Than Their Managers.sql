select
    Employee.Name as Employee
from
    Employee
    left join Employee as Employee2 on Employee.ManagerId = Employee2.Id
where
    Employee.Salary > Employee2.Salary