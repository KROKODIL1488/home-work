SELECT name
from users
where LENGTH(name) > 10;

SELECT LOWER(email) AS email
FROM users;

SELECT id, UPPER(name) AS name
FROM users;

SELECT CONCAT(first_name, ' ', last_name) AS full_name
FROM users;

SELECT SUBSTR(product_code, 1, 3) AS code
FROM products;

SELECT GROUP_CONCAT(category_name, ', ') AS categories
FROM categories;