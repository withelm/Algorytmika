/* Write your T-SQL query statement below */
select
    date_id,
    make_name,
    sum(unique_leads) as unique_leads,
    sum(unique_partners) as unique_partners
from
    (
        (
            select
                date_id,
                make_name,
                1 as unique_leads,
                0 as unique_partners
            from
                DailySales
            group by
                date_id,
                make_name,
                lead_id
        )
        union all (
            select
                date_id,
                make_name,
                0 as unique_leads,
                1 as unique_partners
            from
                DailySales
            group by
                date_id,
                make_name,
                partner_id
        )
    ) as k
group by
    date_id,
    make_name