CREATE PROCEDURE promedioEdad()
  8 LANGUAGE plpgsql as $$
  7 DECLARE
  6         totalₚersonas INT;
  5         edadₚromedio NUMERIC;
  4 BEGIN
  3         SELECT COUNT() INTO total_personas, AVG(EXTRACT(YEAR FROM AGE(fecha_nacimiento))) INTO edad_promedio FROM personas;
  2         RAISE NOTICE 'total de personas: %, promedio de edad: %', total_p, edad_promedio;
  1 END;
140 $$;
