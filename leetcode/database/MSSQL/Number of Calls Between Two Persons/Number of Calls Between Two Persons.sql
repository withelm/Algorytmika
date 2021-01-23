/* Write your T-SQL query statement below */
select
    from_id as person1,
    to_id as person2,
    count(1) as call_count,
    sum(duration) as total_duration
from
    (
        select
            (
                CASE
                    WHEN from_id < to_id THEN from_id
                    ELSE to_id
                END
            ) as from_id,
            (
                CASE
                    WHEN from_id > to_id THEN from_id
                    ELSE to_id
                END
            ) as to_id,
            duration
        from
            Calls
    ) as k
group by
    from_id,
    to_id