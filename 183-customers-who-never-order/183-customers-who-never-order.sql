# Write your MySQL query statement below
# way 1
# SELECT name AS Customers 
#    FROM Customers LEFT JOIN Orders ON Customers.id = Orders.customerId
#    WHERE customerId IS NULL;

# way 2 using Not NULL
     SELECT name AS Customers
     FROM Customers
     WHERE id NOT IN (SELECT customerId FROM Orders);
