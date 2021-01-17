select
    p.product_id,
    ROUND(sum(u.units * p.price) / sum(u.units + 0.0), 2) as average_price
from
    Prices as p
    left join UnitsSold as u on p.product_id = u.product_id
    and u.purchase_date >= p.start_date
    and u.purchase_date <= p.end_date
group by
    p.product_id