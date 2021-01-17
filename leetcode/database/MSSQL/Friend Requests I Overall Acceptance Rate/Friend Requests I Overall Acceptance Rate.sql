DECLARE @a DECIMAL = (
    select
        count(1)
    from
        (
            select
                count(1) as k
            from
                request_accepted
            group by
                requester_id,
                accepter_id
        ) as N
)
DECLARE @b DECIMAL = (
    select
        count(1)
    from
        (
            select
                count(1) as k
            from
                friend_request
            group by
                sender_id,
                send_to_id
        ) as A
) 
if (@b = 0) BEGIN
select
    CAST(ROUND(0, 2) as NUMERIC(12, 2)) as accept_rate
END
ELSE 
BEGIN
select
    CAST(ROUND(@a / @b, 2) as NUMERIC(12, 2)) as accept_rate
END