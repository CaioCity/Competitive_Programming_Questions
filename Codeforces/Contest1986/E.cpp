// https://codeforces.com/contest/1986/problem/E
// Beautiful Array

#include <bits/stdc++.h>

int main() {

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int t;
    std::cin >> t;

    while (t--) {
        int n, k, ans = 0;
        std::cin >> n >> k;

        int array[n + 1];
        std::map<int, std::multiset<int>> modulo;

        for (int i = 1; i <= n; ++i) {
            std::cin >> array[i];
            modulo[array[i] % k].insert(array[i]);
        }

        int next = 0;
        for (auto [i, MS] : modulo)
            if (MS.size() & 1) {
                if (++next >= 2)
                    break;
            }
        if (next >= 2) {
            std::cout << "-1\n";
            continue;
        }

        for (auto [i, MS] : modulo) {
            std::multiset<int>::iterator a = MS.begin(), b = MS.begin(), c = MS.end(), d = MS.end();
            std::multiset<int>::iterator begin = MS.begin(), end = MS.end();
            ++b, --c; --c; --d;

            std::vector<int> numbers (MS.begin(),MS.end());
            int tam=MS.size();

            if( !(tam & 1) ){ // MS.size() par, vidinha de morango
                int aux=0;
                for(int i=1; i<tam; i+=2)
                    aux+=(numbers[i]-numbers[i-1]);
                ans+=(aux/k);
            }
            else {   //MS.size() impar, boa sorte 

                int sum_even[tam], sum_odd[tam];
                sum_even[0] = (-1) * numbers[0];
                sum_odd[0] = numbers[0];

                for(int i=1; i<tam; ++i){
                    if(i&1){
                        sum_even[i] = sum_even[i-1] + numbers[i];
                        sum_odd[i] = sum_odd[i - 1] - numbers[i];
                    } else{
                        sum_even[i] = sum_even[i-1] - numbers[i];
                        sum_odd[i] = sum_odd[i-1] + numbers[i];
                    }
                }

                int min_diff = INT32_MAX,aux;
                for(int index=1; index<(tam-1); ++index){
                    aux=std::abs(sum_odd[index-1] + sum_even[tam-1] - sum_even[index] );
                    if(min_diff>aux)
                        min_diff = aux;
                }

                int sum_with_begin = 0, sum_with_end = 0;
                if (MS.size() & 1) {
                    int cont = 0;
                    for (auto i : MS) {
                        if (cont & 1) {
                            sum_with_begin -= i;
                            sum_with_end += i;
                        }
                        else {
                            sum_with_begin += i;
                            sum_with_end -= i;
                        }
                        ++cont;
                    }
                    sum_with_end += (*a);
                    sum_with_begin -= (*d);
                }

                min_diff = std::abs(min_diff); sum_with_begin = std::abs(sum_with_begin); sum_with_end = std::abs(sum_with_end);

                min_diff = std::min( min_diff, std::min(sum_with_begin, sum_with_end));

                ans += (min_diff/k);
            } 
        }        

        std::cout << ans << '\n';
    }

    return 0;
}
