/* Write your T-SQL query statement below */
select
    *,
    (
        CASE
            WHEN (
                x + y > z
                and x + z > y
                and z + y > x
            ) THEN 'Yes'
            ELSE 'No'
        END
    ) as triangle
from
    triangle