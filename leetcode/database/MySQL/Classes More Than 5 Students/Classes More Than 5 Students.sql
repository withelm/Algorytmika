# Write your MySQL query statement below
select
    class
from
    (
        select
            student,
            class
        from
            courses
        group by
            student,
            class
    ) as k
group by
    class
having
    count(class) >= 5