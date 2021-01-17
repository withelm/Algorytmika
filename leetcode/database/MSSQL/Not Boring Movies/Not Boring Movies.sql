/* Write your T-SQL query statement below */
select
    *
from
    cinema
where
    id % 2 = 1
    AND description <> 'boring'
order by
    rating desc