# Write your MySQL query statement below
SELECT 
    name
From Customer
Where referee_id IS NULL OR referee_id<>2;