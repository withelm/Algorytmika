/* Write your T-SQL query statement below */
select
    gender,
    day,
    SUM(score_points) OVER(
        PARTITION BY gender
        ORDER BY
            gender,
            day ROWS BETWEEN UNBOUNDED PRECEDING
            AND CURRENT ROW
    ) AS total
from
    Scores
order by
    gender,
    day