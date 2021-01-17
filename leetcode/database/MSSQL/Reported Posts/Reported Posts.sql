/* Write your T-SQL query statement below */
select
    report_reason,
    sum(report_count) as report_count
from
    (
        select
            extra as report_reason,
            1 as report_count
        from
            Actions
        where
            action_date = '2019-07-04'
            and action = 'report'
        group by
            extra,
            post_id
    ) as A
group by
    report_reason