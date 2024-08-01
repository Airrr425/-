#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
const int NUM_CITIES = 8; // 城市数量
struct Individual {
    std::vector<int> chromosomes;
    double fitness;
};
std::vector<Individual> population;
int populationSize = 20;
int getRandomCity() {
    return rand() % NUM_CITIES;
}
double getDistance(int city1, int city2) {
    int distances[NUM_CITIES][NUM_CITIES] = {
        {0, 2, 9, 10, 5, 4, 8, 7},
        {2, 0, 6, 4, 8, 11, 3, 1},
        {9, 6, 0, 3, 7, 1, 5, 12},
        {10, 4, 3, 0, 12, 9, 7, 5},
        {5, 8, 7, 12, 0, 3, 6, 9},
        {4, 11, 1, 9, 3, 0, 10, 8},
        {8, 3, 5, 7, 6, 10, 0, 2},
        {7, 1, 12, 5, 9, 8, 2, 0}
    };
    return distances[city1][city2];
}
double calculateFitness(Individual& individual) {
    double totalDistance = 0.0;
    for (int i = 0; i < NUM_CITIES - 1; ++i) {
        int cityIndex1 = individual.chromosomes[i];
        int cityIndex2 = individual.chromosomes[i + 1];
        totalDistance += getDistance(cityIndex1, cityIndex2);
    }
    int lastCityIndex = individual.chromosomes[NUM_CITIES - 1];
    int firstCityIndex = individual.chromosomes[0];
    totalDistance += getDistance(lastCityIndex, firstCityIndex);
    individual.fitness = 1.0 / totalDistance;
    return individual.fitness;
}
void createPopulation() {
    for (int i = 0; i < populationSize; ++i) {
        Individual individual;
        for (int j = 0; j < NUM_CITIES; ++j) {
            individual.chromosomes.push_back(getRandomCity());
        }
        population.push_back(individual);
    }
}
void printPopulation() {
    for (const auto& individual : population) {
        for (const auto& chromosome : individual.chromosomes) {
            std::cout << chromosome << " ";
        }
        std::cout << " Fitness: " << individual.fitness << std::endl;
    }
}
bool compareFitness(const Individual& individual1, const Individual& individual2) {
    return individual1.fitness > individual2.fitness;
}
Individual tournamentSelection() {
    const int TOURNAMENT_SIZE = 4;
    std::vector<Individual> tournamentPool;
    for (int i = 0; i < TOURNAMENT_SIZE; ++i) {
        int randomIndex = rand() % populationSize;
        tournamentPool.push_back(population[randomIndex]);
    }
    std::sort(tournamentPool.begin(), tournamentPool.end(), compareFitness);
    return tournamentPool[0];
}
void crossover(Individual& parent1, Individual& parent2, Individual& offspring) {
    int startPos = rand() % NUM_CITIES;
    int endPos = rand() % NUM_CITIES;
    for (int i = 0; i < NUM_CITIES; ++i) {
        if (startPos < endPos && i > startPos && i < endPos) {
            offspring.chromosomes[i] = parent1.chromosomes[i];
        }
        else if (startPos > endPos) {
            if (!(i < startPos && i > endPos)) {
                offspring.chromosomes[i] = parent1.chromosomes[i];
            }
        }
    }
    for (int i = 0; i < NUM_CITIES; ++i) {
        if (std::find(offspring.chromosomes.begin(), offspring.chromosomes.end(), parent2.chromosomes[i]) ==
            offspring.chromosomes.end()) {
            for (int j = 0; j < NUM_CITIES; ++j) {
                if (offspring.chromosomes[j] == -1) {
                    offspring.chromosomes[j] = parent2.chromosomes[i];
                    break;
                }
            }
        }
    }
}
void mutation(Individual& individual) {
    for (int i = 0; i < NUM_CITIES; ++i) {
        if (rand() % 100 < 5) {
            int swapIndex = rand() % NUM_CITIES;
            std::swap(individual.chromosomes[i], individual.chromosomes[swapIndex]);
        }
    }
}
void printShortestPath(const Individual& individual) {
    std::cout << "Shortest path: ";
    for (int i = 0; i < NUM_CITIES; ++i) {
        std::cout << individual.chromosomes[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Distance: " << 1.0 / individual.fitness << std::endl;
}
int main() {
    srand((unsigned)time(0));
    createPopulation();
    printPopulation();
    Individual bestIndividual;
    for (int i = 0; i < 1000; ++i) {
        std::vector<Individual> newPopulation;
        for (int j = 0; j < populationSize; ++j) {
            Individual parent1 = tournamentSelection();
            Individual parent2 = tournamentSelection();
            Individual offspring;
            offspring.chromosomes = std::vector<int>(NUM_CITIES, -1);
            crossover(parent1, parent2, offspring);
            mutation(offspring);
            calculateFitness(offspring);
            newPopulation.push_back(offspring);
        }
        population = newPopulation;
        std::sort(population.begin(), population.end(), compareFitness);
        printPopulation();
    }
    printShortestPath(bestIndividual);
    return 0;
}
