select
    Trips.Request_at as Day,
    round(
        sum(
            CASE
                WHEN Trips.Status <> 'completed' THEN 1
                ELSE 0
            END
        ) / (count(1) + 0.0),
        2
    ) as 'Cancellation Rate'
from
    Trips
    left join Users as client on client.Users_Id = Trips.Client_Id
where
    client.Banned = 'NO'
    and (
        Trips.Request_at BETWEEN '2013-10-01'
        and '2013-10-03'
    )
group by
    Trips.Request_at
order by
    Trips.Request_at