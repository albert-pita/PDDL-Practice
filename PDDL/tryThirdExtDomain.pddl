(define (domain planificador)
	(:requirements :adl :typing :fluents)
	(:types ejercicio - object
			dia - object
	)
	(:functions
		(nivelEjercicio ?e - ejercicio)
		(contadorEjercicios)
	)
	(:predicates
		(precursor ?p - ejercicio ?e - ejercicio) ;; p precursa a e
		(preparador ?p - ejercicio ?e - ejercicio) ;; p prepara a e
		(diaAnterior ?d1 - dia ?d2 - dia)
		(diaActual ?d - dia)
		(subidoNivel ?e - ejercicio)
		(ejercicioHoy ?e - ejercicio)
		(ultimoEjercicio ?e - ejercicio)
	)

	(:action realizarEjercicio
		:parameters (?e - ejercicio)
		:precondition (and
							(forall (?p - ejercicio)
										(not (and (precursor ?p ?e) (not (ultimoEjercicio ?p))))
							)
							(not (ejercicioHoy ?e))
							(forall (?p - ejercicio)
										(not (and (preparador ?p ?e) (not (ejercicioHoy ?p))))
							)
							(< (contadorEjercicios) 6)
					  )
	    :effect (and
	    			(forall (?l - ejercicio)
	    					(when (ultimoEjercicio ?l) (not (ultimoEjercicio ?l)))
	    			)
	    			(ultimoEjercicio ?e)
	    			(ejercicioHoy ?e)

	    			(increase (contadorEjercicios) 1)
	    		)
	)

	(:action subirNivel
		:parameters (?e - ejercicio)
		:precondition (and
							(ejercicioHoy ?e)
							(not (subidoNivel ?e))
					  )
		:effect (and
					(when (< (nivelEjercicio ?e) 10) (increase (nivelEjercicio ?e) 1))
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
				    		(when (ultimoEjercicio ?e)
				    		      (not (ultimoEjercicio ?e)))
    		        )
    		        (forall (?e - ejercicio)
    		        		(when (subidoNivel ?e)
    		        			  (not (subidoNivel ?e)))
    			    )
    			    (assign (contadorEjercicios) 0)
				)
	)
)
