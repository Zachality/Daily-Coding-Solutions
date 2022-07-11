// Good morning! Here's your coding interview problem for today.

// This problem was asked by Google.

// Implement a PrefixMapSum class with the following methods:

// insert(key: str, value: int): Set a given key's value in the map. If the key already exists, overwrite the value.
// sum(prefix: str): Return the sum of all values of keys that begin with a given prefix.
// For example, you should be able to run the following code:

// mapsum.insert("columnar", 3)
// assert mapsum.sum("col") == 3

// mapsum.insert("column", 2)
// assert mapsum.sum("col") == 5

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class PrefixMapSum {
    public: 
        std::map<std::string, int> log;
        void insert_value(std::string map_key, int map_value){
            log.insert(std::pair<std::string, int>(map_key, map_value));
            // log.emplace(map_key, map_value)
        }

        static bool cmp(std::pair<std::string, int>& pair_1, std::pair<std::string, int>& pair_2){
                return pair_1.first < pair_2.first;
            }

        int sum(std::string query){

            // sort existing map log
            std::vector<std::pair<std::string, int> > V;

            for(auto& it : log){
                V.push_back(it);
            }
            std::sort(V.begin(), V.end(), cmp);

            //add all the values for keys with query in name
            int sum = 0;
            for(int i = 0; i < V.size(); i++){
                bool indicator = true;
                for(int j = 0; j < query.length(); j++){
                    if (query[j] != V[i].first[j]){
                        indicator = false;
                    }
                }
                if (indicator == true){
                    sum += V[i].second;
                }
            }
            std::cout << sum << "     ";
            return sum;
        }
};

int main(){
    PrefixMapSum myMap;
    myMap.insert_value("Eric", 60);
    myMap.insert_value("Sheila", 59);
    myMap.insert_value("Rebecca", 19);
    myMap.insert_value("Ralph", 85);
    myMap.insert_value("Rex", 12);
    myMap.insert_value("Column", 2);
    myMap.insert_value("Columnar", 3);
    myMap.sum("Col");
}