select
    a.contest_id,
    a.c as percentage
from
    (
        select
            contest_id,
            ROUND(
                (
                    (100.0 * count(1)) / (
                        select
                            count(1)
                        from
                            Users
                    )
                ),
                2
            ) as c
        from
            Register as r
        group by
            contest_id
    ) as a
order by
    a.c desc,
    a.contest_id