// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
// Minimum Number of Days to Make m Bouquets

class Solution {
public:
    int buque(int dia, vector<int>& bloomday, int k) {
        int n = bloomday.size(), count = 0, conj = 0;
        for (int i = 0; i < n; i++) {
            if (bloomday[i] > dia)
                count = 0;
            else {
                count++;
                if (count == k) {
                    conj++;
                    count = 0;
                }
            }
        }
        return conj;
    }

    int bs(int inicio, int fim, vector<int>& bloomday, int m, int k) {
        if (fim - inicio <= 1) {
            int aux = buque(inicio, bloomday, k);
            if(inicio==fim){
                if(aux>=m)
                    return inicio;
                else return -1;
            }
            if (aux < m && m <= buque(fim, bloomday, k))
                return fim;
            else if (aux >= m)
                return inicio;
            else
                return -1;
        }

        int meio = (fim + inicio) / 2;

        int aux=buque(meio, bloomday, k);

        if (aux == m)
            return bs(inicio, meio, bloomday, m, k);
        if (aux > m)
            return bs(inicio, meio - 1, bloomday, m, k);
        if (aux < m)
            return bs(meio + 1, fim, bloomday, m, k);

        return 0;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(), maior = 0;
        if ((long long)m * k > n)
            return -1;
        for (int i = 0; i < n; i++)
            maior = max(maior, bloomDay[i]);

        return bs(0, maior, bloomDay, m, k);
    }
};
