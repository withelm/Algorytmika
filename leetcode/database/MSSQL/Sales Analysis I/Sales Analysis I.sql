select
    seller_id
from
    Sales
group by
    seller_id
having
    sum(price) = (
        select
            top 1 sum(price)
        from
            Sales
        group by
            seller_id
        ORDER BY
            sum(price) DESC
    )
ORDER BY
    sum(price) DESC