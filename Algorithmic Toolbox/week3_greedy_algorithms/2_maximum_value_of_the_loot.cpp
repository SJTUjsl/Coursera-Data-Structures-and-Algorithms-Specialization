#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;

    // write your code here
    vector<double> vpw; // value per weight
    for(int i = 0; i < values.size(); ++i)
        vpw.push_back((double)values[i] / weights[i]);

    while(capacity > 0 && values.size() > 0){ // bag is not full yet
        // get the biggest vpw
        int candi_idx = -1;
        double max_vpw = 0.0;
        for(int i = 0; i < vpw.size(); i++){
            if(candi_idx == -1 || vpw[i] > max_vpw){
                candi_idx = i;
                max_vpw = vpw[i];
            }
        }

        // put the current item with biggest vpw in the bag
        if(weights[candi_idx] <= capacity){
            value += values[candi_idx];
            capacity -= weights[candi_idx];
            weights.erase(weights.begin() + candi_idx);
            values.erase(values.begin() + candi_idx);
            vpw.erase(vpw.begin() + candi_idx);
        }
        else{
            value += capacity * vpw[candi_idx];
            capacity = 0;
        }
    }

    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
      std::cin >> values[i] >> weights[i];

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}
