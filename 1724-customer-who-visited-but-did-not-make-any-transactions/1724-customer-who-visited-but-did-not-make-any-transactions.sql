# Write your MySQL query statement below
select v.customer_id,count(customer_id) as count_no_trans
from Visits v left join Transactions t
using(visit_id)
where t.transaction_id is null
group by v.customer_id
