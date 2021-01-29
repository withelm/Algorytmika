select
    y.Id
from
    Weather as t
    left join Weather as y on DATEDIFF(day, t.recordDate, y.recordDate) = 1
where
    t.Temperature < y.Temperature