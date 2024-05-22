#include <string>
#include <array>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <random>

std::vector < std::vector< int > > messages{
    {50, 66, 05, 48, 62, 13, 75, 29, 24, 61, 42, 70, 66, 62, 32, 14, 81, 8, 15, 78, 02, 29, 13, 49, 01,
        80, 82, 40, 63, 81, 21, 19, 00, 40, 51, 65, 26, 14, 21, 70, 47, 44, 48, 42, 19, 48, 13, 47, 19, 49,
        72, 31, 05, 24, 03, 43, 59, 67, 33, 49, 41, 60, 21, 26, 30, 05, 25, 20, 71, 11, 74, 56, 04, 74, 19,
        71, 04, 51, 41, 43, 80, 72, 54, 63, 79, 81, 15, 16, 44, 31, 30, 12, 33, 57, 28, 13, 64, 43, 48 },

    { 80, 66, 05, 48, 62, 13, 75, 29, 24, 61, 42, 70, 66, 62, 32, 14, 81, 8, 15, 78, 02, 29, 13, 49, 01,
        29, 11, 30, 52, 81, 21, 19, 00, 25, 26, 54, 20, 14, 21, 70, 47, 44, 48, 42, 19, 48, 13, 47, 19, 49,
        44, 26, 59, 77, 64, 43, 79, 28, 72, 64, 01, 30, 73, 23, 67, 06, 33, 25, 64, 81, 68, 46, 17, 36, 13,
        17, 21, 68, 13, 9, 46, 67, 57, 34, 62, 82, 15, 10, 73, 62, 02, 11, 65, 72, 37, 44, 10, 43, 68, 62,
        9, 34, 18 },

    { 36, 66, 05, 48, 62, 13, 75, 29, 24, 61, 42, 70, 66, 62, 32, 14, 81, 8, 15, 78, 02, 29, 13, 49, 01,
        69, 76, 52, 9, 48, 66, 80, 22, 64, 57, 40, 49, 78, 03, 16, 56, 19, 47, 40, 80, 06, 13, 64, 29, 49,
        64, 63, 06, 49, 31, 13, 16, 10, 45, 24, 26, 77, 10, 60, 81, 61, 34, 54, 70, 21, 15, 04, 66, 77, 42,
        37, 30, 22, 00, 11, 41, 72, 57, 20, 23, 57, 65, 41, 23, 18, 72, 42, 05, 03, 26, 78, 8, 05, 54, 45,
        77, 25, 64, 61, 16, 44, 54, 51, 20, 63, 25, 11, 26, 45, 53, 60, 38, 34 },

    { 76, 66, 05, 49, 75, 54, 69, 46, 32, 01, 42, 60, 26, 48, 50, 80, 32, 24, 55, 61, 47, 12, 21, 12, 49,
         54, 34, 25, 36, 15, 56, 55, 20, 9, 8, 62, 13, 82, 9, 44, 29, 60, 53, 82, 42, 80, 05, 43, 71, 03,
         80, 77, 47, 78, 34, 25, 62, 18, 10, 49, 62, 64, 52, 81, 11, 66, 62, 13, 47, 17, 52, 70, 26, 23, 32,
         31, 64, 23, 35, 32, 50, 06, 01, 25, 8, 37, 47, 43, 26, 76, 65, 68, 80, 17, 07, 45, 63, 14, 53, 63,
         60, 16 },

    { 63, 66, 05, 49, 75, 54, 02, 60, 29, 40, 78, 47, 60, 75, 67, 71, 60, 02, 65, 07, 47, 14, 45, 74, 59,
        41, 80, 13, 60, 13, 81, 22, 35, 50, 40, 39, 02, 59, 48, 31, 76, 02, 80, 75, 01, 56, 67, 11, 21, 8,
        40, 65, 45, 75, 55, 39, 60, 42, 13, 03, 22, 57, 02, 06, 58, 9, 70, 01, 58, 56, 63, 68, 25, 79, 07,
        20, 19, 64, 02, 66, 73, 30, 71, 16, 12, 30, 65, 37, 20, 13, 22, 63, 18, 46, 64, 59, 41, 81, 82, 22,
        78, 36, 47, 17, 04, 06, 17, 05, 36, 79, 63, 01, 64, 69, 15, 43, 04, 58, 56, 31, 14, 64, 58, 18, 44,
        78, 69, 01, 00, 46, 20, 71, 73, 25, 35, 8, 24 },


    { 34, 66, 05, 49, 75, 54, 23, 74, 11, 13, 28, 26, 19, 48, 67, 57, 37, 60, 34, 28, 74, 10, 17, 32, 11,
        18, 19, 43, 19, 81, 42, 04, 62, 9, 46, 49, 32, 51, 76, 58, 04, 43, 47, 17, 67, 79, 21, 32, 44, 16,
        30, 37, 26, 28, 41, 68, 57, 34, 51, 10, 69, 70, 8, 06, 46, 43, 18, 39, 47, 43, 15, 13, 33, 30, 35,
        62, 37, 00, 37, 05, 38, 55, 37, 13, 40, 25, 9, 21, 11, 64, 05, 79, 42, 68, 11, 71, 11, 48, 03, 67,
        61, 40, 22, 14, 35, 50, 61, 39, 11, 02, 66, 49, 51, 53, 17, 73, 36, 75, 74, 54, 24, 30, 54, 70 },

    { 27, 66, 05, 49, 75, 54, 02, 60, 29, 40, 02, 55, 9, 15, 59, 18, 68, 03, 36, 05, 47, 77, 44, 38, 01,
        18, 28, 76, 04, 34, 60, 63, 58, 80, 17, 54, 79, 75, 48, 54, 55, 19, 62, 64, 14, 47, 51, 70, 75, 05,
        11, 47, 45, 58, 68, 69, 79, 25, 38, 45, 73, 47, 68, 50, 34, 45, 78, 26, 79, 57, 04, 56, 22, 60, 18,
        75, 43, 60, 59, 67, 63, 42, 49, 33, 40, 65, 79, 77, 07, 03, 26, 62, 31, 78, 26, 57, 69, 40, 04, 23,
        26, 13, 67, 42, 38, 72, 11, 39, 65, 60, 25, 06, 80, 66, 68, 77, 59, 78, 19 },

    { 77, 66, 05, 49, 75, 54, 02, 60, 29, 40, 02, 55, 9, 15, 59, 18, 68, 03, 36, 05, 47, 60, 21, 80, 01,
        72, 55, 16, 82, 35, 57, 19, 01, 66, 18, 27, 39, 17, 74, 81, 39, 14, 78, 00, 25, 65, 43, 66, 64, 38,
        81, 23, 24, 50, 57, 30, 71, 75, 26, 68, 54, 57, 56, 50, 71, 73, 14, 21, 8, 32, 26, 63, 05, 37, 19,
        43, 66, 47, 53, 34, 66, 23, 73, 31, 54, 38, 77, 67, 11, 63, 79, 06, 22, 21, 51, 69, 74, 21, 05, 17,
        67, 37, 29, 21, 60, 14, 82, 44, 30, 04, 20, 42, 35, 01, 31, 54, 46, 20, 40, 30 },

    { 33, 66, 05, 49, 75, 54, 02, 60, 29, 40, 02, 55, 9, 15, 59, 18, 68, 03, 36, 05, 47, 33, 21, 59, 44,
        18, 28, 76, 59, 34, 60, 63, 79, 27, 12, 54, 05, 49, 48, 54, 55, 52, 62, 72, 69, 10, 57, 22, 58, 48,
        67, 53, 07, 34, 32, 30, 31, 19, 26, 8, 34, 46, 07, 30, 71, 55, 34, 75, 54, 9, 06, 60, 05, 23, 25,
        45, 42, 80, 25, 12, 22, 76, 20, 51, 62, 21, 40, 9, 41, 10, 44, 73, 8, 33, 70, 73, 06, 31, 21, 72,
        05, 40, 61, 51, 42, 66, 64, 74, 61, 25, 63, 42, 24, 41 }
};

constexpr int aSize{ 83 };
constexpr int mCount{ 9 };

void compute( const std::vector<int>& cypher, int target, std::array<std::array<int, aSize>, aSize>& counter)
{
    bool found{ 0 };
    std::array<int, aSize>& counterPlace{counter[target]};
    for (int i = 0; i < cypher.size(); i++)
    {
        if (!found)
        {
            if (cypher[i] == target)
                found = true;
        }
        else
        {
            for (int t = 1; t < aSize; t++)
            {
                if (cypher[i] == ((target + t) % aSize))
                {
                    counterPlace[t]++;
                }
            }
        }
    }
}

std::vector<bool> get_shared_vec()
{
   
    std::vector<bool> vec(
        []()->std::size_t
        {
            std::size_t max_length{ 0 };
            for (auto& msg : messages)
                max_length = std::max(max_length, msg.size());

            return max_length;
        }(),
        false);

    for (int i = 0; i < mCount; i++)
    {
        for (int j = 0; j < messages[i].size(); j++)
        {
            if (!vec[j])
            {
                int& cypeherChar = messages[i][j];
                for (int k = 0; k < mCount; k++)
                {
                    if (i != k && j < messages[k].size() && cypeherChar == messages[k][j])
                    {
                        vec[j] = true;
                        break;
                    }
                }
            }
        }
    }

    return vec;
}

void inline_scramble_unshared(const std::vector<bool>& shared_vec)
{
    std::random_device random_device;
    std::mt19937 mt(random_device());
    std::uniform_int_distribution<int> dist(0, 82);

    for (int i = 0; i < mCount; i++)
    {
        for (int j = 0; j < messages[i].size(); j++)
        {
            if (!shared_vec[j])
            {
                messages[i][j] = dist(mt);
            }
        }
    }
}

template<typename T>
float avg(std::vector<T>& vec)
{
    float sum{ 0.0f };
    for (auto& e : vec)
        sum += static_cast<float>(e);
    return sum / static_cast<float>(vec.size());
}

template<typename T>
float stdev(std::vector<T>& vec, float avg_v)
{
    float var{ 0.0f };
    for (auto& e : vec)
        var += std::powf(static_cast<float>(e) - avg_v, 2);
    return std::sqrtf(var / static_cast<float>(vec.size() - 1));
}

template<typename T>
float stdev(std::vector<T>& vec)
{
    float avg_v = avg(vec);
    return stdev(vec, avg_v);
}



int main()
{
        std::array<std::array<int, aSize>, aSize> freq;
        for(auto& freqCounter : freq )
            freqCounter.fill(0);

        // first unrandomized
        for (int i = 0; i < aSize; i++)
            for (auto& message : messages)
                compute(message, i, freq);

        std::vector<int> appeared_vec;
        // 0 difference does not appear, exclude
        for (int i = 1; i < aSize; i++)
        {
            // at difference sum apperances
            int difference_appeared{ 0 };
            for (int j = 1; j < aSize; j++)
                difference_appeared += freq[j][i];

            appeared_vec.push_back(difference_appeared);
        }
        float avg_v = avg(appeared_vec);
        float stdev_v = stdev(appeared_vec, avg_v);

        for (int i = 0; i < aSize - 1; i++)
            std::cout
            << "diff of: " << std::setw(2) << i + 1 << " deviates for "
            << std::setw(4) << (static_cast<float>(appeared_vec[i]) - avg_v) / stdev_v << std::endl;
        std::cout << std::endl;

        // clear
        for (auto& freqCounter : freq)
            freqCounter.fill(0);
        appeared_vec.clear();


        // randomized unshared
        std::vector<bool> shared_vec_v = get_shared_vec();
        for (int i = 0; i < 100000; i++)
        {
            inline_scramble_unshared(shared_vec_v);

            for (int i = 0; i < aSize; i++)
                for (auto& message : messages)
                    compute(message, i, freq);
        }

        appeared_vec;
        // 0 difference does not appear, exclude
        for (int i = 1; i < aSize; i++)
        {
            // at difference sum apperances
            int difference_appeared{ 0 };
            for (int j = 1; j < aSize; j++)
                difference_appeared += freq[j][i];

            appeared_vec.push_back(difference_appeared);
        }
        avg_v = avg(appeared_vec);
        stdev_v = stdev(appeared_vec, avg_v);

        for (int i = 0; i < aSize - 1; i++)
            std::cout 
            << "diff of: " << std::setw(2) << i +1 << " deviates for "
            << std::setw(4) << (static_cast<float>(appeared_vec[i]) - avg_v) / stdev_v << std::endl;


    return 0;
}

