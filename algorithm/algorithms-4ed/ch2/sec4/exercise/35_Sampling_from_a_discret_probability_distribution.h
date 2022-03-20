#ifndef SAMPLE_H
#define SAMPLE_H

#include <random>
#include <vector>

struct Node {
  Node() = default;
  Node(double w) : weight(w) {}
  double weight;
  double cumulativeWeight = 0;
};

class Sample {
public:
  Sample(const std::vector<double> &a);

public:
  int random();
  void changeKey(int i, double v);

private:
  void computeCumulativeWeights();
  void updateCumulativeWeights(int i, double diff);

private:
  int sum;
  std::vector<Node> nodes;
};

inline Sample::Sample(const std::vector<double> &probabilities)
    : nodes(probabilities.size() + 1) {
  for (int i = 1; i <= probabilities.size(); ++i) {
    double weight = probabilities[i - 1];
    nodes[i] = Node(weight);
    sum += weight;
  }
  computeCumulativeWeights();
}

// return an index i with probability p[i]/sum
inline int Sample::random() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0, sum);

  auto randomValue = dis(gen);
  auto i = 1;
  while (randomValue < nodes[i].cumulativeWeight) {
    i *= 2;
    auto leftSubtreeWeight = nodes[i].cumulativeWeight + nodes[i].weight;
    if (randomValue >= leftSubtreeWeight) {
      randomValue -= leftSubtreeWeight;
      ++i;
    }
  }
  return i - 1;
}

// change the value of p[i] to v
inline void Sample::changeKey(int i, double val) {
  ++i;
  auto diff = val - nodes[i].weight;
  nodes[i].weight = val;

  sum += diff;
  updateCumulativeWeights(i/2, diff);
}


inline void Sample::computeCumulativeWeights() {
  for (int i = nodes.size() - 1; i >= 2; --i) {
    nodes[i / 2].cumulativeWeight +=
        nodes[i].cumulativeWeight + nodes[i].weight;
  }
}

inline void Sample::updateCumulativeWeights(int i, double diff) {
  while (i >= 1) {
    nodes[i].cumulativeWeight += diff;
    i /= 2;
  }
}

#endif /* SAMPLE_H */
