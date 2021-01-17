/* Write your T-SQL query statement below */
select
    '[0-5>' as bin,
    count(1) as total
from
    Sessions
where
    duration < 5 * 60
union
all
select
    '[5-10>' as bin,
    count(1) as total
from
    Sessions
where
    duration < 10 * 60
    and duration >= 5 * 60
union
all
select
    '[10-15>' as bin,
    count(1) as total
from
    Sessions
where
    duration < 15 * 60
    and duration >= 10 * 60
union
all
select
    '15 or more' as bin,
    count(1) as total
from
    Sessions
where
    duration >= 15 * 60