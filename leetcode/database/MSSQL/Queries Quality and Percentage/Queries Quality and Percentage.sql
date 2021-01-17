/* Write your T-SQL query statement below */
select
    query_name,
    ROUND(sum((0.0 + rating) / position) / count(1), 2) as quality,
    round(
        100 * sum(
            CASE
                WHEN rating < 3 THEN 1.0
                ELSE 0.0
            END
        ) / count(1),
        2
    ) as poor_query_percentage
from
    (
        select
            distinct *
        from
            Queries as q
    ) as a
group by
    query_name