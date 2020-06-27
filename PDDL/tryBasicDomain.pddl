(define (domain planificador)
	(:requirements :adl :typing)
	(:types ejercicio - object
			dia - object
			nivel - object
	)
	(:predicates
		(preparador ?p - ejercicio ?e - ejercicio) ;; p prepara a e
		(diaAnterior ?d1 - dia ?d2 - dia)
		(diaActual ?d - dia)
		(nivelPosterior ?n - nivel ?n1 - nivel) ;; n1 es el nivel posterior a n
		(nivelActual ?e - ejercicio ?n - nivel) ;; n es el nivel actual del ejercicio e
		(subidoNivel ?e - ejercicio)
		(ejercicioHoy ?e - ejercicio)
	)

	(:action realizarEjercicio
		:parameters (?e - ejercicio)
		:precondition (and
							(not (ejercicioHoy ?e))
							(forall (?p - ejercicio)
										(not (and (preparador ?p ?e) (not (ejercicioHoy ?p))))
							)
					  )
	    :effect (ejercicioHoy ?e) 		
	)

	(:action subirNivel
		:parameters (?e - ejercicio
					 ?n - nivel
					 ?n1 - nivel)
		:precondition (and
							(ejercicioHoy ?e)
							(nivelActual ?e ?n)
							(nivelPosterior ?n ?n1)
							(not (subidoNivel ?e))
					  )
		:effect (and
					(not (nivelActual ?e ?n))
					(nivelActual ?e ?n1)
					(subidoNivel ?e)
				)
	)

	(:action pasarDia
		:parameters (?d1 ?d2 - dia)
		:precondition (and
						(diaActual ?d1)
						(diaAnterior ?d1 ?d2)
					  )
		:effect (and
					(not (diaActual ?d1))
					(diaActual ?d2)
					(forall (?e - ejercicio)
							(when (ejercicioHoy ?e)
								  (not (ejercicioHoy ?e)))
				    )
    		        (forall (?e - ejercicio)
    		        		(when (subidoNivel ?e)
    		        			  (not (subidoNivel ?e)))
    			    )
				)
	)
)