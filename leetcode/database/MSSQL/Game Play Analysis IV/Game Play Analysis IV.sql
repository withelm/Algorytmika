select
    ROUND(
        (
            select
                count(1) + 0.0
            from
                (
                    select
                        distinct a.player_id
                    from
                        Activity as a
                        left join (
                            select
                                player_id,
                                min(event_date) as event_date
                            from
                                Activity
                            group by
                                player_id
                        ) as b on a.event_date = DATEADD(DAY, 1, b.event_date)
                        and a.player_id = b.player_id
                    where
                        b.player_id IS NOT NULL
                ) as A
        ) / (
            select
                count(1)
            from
                (
                    select
                        a.player_id
                    from
                        Activity as a
                    group by
                        a.player_id
                ) as A
        ),
        2
    ) as fraction