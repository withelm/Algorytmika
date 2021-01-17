select
    a as post_id,
    sum(
        CASE
            when b IS NULL then 0
            else 1
        end
    ) as number_of_comments
from
    (
        select
            distinct s.sub_id as a,
            ss.sub_id as b,
            ss.parent_id as c
        from
            Submissions as s
            left join Submissions as ss on s.sub_id = ss.parent_id
        where
            s.parent_id is NULL
    ) as A
group by
    a
order by
    a