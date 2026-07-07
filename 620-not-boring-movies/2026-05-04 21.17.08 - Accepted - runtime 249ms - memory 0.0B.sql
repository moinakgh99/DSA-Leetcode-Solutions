# Write your MySQL query statement below
select * from Cinema as a
where id % 2 != 0 and description != "boring"
order by rating desc;