select
    *
from
    (
        select
            ss.student_id,
            ss.student_name,
            s.subject_name,
            sum(
                CASE
                    WHEN e.subject_name IS NULL THEN 0
                    else 1
                end
            ) as attended_exams
        from
            Subjects as s
            left join Students as ss on s.subject_name <> cast(ss.student_id as varchar(100))
            left join Examinations as e on s.subject_name = e.subject_name
            and ss.student_id = e.student_id
        group by
            ss.student_id,
            ss.student_name,
            s.subject_name
    ) as A
where
    student_id is NOT NULL