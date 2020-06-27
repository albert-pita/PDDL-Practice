(define (problem test-00) (:domain planificador)
	(:objects ej1 ej2 ej3 ej4 ej5 - ejercicio
	          d1 d2 d3 d4 d5 d6 d7 d8 d9 d10 d11 d12 d13 d14 d15 - dia
	          n1 n2 n3 n4 n5 n6 n7 n8 n9 n10 -  nivel
    )

    (:init
    	(preparador ej2 ej1)
    	(preparador ej3 ej2)
    	(preparador ej5 ej4)

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

		(nivelPosterior n1 n2)
		(nivelPosterior n2 n3)
		(nivelPosterior n3 n4)
		(nivelPosterior n4 n5)
		(nivelPosterior n5 n6)
		(nivelPosterior n6 n7)
		(nivelPosterior n7 n8)
		(nivelPosterior n8 n9)
		(nivelPosterior n9 n10)

		(nivelActual ej1 n1)
		(nivelActual ej2 n1)
		(nivelActual ej3 n1)
		(nivelActual ej4 n1)
		(nivelActual ej5 n1)
    )

    (:goal (and
    			(nivelActual ej1 n5)
    			(nivelActual ej2 n5)
    			(nivelActual ej3 n5)
    			(nivelActual ej4 n5)
    			(nivelActual ej5 n5)
    		)
	)
)