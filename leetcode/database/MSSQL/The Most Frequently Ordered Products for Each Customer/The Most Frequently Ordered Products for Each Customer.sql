/* Write your T-SQL query statement below */
with a as (
    select
        customer_id,
        product_id,
        RANK() OVER(
            PARTITION By customer_id
            ORDER BY
                count(1) desc
        ) AS rank_num
    from
        Orders
    group by
        customer_id,
        product_id
)
select
    customer_id,
    a.product_id,
    Products.product_name
from
    a
    left join Products on a.product_id = Products.product_id
where
    rank_num = 1