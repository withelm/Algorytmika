/* Write your T-SQL query statement below */
select
    Product.name,
    sum(Invoice.rest) as rest,
    sum(Invoice.paid) as paid,
    sum(Invoice.canceled) as canceled,
    sum(Invoice.refunded) as refunded
from
    Invoice
    left join Product on Product.product_id = Invoice.product_id
group by
    Product.name