CREATE FUNCTION getNthHighestSalary(@N INT) RETURNS INT AS BEGIN RETURN (
    Select
        ISNULL(
            (
                Select
                    distinct Salary
                from
                    employee
                order by
                    salary desc OFFSET @N - 1 ROWS
                FETCH FIRST
                    1 ROW ONLY
            ),
            NULL
        ) as SecondHighestSalary
);

END