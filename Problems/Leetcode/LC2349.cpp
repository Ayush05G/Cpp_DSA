//Single map solution(less space complexity/more time complexity)
class NumberContainers {
    public:
        map<int, int> indexToNumberMap;
    
        void change(int index, int number) {
            indexToNumberMap[index] = number;
        }
    
        int find(int number) {
            int smallestIndex = -1;
            for (const auto& pair : indexToNumberMap) {
                if (pair.second == number) {
                    if (smallestIndex == -1 || pair.first < smallestIndex) {
                        smallestIndex = pair.first;
                    }
                }
            }
            return smallestIndex;
        }
    };
    
//Two map solution(more space complexity/less time complexity)
class NumberContainers {
    public:
        map<int, int> indexToNumberMap;
        map<int, set<int>> numberToIndicesMap;
    
        NumberContainers() {
        }
    
        void change(int index, int number) {
            auto it = indexToNumberMap.find(index);
            if (it != indexToNumberMap.end()) {
                numberToIndicesMap[it->second].erase(index);
                it->second = number;
            } else {
                indexToNumberMap[index] = number;
            }
            numberToIndicesMap[number].insert(index);
        }
    
        int find(int number) {
            auto it = numberToIndicesMap.find(number);
            return (it == numberToIndicesMap.end() || it->second.empty()) ? -1 : *it->second.begin();
        }
    };