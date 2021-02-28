/* Write your T-SQL query statement below */
select
	b.id,
	b.company,
	b.salary
from
	(
		select
			*,
			ROW_NUMBER() OVER(
				partition by Company
				order by
					Salary
			) as num
		from
			Employee
	) as b
	left join (
		select
			a.Company,
			num / 2 as num
		from
			(
				select
					a.Company,
					max(num) as num
				from
					(
						select
							*,
							ROW_NUMBER() OVER(
								partition by Company
								order by
									Salary
							) as num
						from
							Employee
					) as a
				group by
					a.Company
			) as a
		where
			num % 2 = 0
		union
		all
		select
			a.Company,
			num / 2 + 1 as num
		from
			(
				select
					a.Company,
					max(num) as num
				from
					(
						select
							*,
							ROW_NUMBER() OVER(
								partition by Company
								order by
									Salary
							) as num
						from
							Employee
					) as a
				group by
					a.Company
			) as a
		where
			num % 2 = 0
	) as a on a.Company = b.Company
	and a.num = b.num
where
	a.num is not null
union
all
select
	b.id,
	b.company,
	b.salary
from
	(
		select
			*,
			ROW_NUMBER() OVER(
				partition by Company
				order by
					Salary
			) as num
		from
			Employee
	) as b
	left join (
		select
			a.Company,
			num / 2 + 1 as num
		from
			(
				select
					a.Company,
					max(num) as num
				from
					(
						select
							*,
							ROW_NUMBER() OVER(
								partition by Company
								order by
									Salary
							) as num
						from
							Employee
					) as a
				group by
					a.Company
			) as a
		where
			num % 2 = 1
	) as a on a.Company = b.Company
	and a.num = b.num
where
	a.num is not null