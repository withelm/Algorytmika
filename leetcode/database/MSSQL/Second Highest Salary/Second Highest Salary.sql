Select
    ISNULL(
        (
            Select
                distinct Salary
            from
                employee
            order by
                salary desc OFFSET 1 ROWS
            FETCH FIRST
                1 ROW ONLY
        ),
        NULL
    ) as Secondhighestsalary