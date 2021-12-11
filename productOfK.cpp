#include <vector>
using namespace std;

class ProductOfNumbers {
public:
    ProductOfNumbers()
    {
        numbers.reserve(40000);
    }

    void add(int num)
    {
        if(num != 1)
            numbers.push_back(std::make_pair(num, numbers.size()));
    }

    int getProduct(int k)
    {
        int product = 1;
        auto s = numbers.size() - k;
        for(auto it = numbers.rbegin(), itEnd = numbers.rend(); it != itEnd && k--; ++it) {
            const auto& p = *it;
            if(p.second < s)
                break;

            product *= p.first;
        }

        return product;
    }

private:
    std::vector<std::pair<int, std::size_t>> numbers;
};

int main()
{

}