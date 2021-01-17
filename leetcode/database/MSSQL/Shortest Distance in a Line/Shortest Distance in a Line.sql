/* Write your T-SQL query statement below */
select
    min(abs(a.x - b.x)) as shortest
from
    (
        select
            ROW_NUMBER() OVER(
                ORDER BY
                    x
            ) AS id,
            x
        from
            point
    ) as a
    left join (
        select
            ROW_NUMBER() OVER(
                ORDER BY
                    x
            ) AS id,
            x
        from
            point
    ) as b on a.id = b.id + 1