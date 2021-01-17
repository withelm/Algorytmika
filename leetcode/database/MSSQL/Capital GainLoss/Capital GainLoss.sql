/* Write your T-SQL query statement below */
select
    a.stock_name,
    sum(a.price - b.price) as capital_gain_loss
from
    (
        select
            stock_name,
            price,
            ROW_NUMBER() OVER(
                PARTITION BY s.stock_name
                ORDER BY
                    s.operation_day
            ) AS stockRank
        from
            Stocks as s
        where
            operation = 'Buy'
    ) as b
    left join (
        select
            stock_name,
            price,
            ROW_NUMBER() OVER(
                PARTITION BY s.stock_name
                ORDER BY
                    s.operation_day
            ) AS stockRank
        from
            Stocks as s
        where
            operation = 'Sell'
    ) as a on a.stockRank = b.stockRank
    and a.stock_name = b.stock_name
group by
    a.stock_name