# Write your MySQL query statement below
SELECT firstName, lastName, city, state
FROM Person as p
LEFT OUTER JOIN Address as a
ON p.personId = a.personId
