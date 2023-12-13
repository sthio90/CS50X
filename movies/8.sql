SELECT name FROM people WHERE id IN (SELECT person_id FROM movies JOIN stars ON id = movie_id WHERE title = 'Toy Story');
