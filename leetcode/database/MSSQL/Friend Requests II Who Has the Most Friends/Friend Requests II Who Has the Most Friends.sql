/* Write your T-SQL query statement below */
select
    top 1 id as id,
    count(1) as num
from
    (
        select
            requester_id as id
        from
            request_accepted
        union all
        select
            accepter_id as id
        from
            request_accepted
    ) as a
group by
    a.id
order by
    count(1) desc