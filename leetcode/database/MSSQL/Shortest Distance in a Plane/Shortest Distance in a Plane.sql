/* Write your T-SQL query statement below */
select
    top 1 ROUND(
        sqrt((a.x - b.x) *(a.x - b.x) + (a.y - b.y) *(a.y - b.y)),
        2
    ) as shortest
from
    point_2d as a
    left join point_2d as b on a.x <> b.x
    OR a.y <> b.y
order by
    ROUND(
        sqrt((a.x - b.x) *(a.x - b.x) + (a.y - b.y) *(a.y - b.y)),
        2
    )