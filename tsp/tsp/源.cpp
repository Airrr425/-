#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std::chrono;
using namespace std;
const int POPULATION_SIZE = 20;     //个体数量
const int NUM_GENERATIONS = 100;     //遗传次数
const double MUTATION_RATE = 0.15;   //变异频率
// 数据结构表示遗传算法中的每个个体
struct Individual {           //individual[i]表示路径上的第i个城市。
    vector<int> chromosome;  //每个染色体代表一个可能的解决方案，即一条路径，用整数数组代表染色体容易对其进行遗传操作
    double fitness;          //适应度
    bool operator<(const Individual& other) const {
        return fitness < other.fitness;
    }
};
// 生成随机个体（即一条路径）
vector<int> generateRandomIndividual(int numCities) {
    vector<int> individual(numCities);
    for (int i = 0; i < numCities; ++i) {
        individual[i] = i;
    }
    random_device rd;
    mt19937 randomEngine(rd());         //伪随机数生成，随机选择个体
    shuffle(individual.begin(), individual.end(), randomEngine);    //将容器中的元素打乱，增加多样性
    return individual;
}
// 计算个体的适应度（即路径的总长度）
double calculateFitness(const vector<int>& individual, const vector<vector<double>>& distances) {          //distances[i][j]表示城市i到城市j的距离
    double fitness = 0;
    int numCities = individual.size();   //记录城市的数量
    for (int i = 0; i < numCities - 1; ++i) {      //遍历所有的城市
        fitness += distances[individual[i]][individual[i + 1]];
    }
    fitness += distances[individual[numCities - 1]][individual[0]];
    return fitness;
}
// 进行交叉操作（使用顺序交叉）
vector<int> crossover(const vector<int>& parent1, const vector<int>& parent2) {
    vector<int> child(parent1.size(), -1);      //创建染色体长度相同的子代个体
    random_device rd;
    mt19937 randomEngine(rd());
    uniform_int_distribution<int> distribution(0, parent1.size() - 1);   //创建一个整数分布对象
    int startPos = distribution(randomEngine);       //生成随机基因起始位置
    int endPos = distribution(randomEngine);         //生成随机基因结束位置
    if (startPos > endPos) {
        swap(startPos, endPos);
    }
    for (int i = startPos; i <= endPos; ++i) {
        child[i] = parent1[i];                 //将这段基因的染色体片段复制
    }
    int currentIndex = 0;
    for (int i = 0; i < parent2.size(); ++i) {
        if (currentIndex == startPos) {
            currentIndex = endPos + 1;          //跳过已复制的基因片段
        }
        if (find(child.begin(), child.end(), parent2[i]) == child.end()) {
            child[currentIndex] = parent2[i];
            currentIndex = (currentIndex + 1) % parent2.size();        //将父代2的基因复制到剩余片段
        }
    }
    return child;
}
// 进行变异操作（使用随机交换）
void mutate(vector<int>& individual) { 
    random_device rd;
    mt19937 randomEngine(rd());
    uniform_real_distribution<double> distribution(0.0, 1.0);
    for (int i = 0; i < individual.size(); ++i) {
        if (distribution(randomEngine) < MUTATION_RATE) {
            int swapIndex = randomEngine() % individual.size();
            swap(individual[i], individual[swapIndex]);     //交换两个城市的位置来引入变异
        }
    }
}
// 遗传算法主函数
vector<int> geneticAlgorithm(const vector<vector<double>>& distances) {
    int numCities = distances.size();
    // 初始化种群
    vector<Individual> population(POPULATION_SIZE);
    for (int i = 0; i < POPULATION_SIZE; ++i) {
        population[i].chromosome = generateRandomIndividual(numCities);
        population[i].fitness = calculateFitness(population[i].chromosome, distances);    //计算种群中个体的适应度
    }
    // 进化过程
    for (int generation = 0; generation < NUM_GENERATIONS; ++generation) {               //进行多次迭代
        sort(population.begin(), population.end());
        // 选择父代进行交叉和变异
        vector<Individual> nextGeneration(POPULATION_SIZE);
        for (int i = 0; i < POPULATION_SIZE / 2; ++i) {
            int parentIndex1 = rand() % (POPULATION_SIZE / 2);         //随机挑选亲代
            int parentIndex2 = rand() % (POPULATION_SIZE / 2);
            nextGeneration[i * 2].chromosome = crossover(population[parentIndex1].chromosome, population[parentIndex2].chromosome);     //通过交叉操作，生成两个子代个体的染色体
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
            }*/         //用来查看遗传过程
        }
        population = nextGeneration;         //更新父代染色体
    }
    sort(population.begin(), population.end());       
    return population[0].chromosome;            
}
int main() {
    auto startTime = high_resolution_clock::now();
    vector<vector<double>> distances = {
    {0, 2, 9, 10, 5, 4, 8, 7},  //对称矩阵来表示城市间的距离
    {2, 0, 6, 4, 8, 11, 3, 1},
    {9, 6, 0, 3, 7, 1, 5, 12},
    {10, 4, 3, 0, 12, 9, 7, 5},
    {5, 8, 7, 12, 0, 3, 6, 9},
    {4, 11, 1, 9, 3, 0, 10, 8},
    {8, 3, 5, 7, 6, 10, 0, 2},
    {7, 1, 12, 5, 9, 8, 2, 0}
    };
    vector<int> path = geneticAlgorithm(distances);
    cout << "最佳路径: ";
    for (int city : path) {
        cout << city << " ";
    }
    cout << endl;
    double totalDistance = calculateFitness(path, distances);
    cout << "总路程: " << totalDistance << endl;
    auto endTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(endTime - startTime).count();
    cout << "程序运行时间: " << duration << " 毫秒" << endl;
    system("pause");
    return 0;
}