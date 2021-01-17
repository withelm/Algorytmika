/* Write your T-SQL query statement below */
select
    p.product_name,
    sum(o.unit) as unit
from
    Orders as o
    left join Products as p on o.product_id = p.product_id
where
    YEAR(o.order_date) = 2020
    and month(o.order_date) = 2
group by
    p.product_name
having
    sum(o.unit) >= 100