select
    name,
    mail
from
    Users
where
    user_id in (
        select
            user_id
        from
            (
                select
                    gold_medal as user_id
                from
                    Contests
                group by
                    gold_medal
                having
                    count(1) >= 3
                union
                all
                select
                    a.gold_medal as user_id
                from
                    Contests as a
                    left join Contests as b on a.contest_id = b.contest_id + 1
                    left join Contests as c on b.contest_id = c.contest_id + 1
                where
                    a.gold_medal in (b.gold_medal, b.silver_medal, b.bronze_medal)
                    and a.gold_medal in (c.gold_medal, c.silver_medal, c.bronze_medal)
                union
                all
                select
                    a.silver_medal as user_id
                from
                    Contests as a
                    left join Contests as b on a.contest_id = b.contest_id + 1
                    left join Contests as c on b.contest_id = c.contest_id + 1
                where
                    a.silver_medal in (b.gold_medal, b.silver_medal, b.bronze_medal)
                    and a.silver_medal in (c.gold_medal, c.silver_medal, c.bronze_medal)
                union
                all
                select
                    a.bronze_medal as user_id
                from
                    Contests as a
                    left join Contests as b on a.contest_id = b.contest_id + 1
                    left join Contests as c on b.contest_id = c.contest_id + 1
                where
                    a.bronze_medal in (b.gold_medal, b.silver_medal, b.bronze_medal)
                    and a.bronze_medal in (c.gold_medal, c.silver_medal, c.bronze_medal)
            ) as k
        group by
            user_id
    )