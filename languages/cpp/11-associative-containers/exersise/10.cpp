#include <list>
#include <utility>
#include <vector>
#include <map>

int main() {
    std::map<std::vector<int>::iterator, int> mv;
    std::map<std::list<int>::iterator, int> ml;

    std::vector<int> vi;
    mv.insert(std::pair<std::vector<int>::iterator, int>(vi.begin(), 0));

    // list iterator has no operator < 
    std::list<int> li;
    mv.insert(std::pair<std::list<int>::iterator, int>(li.begin(), 0));
}
