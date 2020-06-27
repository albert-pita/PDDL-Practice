(define (problem test-04) (:domain planificador)
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
		
		(= (tiempoEjercicio ej1) 20)
		(= (tiempoEjercicio ej2) 20)
		(= (tiempoEjercicio ej3) 10)
		(= (tiempoEjercicio ej4) 10)
		(= (tiempoEjercicio ej5) 10)
		(= (tiempoEjercicio ej6) 10)
        (= (tiempoEjercicio ej7) 20)

		(= (tiempoEjercitado) 0)
    )

    (:goal (and
    			(= (nivelEjercicio ej1) 5)
    			(= (nivelEjercicio ej2) 5)
    			(= (nivelEjercicio ej3) 5)
    			(= (nivelEjercicio ej4) 5)
    			(= (nivelEjercicio ej5) 5)
    			(= (nivelEjercicio ej6) 5)
    			(= (nivelEjercicio ej7) 5)
    		)
	)
)
