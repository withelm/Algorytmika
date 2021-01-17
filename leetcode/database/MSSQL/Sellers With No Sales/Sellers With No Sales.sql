/* Write your T-SQL query statement below */
select
    seller_name
from
    Seller
where
    seller_id not in (
        select
            s.seller_id
        from
            Seller as s
            left join Orders as o on s.seller_id = o.seller_id
        where
            year(o.sale_date) = 2020
    )
order by
    seller_name