SELECT COUNT(DISTINCT movie_id) AS NumberOfMoviesWith10Rating
FROM ratings
WHERE rating = 10.0;

