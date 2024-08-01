#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std::chrono;
using namespace std;
const int POPULATION_SIZE = 20;     //��������
const int NUM_GENERATIONS = 100;     //�Ŵ�����
const double MUTATION_RATE = 0.15;   //����Ƶ��
// ���ݽṹ��ʾ�Ŵ��㷨�е�ÿ������
struct Individual {           //individual[i]��ʾ·���ϵĵ�i�����С�
    vector<int> chromosome;  //ÿ��Ⱦɫ�����һ�����ܵĽ����������һ��·�����������������Ⱦɫ�����׶�������Ŵ�����
    double fitness;          //��Ӧ��
    bool operator<(const Individual& other) const {
        return fitness < other.fitness;
    }
};
// ����������壨��һ��·����
vector<int> generateRandomIndividual(int numCities) {
    vector<int> individual(numCities);
    for (int i = 0; i < numCities; ++i) {
        individual[i] = i;
    }
    random_device rd;
    mt19937 randomEngine(rd());         //α��������ɣ����ѡ�����
    shuffle(individual.begin(), individual.end(), randomEngine);    //�������е�Ԫ�ش��ң����Ӷ�����
    return individual;
}
// ����������Ӧ�ȣ���·�����ܳ��ȣ�
double calculateFitness(const vector<int>& individual, const vector<vector<double>>& distances) {          //distances[i][j]��ʾ����i������j�ľ���
    double fitness = 0;
    int numCities = individual.size();   //��¼���е�����
    for (int i = 0; i < numCities - 1; ++i) {      //�������еĳ���
        fitness += distances[individual[i]][individual[i + 1]];
    }
    fitness += distances[individual[numCities - 1]][individual[0]];
    return fitness;
}
// ���н��������ʹ��˳�򽻲棩
vector<int> crossover(const vector<int>& parent1, const vector<int>& parent2) {
    vector<int> child(parent1.size(), -1);      //����Ⱦɫ�峤����ͬ���Ӵ�����
    random_device rd;
    mt19937 randomEngine(rd());
    uniform_int_distribution<int> distribution(0, parent1.size() - 1);   //����һ�������ֲ�����
    int startPos = distribution(randomEngine);       //�������������ʼλ��
    int endPos = distribution(randomEngine);         //��������������λ��
    if (startPos > endPos) {
        swap(startPos, endPos);
    }
    for (int i = startPos; i <= endPos; ++i) {
        child[i] = parent1[i];                 //����λ����Ⱦɫ��Ƭ�θ���
    }
    int currentIndex = 0;
    for (int i = 0; i < parent2.size(); ++i) {
        if (currentIndex == startPos) {
            currentIndex = endPos + 1;          //�����Ѹ��ƵĻ���Ƭ��
        }
        if (find(child.begin(), child.end(), parent2[i]) == child.end()) {
            child[currentIndex] = parent2[i];
            currentIndex = (currentIndex + 1) % parent2.size();        //������2�Ļ����Ƶ�ʣ��Ƭ��
        }
    }
    return child;
}
// ���б��������ʹ�����������
void mutate(vector<int>& individual) { 
    random_device rd;
    mt19937 randomEngine(rd());
    uniform_real_distribution<double> distribution(0.0, 1.0);
    for (int i = 0; i < individual.size(); ++i) {
        if (distribution(randomEngine) < MUTATION_RATE) {
            int swapIndex = randomEngine() % individual.size();
            swap(individual[i], individual[swapIndex]);     //�����������е�λ�����������
        }
    }
}
// �Ŵ��㷨������
vector<int> geneticAlgorithm(const vector<vector<double>>& distances) {
    int numCities = distances.size();
    // ��ʼ����Ⱥ
    vector<Individual> population(POPULATION_SIZE);
    for (int i = 0; i < POPULATION_SIZE; ++i) {
        population[i].chromosome = generateRandomIndividual(numCities);
        population[i].fitness = calculateFitness(population[i].chromosome, distances);    //������Ⱥ�и������Ӧ��
    }
    // ��������
    for (int generation = 0; generation < NUM_GENERATIONS; ++generation) {               //���ж�ε���
        sort(population.begin(), population.end());
        // ѡ�񸸴����н���ͱ���
        vector<Individual> nextGeneration(POPULATION_SIZE);
        for (int i = 0; i < POPULATION_SIZE / 2; ++i) {
            int parentIndex1 = rand() % (POPULATION_SIZE / 2);         //�����ѡ�״�
            int parentIndex2 = rand() % (POPULATION_SIZE / 2);
            nextGeneration[i * 2].chromosome = crossover(population[parentIndex1].chromosome, population[parentIndex2].chromosome);     //ͨ��������������������Ӵ������Ⱦɫ��
            nextGeneration[i * 2 + 1].chromosome = crossover(population[parentIndex2].chromosome, population[parentIndex1].chromosome);
            mutate(nextGeneration[i * 2].chromosome);
            mutate(nextGeneration[i * 2 + 1].chromosome);
            nextGeneration[i * 2].fitness = calculateFitness(nextGeneration[i * 2].chromosome, distances);
            nextGeneration[i * 2 + 1].fitness = calculateFitness(nextGeneration[i * 2 + 1].chromosome, distances);
            /*for (const auto& individual : population) {
                for (const auto& chromosome : individual.chromosome) {
                    cout << chromosome << " ";
                }
                cout << " fitness: " << individual.fitness << endl;
            }*/         //�����鿴�Ŵ�����
        }
        population = nextGeneration;         //���¸���Ⱦɫ��
    }
    sort(population.begin(), population.end());       
    return population[0].chromosome;            
}
int main() {
    auto startTime = high_resolution_clock::now();
    vector<vector<double>> distances = {
    {0, 2, 9, 10, 5, 4, 8, 7},  //�Գƾ�������ʾ���м�ľ���
    {2, 0, 6, 4, 8, 11, 3, 1},
    {9, 6, 0, 3, 7, 1, 5, 12},
    {10, 4, 3, 0, 12, 9, 7, 5},
    {5, 8, 7, 12, 0, 3, 6, 9},
    {4, 11, 1, 9, 3, 0, 10, 8},
    {8, 3, 5, 7, 6, 10, 0, 2},
    {7, 1, 12, 5, 9, 8, 2, 0}
    };
    vector<int> path = geneticAlgorithm(distances);
    cout << "���·��: ";
    for (int city : path) {
        cout << city << " ";
    }
    cout << endl;
    double totalDistance = calculateFitness(path, distances);
    cout << "��·��: " << totalDistance << endl;
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(endTime - startTime).count();
    cout << "��������ʱ��: " << duration << " ����" << endl;
    system("pause");
    return 0;
}