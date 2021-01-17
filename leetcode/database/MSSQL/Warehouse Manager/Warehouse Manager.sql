/* Write your T-SQL query statement below */
select
    Warehouse.name as warehouse_name,
    sum(
        Warehouse.units * Products.Width * Products.Length * Products.Height
    ) as volume
from
    Warehouse
    left join Products on Warehouse.product_id = Products.product_id
group by
    Warehouse.name