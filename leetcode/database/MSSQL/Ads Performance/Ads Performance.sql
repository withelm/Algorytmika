select
    ad_id,
    cast (
        CASE
            WHEN sum(ISNULL(c, 0) + ISNULL(v, 0)) = 0 THEN 0
            ELSE round(
                sum(isNULL(c, 0) + 0.0) / sum(ISNULL(c, 0) + ISNULL(v, 0)) * 100,
                2
            )
        END as numeric(12, 2)
    ) as ctr
from
    (
        select
            ad_id,
            CASE
                WHEN action = 'Clicked' THEN count(1)
            END as c,
            CASE
                WHEN action = 'Ignored' THEN count(1)
            END as i,
            CASE
                WHEN action = 'Viewed' THEN count(1)
            END as v
        from
            Ads
        group by
            ad_id,
            action
    ) as A
group by
    ad_id
order by
    ctr desc,
    ad_id