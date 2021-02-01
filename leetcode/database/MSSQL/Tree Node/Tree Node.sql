/* Write your T-SQL query statement below */
select
    *
from
    (
        select
            id,
            'Root' as Type
        from
            tree
        where
            p_id IS NULL
        union all
        select
            p_id as id,
            'Inner' as Type
        from
            tree
        where
            p_id IS NOT NULL
            and p_id not in (
                select
                    id
                from
                    tree
                where
                    p_id IS NULL
            )
        group by
            p_id
        union all
        select
            id,
            'Leaf' as TYPE
        from
            tree
        where
            id not in (
                select
                    p_id
                from
                    tree
                where
                    p_id IS NOT NULL
                group by
                    p_id
            )
            and id not in (
                select
                    id
                from
                    tree
                where
                    p_id IS NULL
            )
    ) as a
order by
    a.id