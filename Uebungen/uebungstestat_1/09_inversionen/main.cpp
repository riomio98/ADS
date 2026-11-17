
#include <iostream>
#include <vector>
using namespace std;

long long inversionen_rek(vector<int>& v, size_t lo, size_t hi)
{
    // 1. Abbruchbedingung
    if (lo >= hi)
    {
        return 0;
    }

    // 2. Teilen
    size_t mi = lo + (hi - lo) / 2;

    // 3. Rekursive Aufrufe
    long long links = inversionen_rek(v, lo, mi);
    long long rechts = inversionen_rek(v, mi + 1, hi);

    // 4. Zusammenführen
    long long zwischen = 0;

    size_t i = lo;
    size_t j = mi + 1;

    vector<int> temp;

    while (i <= mi && j <= hi)
    {
        if (v[i] <= v[j])
        {
            temp.push_back(v[i]);
            ++i;
        }
        else
        {
            temp.push_back(v[j]);

            zwischen += mi - i + 1;

            ++j;
        }
    }

    // Restliche Elemente links übernehmen
    while (i <= mi)
    {
        temp.push_back(v[i]);
        ++i;
    }

    // Restliche Elemente rechts übernehmen
    while (j <= hi)
    {
        temp.push_back(v[j]);
        ++j;
    }

    // Sortierten Bereich zurückschreiben
    for (size_t k = 0; k < temp.size(); ++k)
    {
        v[lo + k] = temp[k];
    }

    // 5. Ergebnisse zusammenfassen
    return links + rechts + zwischen;
}

long long inversionen(const vector<int>& v)
{
    if (v.empty())
    {
        return 0;
    }

    vector<int> kopie = v;

    return inversionen_rek(kopie, 0, kopie.size() - 1);
}

int main()
{
    vector<int> v = {2, 4, 1, 3, 5};

    cout << inversionen(v) << endl;

    return 0;
}
