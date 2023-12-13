SELECT title
FROM movies
INNER JOIN ratings ON movies.id = ratings.movie_id
WHERE movies.id IN (
    SELECT stars.movie_id
    FROM stars
    INNER JOIN people ON stars.person_id = people.id
    WHERE people.name = 'Chadwick Boseman'
)
ORDER BY ratings.rating DESC
LIMIT 5;
