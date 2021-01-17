select
    a.player_id,
    a.event_date,
    SUM(a.games_played) OVER(
        Partition by a.player_id
        order by
            a.event_date
    ) as games_played_so_far
from
    Activity as a
order by
    a.player_id,
    a.event_date