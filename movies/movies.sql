SELECT title FROM movies WHERE year = 2008;

SELECT birth FROM people WHERE name = "Emma Stone";

SELECT title FROM movies WHERE year >= 2018 ORDER BY title ASC;

SELECT COUNT(rating) FROM ratings WHERE rating = 10.0;

SELECT title, year FROM movies WHERE title LIKE "Harry Potter%" ORDER BY year;

SELECT AVG (rating) AS Average FROM ratings
JOIN movies ON ratings.movie_id = movies.id
WHERE year = 2012;

SELECT movies.title, ratings.rating
FROM ratings JOIN movies ON movies.id = ratings.movie_id
WHERE movies.year = 2010 ORDER BY ratings.rating DESC, movies.title ASC;

SELECT people.name FROM people, stars, movies
WHERE people.id = stars.person_id
AND stars.movie_id = movies.id AND movies.title = "Toy Story";

SELECT DISTINCT (people.name) FROM stars
JOIN people ON people.id = stars.person_id
JOIN movies ON movies.id = stars.movie_id
WHERE movies.year = 2004 ORDER BY people.birth ASC;

SELECT DISTINCT (name)
FROM people JOIN directors ON directors.person_id = people.id
JOIN movies ON directors.movie_id = movies.id
JOIN ratings ON movies.id = ratings.movie_id WHERE rating >= 9.0;

SELECT movies.title FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
JOIN ratings ON movies.id = ratings.movie_id
WHERE people.name = 'Chadwick Boseman'
ORDER BY rating DESC
LIMIT 5;

SELECT movies.title FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON movies.id = stars.movie_id
WHERE people.name = 'Bradley Cooper'
INTERSECT
SELECT movies.title FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON movies.id = stars.movie_id
WHERE people.name = 'Jennifer Lawrence';

SELECT DISTINCT (name) FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON movies.id = stars.movie_id
WHERE movies.title IN
(SELECT DISTINCT (movies.title) FROM people
JOIN stars On people.id = stars.person_id
JOIN movies ON movies.id = stars.movie_id
WHERE people.name = 'Kevin Bacon'AND people.birth = 1958)
AND people.name != 'Kevin Bacon';
