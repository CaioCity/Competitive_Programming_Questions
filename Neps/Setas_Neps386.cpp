// https://neps.academy/br/exercise/386

#include <iostream>

short int N;

bool segue_caminho (short int, short int, char[][500], bool[][500], bool[][500]);

int main(){
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	int safes=0;
	std::cin>>N;
	
	char Tab[N][500]; //tabuleiro com os caracteres
	bool boolTab[N][500]; //diz se a casa já foi visitada
	bool gabTab[N][500]; //diz se a casa é segura ou perigosa
	
	for(short int i=0; i<N; i++)
		for(short int j=0; j<N; j++){
			std::cin>>Tab[i][j];
			boolTab[i][j]=0;
			gabTab[i][j]=1;
		}
	
	for(short int i=0; i<N; i++)
		for(short int j=0; j<N; j++)
			if(segue_caminho(i,j, Tab, boolTab, gabTab))
				safes++;
		
	std::cout<<safes<<std::endl;	
			
	return 0;			
}

bool segue_caminho (short int i, short int j, char Tab[][500] , bool boolTab[][500], bool gabTab[][500] ){
	
	//Se a casa ja estiver definida
	if(boolTab[i][j])
		return gabTab[i][j];
	
	boolTab[i][j]=1; // agr a casa sera definida. nas proximas vezes, ja terei passado por ela
	
	//definindo casas pela 1a vez

	switch(Tab[i][j]){
		case 'A':
			if(i==0) return gabTab[i][j]=0;
			else return gabTab[i][j]=segue_caminho(i-1, j,Tab, boolTab,gabTab);
		case '<':
			if(j==0) return gabTab[i][j]=0;	
			else return gabTab[i][j]=segue_caminho(i, j-1,Tab, boolTab,gabTab);
		case '>':
			if(j==(N-1)) return gabTab[i][j]=0;
			else return gabTab[i][j]=segue_caminho(i,j+1, Tab, boolTab,gabTab);	 
		case 'V':
			if(i==(N-1)) return gabTab[i][j]=0;
			else return gabTab[i][j]=segue_caminho(i+1, j,Tab, boolTab,gabTab);
	}
	
}
