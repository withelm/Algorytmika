select
    a.Num as ConsecutiveNums
from
    Logs as a
    left join Logs as b on a.Id = b.Id + 1
    left join Logs as c on b.Id = c.Id + 1
where
    a.Num = b.Num
    and b.Num = c.Num
group by
    a.Num