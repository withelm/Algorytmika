select
    IsNULL(
        ROUND (
            (
                select
                    sum(a)
                from
                    (
                        select
                            user_id as b,
                            count(1) as a
                        from
                            (
                                select
                                    user_id,
                                    session_id
                                from
                                    Activity
                                where
                                    activity_date >= '2019-06-28'
                                    and activity_date <= '2019-07-27'
                                group by
                                    user_id,
                                    session_id
                            ) as A
                        group by
                            user_id
                    ) as B
            ) / (
                (
                    select
                        count(a)
                    from
                        (
                            select
                                user_id as b,
                                count(1) as a
                            from
                                (
                                    select
                                        user_id,
                                        session_id
                                    from
                                        Activity
                                    where
                                        activity_date >= '2019-06-28'
                                        and activity_date <= '2019-07-27'
                                    group by
                                        user_id,
                                        session_id
                                ) as A
                            group by
                                user_id
                        ) as B
                ) + 0.0
            ),
            2
        ),
        0
    ) as average_sessions_per_user