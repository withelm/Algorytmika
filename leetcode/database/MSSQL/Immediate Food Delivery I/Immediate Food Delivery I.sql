/* Write your T-SQL query statement below */
select
    (
        ROUND(
            100 * sum(
                CASE
                    WHEN order_date = customer_pref_delivery_date THEN 1.0
                    ELSE 0.0
                END
            ) / count(1),
            2
        )
    ) as immediate_percentage
from
    Delivery