/* Write your T-SQL query statement below */
select
    apples.sale_date,
    SUM(apples.sold_num - oranges.sold_num) as diff
from
    Sales as apples
    left join Sales as oranges on apples.sale_date = oranges.sale_date
    and apples.fruit <> oranges.fruit
where
    apples.fruit = 'apples'
    and oranges.fruit = 'oranges'
group by
    apples.sale_date
order by
    apples.sale_date