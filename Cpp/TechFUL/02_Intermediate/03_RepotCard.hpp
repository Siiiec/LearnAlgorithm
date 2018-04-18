#include <iostream>
#include <string>
#include <vector>
#include <valarray>
#include <iomanip>
#include <algorithm>
#include <numeric>

using ar = std::valarray<int>;

struct Seiseki
{
    std::string name;
    int japanese;
    int math;
    int english;
};

std::istream& operator>>(std::istream& is, Seiseki& s)
{
    is >> s.name >> s.japanese >> s.math >> s.english;
    return is;
}

void SeisekiPrint(const Seiseki& s)
{
    using namespace std;
    cout << s.name << "‚³‚ñ‚Ì¬ÑF" << 
        setw(6) << s.japanese <<
        setw(7) << s.math << setw(7) << 
        s.english << endl;
}

void Print(const ar& a, std::string prefix = "")
{
    using namespace std;
    cout << prefix << setw(6) << a[0] <<
        setw(7) << a[1] << setw(7) <<
        a[2] << endl;
}


void solve()
{
    using namespace std;
    int n;
    cin >> n;

    vector<Seiseki> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    //cout << "‘Œê   ”Šw   ‰pŒê" << endl;

    auto sum = accumulate(v.cbegin(), v.cend(), ar(3),
        [](ar init, const Seiseki& s)
    {
        SeisekiPrint(s);
        return init + ar {s.japanese, s.math, s.english};
    });

    Print(sum);
    Print(sum / n);
}