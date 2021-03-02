with q as (
    select
        *
    from
        Stadium
    where
        people >= 100
)
select
    *
from
    (
        select
            distinct a.*
        from
            q as a
            left join q as b on b.people >= 100
            left join q as c on c.people >= 100
        where
            (
                a.id - b.id = 1
                and a.id - c.id = 2
                and b.id - c.id = 1
            )
            or (
                b.id - a.id = 1
                and b.id - c.id = 2
                and a.id - c.id = 1
            )
            or (
                c.id - b.id = 1
                and c.id - a.id = 2
                and b.id - a.id = 1
            )
    ) as a
order by
    a.visit_date