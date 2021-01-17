select
    d.dept_name,
    sum(
        CASE
            WHEN s.dept_id IS NOT NULL THEN 1
            ELSE 0
        END
    ) as student_number
from
    department as d
    left join student as s on d.dept_id = s.dept_id
group by
    d.dept_name
order by
    student_number desc,
    d.dept_name