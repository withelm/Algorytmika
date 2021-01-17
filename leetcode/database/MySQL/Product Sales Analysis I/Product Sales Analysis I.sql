/* Write your T-SQL query statement below */
select
    p.product_name,
    s.year,
    s.price
from
    Sales as s
    LEFT JOIN Product as p on s.product_id = p.product_id