#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// conta a quantidade de soluções
int maior_pontuacao = 0;

vector<bool> linhas(8);

// verifica se é seguro colocar a rainha numa determinada linha
// isso poderia ser feito com menos código, mas assim ficou mais didático
bool seguro(vector<vector<int> > & tab, int N, int lin, int col, vector<vector<int>> rainhas_pos){
	if(linhas[lin] == true)
		return false;
	
	for(int i = 0; i < col; i++){
		if(abs(rainhas_pos[i][0] - col) == abs(rainhas_pos[i][1] - lin))
			return false;
	}
	return true;
}

/*
	função que resolve o problema
	retorna true se conseguiu resolver e false caso contrário
*/
void executar(vector<vector<int> > & tab, int N, int col, vector<vector<int> > rainhas_pos){
	
	if(col == N){
		int soma = 0;
		for(int i = 0; i < N; i++){
			int c = rainhas_pos[i][0];	
			int l = rainhas_pos[i][1];
			soma += tab[l][c];
		}

		if (soma > maior_pontuacao)
			maior_pontuacao = soma;

		return;
	}

	for(int i = 0; i < N; i++){
		// verifica se é seguro colocar a rainha naquela coluna
		if(seguro(tab, N, i, col, rainhas_pos)){
			rainhas_pos[col][0] = col; 
			rainhas_pos[col][1] = i; 

			linhas[i] = true;
			// chamada recursiva
			executar(tab, N, col + 1, rainhas_pos);
			// remove a rainha (backtracking)
			linhas[i] = false;
		}
	}
}

int main(){

	int n_tabuleiros = 0;
	cin >> n_tabuleiros;

	// número de rainhas
	int N = 8;
	
	for(int i = 0; i < n_tabuleiros; i++){

		for(int j = 0; j < N; j++)
			linhas[j] = false;

		// tabuleiro (matriz)
		vector<vector<int>> tab(8);

		// inserindo todas as linhas
		for(int j = 0; j < N; j++){
			tab[j] = vector<int> (8);
			for(int k = 0; k < N; k++){
				cin >> tab[j][k];
			}
		}

		// armazena a posição das rainhas
		vector<vector<int>> rainhas_pos(8);
		for(int j = 0; j < N; j++)
			rainhas_pos[j] = vector<int> (8);

		executar(tab, N, 0, rainhas_pos);

		// imprime a maior pontuacao naquele tabuleiro
		cout << std::right << std::setw(5) << maior_pontuacao << endl;
		maior_pontuacao = 0;
	}	

	return 0;
}