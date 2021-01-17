/* Write your T-SQL query statement below */
select
    c.title
from
    TVProgram as t
    left join Content as c on t.content_id = c.content_id
where
    MONTH(t.program_date) = 6
    and YEAR(t.program_date) = 2020
    and c.Kids_content = 'Y'
    and c.content_type = 'Movies'
group by
    c.title