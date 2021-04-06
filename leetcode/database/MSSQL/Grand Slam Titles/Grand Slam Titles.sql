with source as (
    select
        Wimbledon as player_id
    from
        Championships
    union
    all
    select
        Fr_open as player_id
    from
        Championships
    union
    all
    select
        US_open as player_id
    from
        Championships
    union
    all
    select
        Au_open as player_id
    from
        Championships
)
select
    k.player_id,
    player_name,
    k.grand_slams_count
from
    (
        select
            player_id,
            count(1) as grand_slams_count
        from
            source
        group by
            player_id
    ) as k
    left join Players on Players.player_id = k.player_id