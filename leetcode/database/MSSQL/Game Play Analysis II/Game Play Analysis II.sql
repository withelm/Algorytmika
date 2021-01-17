select
    player_id,
    device_id
from
    (
        select
            player_id,
            device_id,
            ROW_NUMBER() OVER(
                PARTITION BY player_id
                order by
                    min(event_date)
            ) as rn
        from
            Activity
        group by
            player_id,
            device_id
    ) as A
where
    A.rn = 1