#include "../inc/PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    PmergeMe sort(ac, av);
    if (sort.getStatus() == true)
        sort.sortAndMeasure();
}