/* Write your T-SQL query statement below */
select
    DISTINCT con.user_id
from
    Confirmations as con
    left join Confirmations as con2 on con.user_id = con2.user_id
    and con.time_stamp < con2.time_stamp
where
    DATEDIFF (second, con.time_stamp, con2.time_stamp) <= 60 * 60 * 24
order by
    con.user_id