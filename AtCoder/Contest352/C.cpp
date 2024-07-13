// https://atcoder.jp/contests/abc352/tasks/abc352_c
// Standing On The Shoulders

#include <bits/stdc++.h>

struct giant{
	unsigned int ombro;
	unsigned int head;
	int diff;
};

bool compareInterval(struct giant g1, struct giant g2){
    return (g1.diff < g2.diff);
}

int main(){

	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	int N;
	std::cin>>N;
	struct giant G[N];
	struct giant* Pointers[N];
	
	for(int i=0; i<N; i++){
		std::cin>>G[i].ombro>>G[i].head;
		G[i].diff=G[i].head-G[i].ombro;
		Pointers[i]=(G+i);
	}
	
	//sorting(N,G,Pointers);
	std::sort(G, G+N,compareInterval);
	
	long long int altura=0;
	for(int i=0; i<(N-1); i++){
		altura+= G[i].ombro;
	}
		
	
	altura+=G[N-1].head;
	std::cout<<altura<<std::endl;
	
	return 0;
}
