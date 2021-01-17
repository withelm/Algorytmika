select
    s.product_id,
    p.product_name
from
    Sales as s
    left join Product as p on s.product_id = p.product_id
where
    s.sale_date >= '2019-01-01'
    and s.sale_date <= '2019-03-31'
except
select
    s.product_id,
    p.product_name
from
    Sales as s
    left join Product as p on s.product_id = p.product_id
where
    s.sale_date < '2019-01-01'
    or s.sale_date > '2019-03-31'