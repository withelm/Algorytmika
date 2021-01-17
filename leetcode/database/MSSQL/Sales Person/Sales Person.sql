/* Write your T-SQL query statement below */
select
    name
from
    salesperson
where
    sales_id not in (
        select
            s.sales_id
        from
            salesperson as s
            left join orders as o on s.sales_id = o.sales_id
            left join company as c on o.com_id = c.com_id
        where
            c.name = 'RED'
    )