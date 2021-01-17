/* Write your T-SQL query statement below */
select
    DISTINCT a.id as customer_id,
    a.name
from
    (
        select
            year(o.order_date) as a,
            month(o.order_date) as b,
            c.name,
            c.customer_id as id,
            sum(p.price * o.quantity) as c
        from
            Orders as o
            left join Product as p on o.product_id = p.product_id
            left join Customers as c on c.customer_id = o.customer_id
        group by
            year(o.order_date),
            month(o.order_date),
            c.name,
            c.customer_id
    ) as A
where
    (
        A.a = 2020
        and (A.b = 6)
        and c >= 100
    )
INTERSECT
select
    DISTINCT a.id as customer_id,
    a.name
from
    (
        select
            year(o.order_date) as a,
            month(o.order_date) as b,
            c.name,
            c.customer_id as id,
            sum(p.price * o.quantity) as c
        from
            Orders as o
            left join Product as p on o.product_id = p.product_id
            left join Customers as c on c.customer_id = o.customer_id
        group by
            year(o.order_date),
            month(o.order_date),
            c.name,
            c.customer_id
    ) as A
where
    (
        A.a = 2020
        and (A.b = 7)
        and c >= 100
    )