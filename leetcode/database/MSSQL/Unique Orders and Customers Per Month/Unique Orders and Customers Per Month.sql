select
    A.month,
    A.order_count,
    B.customer_count
from
    (
        select
            A.month,
            count(A.order_id) as order_count
        from
            (
                select
                    FORMAT(o.order_date, 'yyyy-MM') as month,
                    o.order_id
                from
                    Orders as o
                where
                    o.invoice > 20
                group by
                    FORMAT(o.order_date, 'yyyy-MM'),
                    o.order_id
            ) as A
        group by
            A.month
    ) as A
    left join (
        select
            B.month,
            count(B.customer_id) as customer_count
        from
            (
                select
                    FORMAT(o.order_date, 'yyyy-MM') as month,
                    o.customer_id
                from
                    Orders as o
                where
                    o.invoice > 20
                group by
                    FORMAT(o.order_date, 'yyyy-MM'),
                    o.customer_id
            ) as B
        group by
            B.month
    ) as B on A.month = B.month