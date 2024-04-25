// https://judge.beecrowd.com/en/problems/view/2632
// Magic and Sword

#include <iostream>
#include <cmath>
#include <string>

#define x1 coords[0].first
#define x2 coords[1].first
#define x3 coords[2].first
#define x4 coords[3].first
#define y1 coords[0].second
#define y2 coords[1].second
#define y3 coords[2].second
#define y4 coords[3].second

//                     cx ou cy  
#define dentro_do_lado(coordC,coord1,coord2) ((coordC>=coord1) && (coordC<=coord2))
#define	distance2(a,b,c,d) (((a-c)*(a-c))+((b-d)*(b-d)))

std::pair<unsigned short int, unsigned short int> coords[4];
unsigned short int R,damage;

void elemento ( std::string, int);

int main(){
	
	int T;
	std::cin>>T;
	
	while(T--){
		
		unsigned short int w,h;
		
		std::cin>>w>>h>>x1>>y1;
		x2=(x1+w), y2=y1;		//O Vértice 2 é o esquerdo inferior
		x3=x1, y3=(y1+h);		//O Vértice 3 é o esquerdo superior
		x4=(x1+w), y4=(y1+h);	//O Vértice 4 é o direito superior
		
	
		std::string S;
		unsigned short int	N,cx,cy;
		std::cin>>S>>N>>cx>>cy;
		
		bool dano=0;
		
		//Receber os dados da magia específica
		elemento(S,N);	
		
		//caso 1: ela dentro do retângulo
		
		if(cx<=x2 && cx>=x1 && cy>=y1 && cy<=y3)
			dano=1;	
				
		//fim do caso 1	
		
		if(dano){
			printf("%hu\n",damage);
			continue;
		}
		
		//ideia 2: observar a projeção da circ sobre os lados do retângulo
		
		if( dentro_do_lado( cx, x1, x2) ) {
			if( std::abs(cy-y1) <=R || std::abs(cy-y3) <=R ){
				dano=1;
				
			}
		}
		if( dentro_do_lado( cy, y1, y3) ){
			if( std::abs(cx-x1) <=R || std::abs(cx-x2) <=R ){
				dano=1;
			}
		}
		
		//fim da ideia 2	
		
		if(dano){
			printf("%hu\n",damage);
			continue;
		}
	
		//ideia 3: identificar de qual vertice a circ tá mais proxima e sua distância
		
		if ( (distance2(cx,cy,x1,y1) <= R*R) 
			|| (distance2(cx,cy,x2,y2) <= R*R) 
			|| (distance2(cx,cy,x3,y3) <= R*R) 
			|| (distance2(cx,cy,x4,y4) <= R*R) )
			dano=1;
		
		//fim da ideia 3
		
		
		
		if(dano){
			printf("%hu\n",damage);
		} else{
			printf("0\n");
		}
		
	}
	
	return 0;
}

//Converte o tipo de magia e seu nível em suas informações específicas
void elemento (std::string S, int N){
	
	if (S=="fire"){
		int level[3]={20,30,50};
		damage=200;
		R = level[N-1];
	} else if(S=="water"){
		int level[3]={10,25,40};
		damage=300;
		R = level[N-1];
	} else if(S=="earth"){
		int level[3]={25,55,70};
		damage=400;
		R = level[N-1];
	} else{
		int level[3]={18,38,60};
		damage=100;
		R = level[N-1];
	}
	
}
