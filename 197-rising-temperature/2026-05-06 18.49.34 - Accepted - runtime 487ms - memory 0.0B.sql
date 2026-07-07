# Write your MySQL query statement below
select a.id from Weather as a   # one copy for today
join Weather as b       # one copy for yesterday
on datediff(a.recordDate, b.recordDate) = 1  # check diff in dates
where a.temperature > b.temperature;  # today's temp should be > yesterday's temp