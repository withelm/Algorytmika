/* Write your T-SQL query statement below */
select
    a.seat_id
from
    cinema as a
    left join cinema as b on abs(a.seat_id - b.seat_id) = 1
where
    a.free = 1
    and b.free = 1
group by
    a.seat_id