#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>
#include <ctime>

void basicGenerator(std::ofstream& output_file) {
    
    output_file << "(define (problem basicProblem) (:domain planificador)" << std::endl;
    output_file << "    (:objects" << std::endl;
    
    std::mt19937 randomEngine(time(NULL));
    static std::uniform_int_distribution<int> distribution(1, 20);
    
    int numExercises = distribution(randomEngine);
    
    std::vector<std::string> exercises (numExercises);
    
    output_file << "          ";
    for (unsigned int i = 0; i < numExercises; i++) {
        std::string exercise = "ej";
        exercise.append(std::to_string(i));
        exercises[i] = exercise;
        output_file << exercises[i] << " ";
    }
    output_file << "- ejercicio" << std::endl;
    output_file << "          ";
    
    std::vector<std::string> days (15);
    for (unsigned int i = 0; i < 15; i++) {
        std::string day = "d";
        day.append(std::to_string(i+1));
        days[i] = day;
        output_file << days[i] <<  " ";
    }
    output_file << "- dia" << std::endl;
    output_file << "          ";
    
    std::vector<std::string> levels (10);
    for (unsigned int i = 0; i < 10; i++) {
        std::string level = "n";
        level.append(std::to_string(i+1));
        levels[i] = level;
        output_file << levels[i] <<  " ";
    }
    output_file << "- nivel" << std::endl;
    output_file << "    )" << std::endl;
    output_file << "    (:init" << std::endl;
    
    // Initial statements that must be defined always
    
    for (unsigned int i = 2; i <= 15; i++) {
        output_file << "          (diaAnterior d" + std::to_string(i-1) + " d" + std::to_string(i) + ")" << std::endl;
    }
    
    output_file << "          (diaActual d1)" << std::endl;
    
    for (unsigned int i = 1; i < 10; i++) {
        output_file << "          (nivelPosterior n" + std::to_string(i) + " n" + std::to_string(i+1) + ")" << std::endl;
    }
    
    // Randomized statements
    
    static std::uniform_int_distribution<int> exercisesDistribution(0, numExercises-1);
    
    int numMaxPreparers = numExercises / 3;
    static std::uniform_int_distribution<int> preparersDistribution(0, numMaxPreparers);
    int numPreparers = preparersDistribution(randomEngine);
    
    std::vector<int> preparedExercises;
    
    while(numPreparers > 0) {
        int preparerExercise = exercisesDistribution(randomEngine);
        int exercise = exercisesDistribution(randomEngine);
        
        bool canPrepare = true;
        
        for (unsigned int i = 0; i < preparedExercises.size() and canPrepare; i++) {
            if (exercise == preparedExercises[i]) canPrepare = false;
        }
        if (preparerExercise != exercise and canPrepare) {
            numPreparers--;
            preparedExercises.push_back(exercise);
            output_file << "          (preparador " + exercises[preparerExercise] + " " + exercises[exercise] + ")" << std::endl;
        }
    }
    
    static std::uniform_int_distribution<int> levelsDistribution(0, 4); // We made it so an exercise can not initially have a higher level than 5
    std::vector<int> initialLevels (numExercises);
    for (unsigned int i = 0; i < numExercises; i++) {
        int level = levelsDistribution(randomEngine);
        initialLevels[i] = level + 1;
        output_file << "          (nivelActual " + exercises[i] + " " + levels[level] + ")" << std::endl;
    }
    output_file << "    )" << std::endl;
    
    output_file << "    (:goal (and" << std::endl;
    for (unsigned int i = 0; i < numExercises; i++) {
        std::uniform_int_distribution<int> dist(initialLevels[i], 10);
        int improve = dist(randomEngine) - 1;
        
        output_file << "                (nivelActual " + exercises[i] + " " + levels[improve] + ")" << std::endl;
    }
    output_file << "           )" << std::endl;
    output_file << "    )" << std::endl;
    output_file << ")" << std::endl;
}

void firstExtensionGenerator(std::ofstream& output_file) {
    
    output_file << "(define (problem firstExtensionProblem) (:domain planificador)" << std::endl;
    output_file << "    (:objects" << std::endl;
    
    std::mt19937 randomEngine(time(NULL));
    static std::uniform_int_distribution<int> distribution(1, 20);
    
    int numExercises = distribution(randomEngine);
    
    std::vector<std::string> exercises (numExercises);
    
    output_file << "          ";
    for (unsigned int i = 0; i < numExercises; i++) {
        std::string exercise = "ej";
        exercise.append(std::to_string(i));
        exercises[i] = exercise;
        output_file << exercises[i] << " ";
    }
    output_file << "- ejercicio" << std::endl;
    output_file << "          ";
    
    std::vector<std::string> days (15);
    for (unsigned int i = 0; i < 15; i++) {
        std::string day = "d";
        day.append(std::to_string(i+1));
        days[i] = day;
        output_file << days[i] <<  " ";
    }
    output_file << "- dia" << std::endl;
    output_file << "          ";
    
    std::vector<std::string> levels (10);
    for (unsigned int i = 0; i < 10; i++) {
        std::string level = "n";
        level.append(std::to_string(i+1));
        levels[i] = level;
        output_file << levels[i] <<  " ";
    }
    output_file << "- nivel" << std::endl;
    output_file << "    )" << std::endl;
    output_file << "    (:init" << std::endl;
    
    // Initial statements that must be defined always
    
    for (unsigned int i = 2; i <= 15; i++) {
        output_file << "          (diaAnterior d" + std::to_string(i-1) + " d" + std::to_string(i) + ")" << std::endl;
    }
    
    output_file << "          (diaActual d1)" << std::endl;
    
    for (unsigned int i = 1; i < 10; i++) {
        output_file << "          (nivelPosterior n" + std::to_string(i) + " n" + std::to_string(i+1) + ")" << std::endl;
    }
    
    // Randomized statements
    
    static std::uniform_int_distribution<int> exercisesDistribution(0, numExercises-1);
    
    int numMaxPreparers = numExercises / 3;
    static std::uniform_int_distribution<int> preparersDistribution(0, numMaxPreparers);
    int numPreparers = preparersDistribution(randomEngine);
    
    while(numPreparers > 0) {
        int preparerExercise = exercisesDistribution(randomEngine);
        int exercise = exercisesDistribution(randomEngine);
        
        if (preparerExercise != exercise) {
            numPreparers--;
            output_file << "          (preparador " + exercises[preparerExercise] + " " + exercises[exercise] + ")" << std::endl;
        }
    }
    
    static std::uniform_int_distribution<int> levelsDistribution(0, 4); // We made it so an exercise can not initially have a higher level than 5
    std::vector<int> initialLevels (numExercises);
    for (unsigned int i = 0; i < numExercises; i++) {
        int level = levelsDistribution(randomEngine);
        initialLevels[i] = level + 1;
        output_file << "          (nivelActual " + exercises[i] + " " + levels[level] + ")" << std::endl;
    }
    output_file << "    )" << std::endl;
    
    output_file << "    (:goal (and" << std::endl;
    for (unsigned int i = 0; i < numExercises; i++) {
        std::uniform_int_distribution<int> dist(initialLevels[i], 10);
        int improve = dist(randomEngine) - 1;
        
        output_file << "                (nivelActual " + exercises[i] + " " + levels[improve] + ")" << std::endl;
    }
    output_file << "           )" << std::endl;
    output_file << "    )" << std::endl;
    output_file << ")" << std::endl;
}

void secondExtensionGenerator(std::ofstream& output_file) {
    
    output_file << "(define (problem secondExtensionProblem) (:domain planificador)" << std::endl;
    output_file << "    (:objects" << std::endl;
    
    std::mt19937 randomEngine(time(NULL));
    static std::uniform_int_distribution<int> distribution(1, 20);
    
    int numExercises = distribution(randomEngine);
    
    std::vector<std::string> exercises (numExercises);
    
    output_file << "          ";
    for (unsigned int i = 0; i < numExercises; i++) {
        std::string exercise = "ej";
        exercise.append(std::to_string(i));
        exercises[i] = exercise;
        output_file << exercises[i] << " ";
    }
    output_file << "- ejercicio" << std::endl;
    output_file << "          ";
    
    std::vector<std::string> days (15);
    for (unsigned int i = 0; i < 15; i++) {
        std::string day = "d";
        day.append(std::to_string(i+1));
        days[i] = day;
        output_file << days[i] <<  " ";
    }
    output_file << "- dia" << std::endl;
    output_file << "          ";
    
    std::vector<std::string> levels (10);
    for (unsigned int i = 0; i < 10; i++) {
        std::string level = "n";
        level.append(std::to_string(i+1));
        levels[i] = level;
        output_file << levels[i] <<  " ";
    }
    output_file << "- nivel" << std::endl;
    output_file << "    )" << std::endl;
    output_file << "    (:init" << std::endl;
    
    // Initial statements that must be defined always
    
    for (unsigned int i = 2; i <= 15; i++) {
        output_file << "          (diaAnterior d" + std::to_string(i-1) + " d" + std::to_string(i) + ")" << std::endl;
    }
    
    output_file << "          (diaActual d1)" << std::endl;
    
    for (unsigned int i = 1; i < 10; i++) {
        output_file << "          (nivelPosterior n" + std::to_string(i) + " n" + std::to_string(i+1) + ")" << std::endl;
    }
    
    // Randomized statements
    
    static std::uniform_int_distribution<int> exercisesDistribution(0, numExercises-1);
    
    int numMaxPreparers = numExercises / 3;
    static std::uniform_int_distribution<int> preparersDistribution(0, numMaxPreparers);
    int numPreparers = preparersDistribution(randomEngine);
    
    while(numPreparers > 0) {
        int preparerExercise = exercisesDistribution(randomEngine);
        int exercise = exercisesDistribution(randomEngine);
        
        if (preparerExercise != exercise) {
            numPreparers--;
            output_file << "          (preparador " + exercises[preparerExercise] + " " + exercises[exercise] + ")" << std::endl;
        }
    }
    
    int numMaxPrecursors = numExercises / 3;
    static std::uniform_int_distribution<int> precursorsDistribution(0, numMaxPrecursors);
    int numPrecursors = precursorsDistribution(randomEngine);
    
    std::vector<int> precursedExercises;
    
    while(numPrecursors > 0) {
        int precursorExercise = exercisesDistribution(randomEngine);
        int exercise = exercisesDistribution(randomEngine);
        
        bool canPrecursor = true;
        
        for (unsigned int i = 0; i < precursedExercises.size() and canPrecursor; i++) {
            if (exercise == precursedExercises[i]) canPrecursor = false;
        }
        if (precursorExercise!= exercise and canPrecursor) {
            numPrecursors--;
            precursedExercises.push_back(exercise);
            output_file << "          (precursor " + exercises[precursorExercise] + " " + exercises[exercise] + ")" << std::endl;
        }
    }
    
    static std::uniform_int_distribution<int> levelsDistribution(0, 4); // We made it so an exercise can not initially have a higher level than 5
    std::vector<int> initialLevels (numExercises);
    for (unsigned int i = 0; i < numExercises; i++) {
        int level = levelsDistribution(randomEngine);
        initialLevels[i] = level + 1;
        output_file << "          (nivelActual " + exercises[i] + " " + levels[level] + ")" << std::endl;
    }
    output_file << "    )" << std::endl;
    
    output_file << "    (:goal (and" << std::endl;
    for (unsigned int i = 0; i < numExercises; i++) {
        std::uniform_int_distribution<int> dist(initialLevels[i], 10);
        int improve = dist(randomEngine) - 1;
        
        output_file << "                (nivelActual " + exercises[i] + " " + levels[improve] + ")" << std::endl;
    }
    output_file << "           )" << std::endl;
    output_file << "    )" << std::endl;
    output_file << ")" << std::endl;
}

void thirdExtensionGenerator(std::ofstream& output_file) {
    
    output_file << "(define (problem thirdExtensionProblem) (:domain planificador)" << std::endl;
    output_file << "    (:objects" << std::endl;
    
    std::mt19937 randomEngine(time(NULL));
    static std::uniform_int_distribution<int> distribution(1, 20);
    
    int numExercises = distribution(randomEngine);
    
    std::vector<std::string> exercises (numExercises);
    
    output_file << "          ";
    for (unsigned int i = 0; i < numExercises; i++) {
        std::string exercise = "ej";
        exercise.append(std::to_string(i));
        exercises[i] = exercise;
        output_file << exercises[i] << " ";
    }
    output_file << "- ejercicio" << std::endl;
    output_file << "          ";
    
    std::vector<std::string> days (15);
    for (unsigned int i = 0; i < 15; i++) {
        std::string day = "d";
        day.append(std::to_string(i+1));
        days[i] = day;
        output_file << days[i] <<  " ";
    }
    output_file << "- dia" << std::endl;
    output_file << "    )" << std::endl;
    output_file << "    (:init" << std::endl;
    
    // Initial statements that must be defined always
    
    for (unsigned int i = 2; i <= 15; i++) {
        output_file << "          (diaAnterior d" + std::to_string(i-1) + " d" + std::to_string(i) + ")" << std::endl;
    }
    
    output_file << "          (diaActual d1)" << std::endl;
    
    // Randomized statements
    
    static std::uniform_int_distribution<int> exercisesDistribution(0, numExercises-1);
    
    int numMaxPreparers = numExercises / 3;
    static std::uniform_int_distribution<int> preparersDistribution(0, numMaxPreparers);
    int numPreparers = preparersDistribution(randomEngine);
    
    while(numPreparers > 0) {
        int preparerExercise = exercisesDistribution(randomEngine);
        int exercise = exercisesDistribution(randomEngine);
        
        if (preparerExercise != exercise) {
            numPreparers--;
            output_file << "          (preparador " + exercises[preparerExercise] + " " + exercises[exercise] + ")" << std::endl;
        }
    }
    
    int numMaxPrecursors = numExercises / 3;
    static std::uniform_int_distribution<int> precursorsDistribution(0, numMaxPrecursors);
    int numPrecursors = precursorsDistribution(randomEngine);
    
    std::vector<int> precursedExercises;
    
    while(numPrecursors > 0) {
        int precursorExercise = exercisesDistribution(randomEngine);
        int exercise = exercisesDistribution(randomEngine);
        
        bool canPrecursor = true;
        
        for (unsigned int i = 0; i < precursedExercises.size() and canPrecursor; i++) {
            if (exercise == precursedExercises[i]) canPrecursor = false;
        }
        if (precursorExercise!= exercise and canPrecursor) {
            numPrecursors--;
            precursedExercises.push_back(exercise);
            output_file << "          (precursor " + exercises[precursorExercise] + " " + exercises[exercise] + ")" << std::endl;
        }
    }
    
    static std::uniform_int_distribution<int> levelsDistribution(1, 5); // We made it so an exercise can not initially have a higher level than 5
    std::vector<int> initialLevels (numExercises);
    for (unsigned int i = 0; i < numExercises; i++) {
        int level = levelsDistribution(randomEngine);
        initialLevels[i] = level;
        output_file << "          (= (nivelEjercicio " + exercises[i] + ") " + std::to_string(level) + ")" << std::endl;
    }
    
    output_file << "          (= (contadorEjercicios) 0)" << std::endl;
    output_file << "    )" << std::endl;
    
    output_file << "    (:goal (and" << std::endl;
    for (unsigned int i = 0; i < numExercises; i++) {
        std::uniform_int_distribution<int> dist(initialLevels[i], 10);
        int improve = dist(randomEngine);
        
        output_file << "                (= (nivelEjercicio " + exercises[i] + ") " + std::to_string(improve) + ")" << std::endl;
    }
    output_file << "           )" << std::endl;    
    output_file << "    )" << std::endl;
    output_file << ")" << std::endl;
}

void fourthExtensionGenerator(std::ofstream& output_file) {
    output_file << "(define (problem thirdExtensionProblem) (:domain planificador)" << std::endl;
    output_file << "    (:objects" << std::endl;
    
    std::mt19937 randomEngine(time(NULL));
    static std::uniform_int_distribution<int> distribution(1, 20);
    
    int numExercises = distribution(randomEngine);
    
    std::vector<std::string> exercises (numExercises);
    
    output_file << "          ";
    for (unsigned int i = 0; i < numExercises; i++) {
        std::string exercise = "ej";
        exercise.append(std::to_string(i));
        exercises[i] = exercise;
        output_file << exercises[i] << " ";
    }
    output_file << "- ejercicio" << std::endl;
    output_file << "          ";
    
    std::vector<std::string> days (15);
    for (unsigned int i = 0; i < 15; i++) {
        std::string day = "d";
        day.append(std::to_string(i+1));
        days[i] = day;
        output_file << days[i] <<  " ";
    }
    output_file << "- dia" << std::endl;
    output_file << "    )" << std::endl;
    output_file << "    (:init" << std::endl;
    
    // Initial statements that must be defined always
    
    for (unsigned int i = 2; i <= 15; i++) {
        output_file << "          (diaAnterior d" + std::to_string(i-1) + " d" + std::to_string(i) + ")" << std::endl;
    }
    
    output_file << "          (diaActual d1)" << std::endl;
    
    // Randomized statements
    
    static std::uniform_int_distribution<int> exercisesDistribution(0, numExercises-1);
    
    int numMaxPreparers = numExercises / 3;
    static std::uniform_int_distribution<int> preparersDistribution(0, numMaxPreparers);
    int numPreparers = preparersDistribution(randomEngine);
    
    while(numPreparers > 0) {
        int preparerExercise = exercisesDistribution(randomEngine);
        int exercise = exercisesDistribution(randomEngine);
        
        if (preparerExercise != exercise) {
            numPreparers--;
            output_file << "          (preparador " + exercises[preparerExercise] + " " + exercises[exercise] + ")" << std::endl;
        }
    }
    
    int numMaxPrecursors = numExercises / 3;
    static std::uniform_int_distribution<int> precursorsDistribution(0, numMaxPrecursors);
    int numPrecursors = precursorsDistribution(randomEngine);
    
    std::vector<int> precursedExercises;
    
    while(numPrecursors > 0) {
        int precursorExercise = exercisesDistribution(randomEngine);
        int exercise = exercisesDistribution(randomEngine);
        
        bool canPrecursor = true;
        
        for (unsigned int i = 0; i < precursedExercises.size() and canPrecursor; i++) {
            if (exercise == precursedExercises[i]) canPrecursor = false;
        }
        if (precursorExercise!= exercise and canPrecursor) {
            numPrecursors--;
            precursedExercises.push_back(exercise);
            output_file << "          (precursor " + exercises[precursorExercise] + " " + exercises[exercise] + ")" << std::endl;
        }
    }
    
    static std::uniform_int_distribution<int> levelsDistribution(1, 5); // We made it so an exercise can not initially have a higher level than 5
    std::vector<int> initialLevels (numExercises);
    for (unsigned int i = 0; i < numExercises; i++) {
        int level = levelsDistribution(randomEngine);
        initialLevels[i] = level;
        output_file << "          (= (nivelEjercicio " + exercises[i] + ") " + std::to_string(level) + ")" << std::endl;
    }
    
    static std::uniform_int_distribution<int> timeDistribution(10, 50);
    for (unsigned int i = 0; i < numExercises; i++) {
        int time = timeDistribution(randomEngine);
        output_file << "          (= (tiempoEjercicio " + exercises[i] + ") " + std::to_string(time) + ")" << std::endl;
    }
    
    output_file << "          (= (tiempoEjercitado) 0)" << std::endl;
    output_file << "    )" << std::endl;
    
    output_file << "    (:goal (and" << std::endl;
    for (unsigned int i = 0; i < numExercises; i++) {
        std::uniform_int_distribution<int> dist(initialLevels[i], 10);
        int improve = dist(randomEngine);
        
        output_file << "                (= (nivelEjercicio " + exercises[i] + ") " + std::to_string(improve) + ")" << std::endl;
    }
    output_file << "           )" << std::endl;    
    output_file << "    )" << std::endl;
    output_file << ")" << std::endl;
}

int main() {
    
    std::ofstream output_file;
    std::string output_file_name;
    std::cout << "Inserte el nombre del fichero (sin extension) en el cual se generara el nuevo problema:" << std::endl;
    std::cin >> output_file_name;
    output_file.open(output_file_name + ".pddl");
    
    bool choosen = false;
    
    while (not choosen) {
    
        int extension;
        std::cout << "Inserte que para que extension quiere generar el problema:" << std::endl;
        std::cout << " 0) Basica" << std::endl;
        std::cout << " 1) Primera extension" << std::endl;
        std::cout << " 2) Segunda extension" << std::endl;
        std::cout << " 3) Tercera extension" << std::endl;
        std::cout << " 4) Cuarta extension" << std::endl;
        std::cin >> extension;

        switch (extension) {
            case 0:
                basicGenerator(output_file);
                choosen = true;
                break;
            case 1:
                firstExtensionGenerator(output_file);
                choosen = true;
                break;
            case 2:
                secondExtensionGenerator(output_file);
                choosen = true;
                break;
            case 3:
                thirdExtensionGenerator(output_file);
                choosen = true;
                break;
            case 4:
                fourthExtensionGenerator(output_file);
                choosen = true;
                break;
            default:
                std::cout << "No se ha seleccionado ninguna extension correctamente." << std::endl;
                std::cout << "Vuelva a seleccionar una." << std::endl;
                break;
        }
    }
    std::cout << "El problema se ha generado correctamente." << std::endl;
    return 0;
}
