/* Write your T-SQL query statement below */
select
    LOWER(TRIM(product_name)) as product_name,
    FORMAT (sale_date, 'yyyy-MM') as sale_date,
    count(1) as total
from
    Sales as s
group by
    LOWER(TRIM(product_name)),
    FORMAT (sale_date, 'yyyy-MM')
order by
    product_name,
    sale_date