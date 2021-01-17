# Write your MySQL query statement below
delete from
    Person
where
    Id not in (
        select
            A.Id
        from
            (
                select
                    min(Id) as Id
                from
                    Person
                group by
                    Email
            ) A
    )