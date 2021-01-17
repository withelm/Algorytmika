select
    s.Score,
    DENSE_RANK() OVER(
        ORDER BY
            s.Score DESC
    ) AS Rank
from
    Scores as s