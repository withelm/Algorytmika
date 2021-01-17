/* Write your T-SQL query statement below */
select
    activity_date as day,
    count(user_id) as active_users
from
    (
        select
            activity_date,
            user_id
        from
            Activity
        where
            activity_date >= '2019-06-28'
            and activity_date <= '2019-07-27'
        group by
            activity_date,
            user_id
    ) as A
group by
    activity_date