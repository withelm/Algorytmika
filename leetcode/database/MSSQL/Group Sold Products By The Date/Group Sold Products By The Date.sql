/* Write your T-SQL query statement below */
select
    A.sell_date,
    count(1) as num_sold,
    STRING_AGG(A.product, ',') as products
from
    (
        select
            A.sell_date,
            A.product
        from
            Activities as A
        group by
            A.sell_date,
            A.product
    ) as A
group by
    A.sell_date
order by
    A.sell_date