(define (problem test-03) (:domain planificador)
	(:objects
				ej1 ej2 ej3 ej4 ej5 ej6 ej7 - ejercicio
	          	d1 d2 d3 d4 d5 d6 d7 d8 d9 d10 d11 d12 d13 d14 d15 - dia
    )

    (:init
    	(precursor ej3 ej2)

    	(preparador ej1 ej2)

		(diaAnterior d1 d2)
		(diaAnterior d2 d3)
		(diaAnterior d3 d4)
		(diaAnterior d4 d5)
		(diaAnterior d5 d6)
		(diaAnterior d6 d7)
		(diaAnterior d7 d8)
		(diaAnterior d8 d9)
		(diaAnterior d9 d10)
		(diaAnterior d10 d11)
		(diaAnterior d11 d12)
		(diaAnterior d12 d13)
		(diaAnterior d13 d14)
		(diaAnterior d14 d15)

		(diaActual d1)

		(= (nivelEjercicio ej1) 1)
		(= (nivelEjercicio ej2) 1)
		(= (nivelEjercicio ej3) 1)
		(= (nivelEjercicio ej4) 1)
		(= (nivelEjercicio ej5) 1)
		(= (nivelEjercicio ej6) 1)
		(= (nivelEjercicio ej7) 1)

		(= (contadorEjercicios) 0)
    )

    (:goal (and
    			(= (nivelEjercicio ej1) 3)
    			(= (nivelEjercicio ej2) 4)
    			(= (nivelEjercicio ej3) 3)
    			(= (nivelEjercicio ej4) 3)
    			(= (nivelEjercicio ej5) 3)
    			(= (nivelEjercicio ej6) 3)
    			(= (nivelEjercicio ej7) 3)
    		)
	)
)
