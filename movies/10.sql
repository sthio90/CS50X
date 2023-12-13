SELECT DISTINCT name FROM people WHERE people.id IN (SELECT directors.movie_id FROM directors JOIN ratings ON directors.movie_id = ratings.movie_id WHERE rating > 9.0);
