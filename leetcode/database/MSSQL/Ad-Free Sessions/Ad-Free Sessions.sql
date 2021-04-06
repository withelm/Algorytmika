select
    session_id
from
    Playback
where
    session_id not in (
        select
            session_id
        from
            Playback
            left join Ads on Playback.customer_id = Ads.customer_id
        where
            start_time <= timestamp
            and timestamp <= end_time
        group by
            session_id
    )