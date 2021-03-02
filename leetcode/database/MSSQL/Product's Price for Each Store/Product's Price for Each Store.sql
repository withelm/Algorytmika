with a as (
    select
        product_id
    from
        Products as a
    group by
        product_id
)
select
    a.product_id,
    b.price as store1,
    c.price as store2,
    d.price as store3
from
    a
    left join Products as b on a.product_id = b.product_id
    and b.store = 'store1'
    left join Products as c on a.product_id = c.product_id
    and c.store = 'store2'
    left join Products as d on a.product_id = d.product_id
    and d.store = 'store3'