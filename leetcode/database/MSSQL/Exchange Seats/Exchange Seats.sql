select
    a.id,
    (
        CASE
            WHEN a.id % 2 = 0 THEN (
                CASE
                    WHEN b.student IS NULL THEN a.student
                    ELSE b.student
                END
            )
            else (
                CASE
                    WHEN c.student IS NULL THEN a.student
                    ELSE c.student
                END
            )
        end
    ) as student
from
    seat as a
    left join seat as b on a.id = b.id + 1
    left join seat as c on a.id = c.id - 1