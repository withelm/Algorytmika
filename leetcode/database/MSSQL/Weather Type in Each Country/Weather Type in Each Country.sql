select
    c.country_name,
    CASE
        WHEN avg(weather_state + 0.0) <= 15 THEN 'Cold'
        WHEN avg(weather_state + 0.0) >= 25 THEN 'Hot'
        else 'Warm'
    END as weather_type
from
    Weather as w
    left join Countries as c on c.country_id = w.country_id
where
    year(w.day) = 2019
    and month(w.day) = 11
group by
    c.country_name